# Owned Win32 critical sections: isolated boundary backend

This new Windows backend executes genuine InitializeCriticalSection,
EnterCriticalSection, LeaveCriticalSection and DeleteCriticalSection on memory
allocated **inside its own helper process**. Source pointer values are identity
strings only. No supplied pointer is cast to the address used for an OS call.
It never opens the original process, copies a captured lock into a new process,
or treats a captured owning-thread/semaphore value as usable locally.

## Original-code evidence

The retained original `_main.exe` SHA is
`7744d5c7c76d51418e00c67cda112c14a495c93b0386ee5a52f05e165702b71c`.
The following addresses are from its original instructions and the matching
`recovered/native/main/decompiled.cpp`:

| Source | Behavior |
| --- | --- |
| `4E2D44..4E2D7C`, call `4E2D5E` | Resource-manager constructor initializes the embedded lock at object `+8` through import `555008`. |
| `4E2D80..4E2DA1`, call `4E2D8F` | Resource-manager destructor deletes that embedded lock through `554EB2`. |
| `4E2DA4` / `4E2DB0` | Add eight to object pointer; pass to Enter import `554EC4` / Leave `555020`. |
| `4E34E8` / `4E34F8` | Read Pen/graphic object `+14`; if nonzero pass that pointer to Enter/Leave. No access to pointed-to structure fields. |
| `4E42A8` constructor | Initializes Canvas `+38`; writes that same pointer into Brush, Pen and Font `+14`. Aliases must share one lock. |
| `4E436C` destructor | Deletes Canvas `+38` after releasing its graphic objects. |
| `4E3DF8`, `4E2F50`, `4E2DBC`, `4E2EA0` | Acquire Canvas/Pen lock, acquire registry lock, then reacquire that **same registry lock** for lookup/release. The normal finally paths perform matching Leave calls. |

In this bounded VCL/registry scope, application code does not inspect the
CRITICAL_SECTION's internal fields. It reads the pointer, computes an embedded
address, and invokes the four imports. The helper therefore preserves locking
semantics using its own OS-initialized opaque structure, rather than copying
raw target lock bytes. This finding does not cover every other original thread
or every runtime lock use.

Microsoft documents that ownership belongs to an OS thread, repeated acquisition
by that same thread is recursive, and every entry requires one leave; critical
sections cannot be shared between processes. Waiter ordering is not guaranteed.
See [EnterCriticalSection](https://learn.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-entercriticalsection)
and [Critical Section Objects](https://learn.microsoft.com/en-us/windows/win32/sync/critical-section-objects).
Native failures/exceptions and deletion of owned locks are not recoverable by
inventing a successful operation.

## New files and protocol

`tools/windows/original_owned_critical_sections.cs` owns the OS objects and a
persistent dedicated Windows thread for each explicitly named source actor.
Callbacks separated by JSON round trips therefore retain real thread ownership.
A contending Enter actually blocks its worker. The protocol reader remains free
to dispatch the owning actor's Leave. `begin` returns only a ticket: it never
claims the primitive completed before `poll` reports a completed successful
result. Nothing silently maps missing actors or locks to defaults.

`tools/windows/original_owned_critical_sections.ps1` either runs the verifier or
serves newline-delimited JSON on stdin/stdout. Protocol name:
`chemlab-owned-win32-critical-sections-v1`.

| Operation | Required values | Meaning |
| --- | --- | --- |
| `create` | `scope`, `source_identity` (`0x` plus 8 hex digits, nonzero) | Execute Initialize on a new owned allocation. Return key and unique lifetime instance. |
| `begin` | `key`, `actor`, `api` (`EnterCriticalSection` / `LeaveCriticalSection`) | Queue on that actor's dedicated OS thread; return ticket. |
| `poll` | `ticket`, `wait_ms` (0..5000) | Return started/complete flags and completed result, if any. |
| `delete` | `key` | Execute Delete and free owned memory only when no owner, pending entry or queued operation exists. |

A shared source pointer in the same scope resolves to the same key. Duplicate
creation is rejected, including a previously deleted key; address reuse requires
an explicit new lifetime scope. This prevents old requests from rebinding to a
new object. There is no arbitrary alias operation merging distinct pointers.
A wrong-thread or unbalanced Leave is rejected before invoking undefined native
behavior. This is an explicit unsupported call, not an original successful
release. There is no automatic timeout release, ownership transfer, deadlock
repair, operation replay, captured-state import or exception unwinder.

## Verification and current limits

On Windows, run:

```
powershell.exe -NoProfile -File tools/windows/original_owned_critical_sections.ps1 -Verify -Output own-critical-verification.json
```

The verifier compares a direct fresh Win32 reference's recursive exclusion with
the backend: two recursive acquisitions, a second actual Windows worker blocked
in Enter, one Leave retaining exclusion, final Leave allowing the waiter to
acquire, and balanced release. It also rejects a wrong-thread Leave, deletion
while held/waiting, stale-lifetime rebinding, and checks stable worker-thread
identity. It never uses the original application's process or handles.

The verifier has been prepared but **has not yet been executed on Windows**.
This macOS workspace has no Windows API runtime or C# compiler; no passing native
result is asserted. The backend is not connected to OriginalPen, frames or
production profiles. A usable integration needs the Windows verification result,
a known reconstructed object-construction/lifetime sequence, explicit source
actor identity, and an asynchronous adapter which waits for actual completion.
The existing synchronous Pen callback cannot be given ticket acceptance as if
it were completed Enter success.

Captured critical sections may already be owned, have waiters, or be in a
process-specific lifetime. Creating a fresh helper object cannot attest those
states. Source exception/finally unwinding on exceptional exits, original thread
scheduling, CRT/OOM behavior and live startup state remain separate boundaries.
Only successful normal calls on explicitly reconstructed owned objects are in
this backend's proposed scope. Every protocol response retains
`native_vcl_verified:false`.

The original Enter/Leave imports are void calls. This backend does not claim
original volatile register/flag values, SEH frames or raw critical-section bytes
are reproduced by a JSON response. For the audited normal setter path, saved
object arguments survive in stack/nonvolatile registers and code resets EAX
before installing its next exception frame (`4E3E0A`, `4E2F69`); no lock-return
value drives those branches. Any broader interpreter adapter must check its own
call-site liveness rather than invent `eax_after` values. It must also keep the
helper's opaque lock storage distinct from historical bytes captured from the
original process; those bytes are not rewritten into a fictional local state.

The portable audit tool `tools/audit_original_critical_sections.py` verifies four
exact original wrapper instruction sequences and the constructor/destructor
import call targets directly from the pinned PE. Its output is
`evidence/original-critical-wrapper-audit.json`. This audit passes locally and is
separate from the still-pending Windows-native verifier.
