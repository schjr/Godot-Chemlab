# Exact source pixel-loop ports

Production frames may set `context.production_pixel_loop=true` to execute two
source loop bodies directly rather than dispatching hundreds of retained x86
instructions for every bitmap pixel. The default reference path remains the
instruction interpreter.

`OriginalParticlePixelLoops.solid` ports `49C996..49CD2A` in `49C620`. The
particle Ellipse/Rectangle prefix, final pixel and Draw/previous-background
suffix remain original IR. The direct loop reads the actual source scanline
pointer tables and their known DWORDs, computes the same eight-neighbor byte
averages, applies `49BA04`'s embedded float32 weights, preserves the high byte and
implements the original current/previous background channel comparisons.
Those float32-weight ×8-bit products and their aligned sum need at most37
significand bits, so binary64 represents the exact same finite values before
the source truncation. No tolerance or replacement blend rule is used.

`fade` ports `49CE08..49CF18` in `49CDD8`. The original IR computes/stores the
QWORD inverse factor first. The direct path reads that stored factor, the input
factor and source `49CF58` half constant, then constructs 256-entry channel
lookups with the existing x87 pair operations in the exact source operation
order. It preserves both half additions, truncation, upper255 clamp, background
channel order and the original high byte. Arbitrary QWORD products are not
assumed exact in binary64. The accelerated factor/inverse magnitudes are bounded
at1000000, keeping every source conversion within signed32-bit range; larger
values retain reference IR. Negative channels retain the original low-byte wrap
without a new lower clamp.

Both direct paths process all but the final pixel and then resume its first
original MOV. That final pixel and loop exits preserve CPU registers, flags,
floating-stack state and loop counters. The solid path also preserves the
source global scratch words and the last nested49BA04 call's stack bytes when
the final pixel takes the background branch. Unknown or aliased row backing
falls through to the original instruction path without inventing pixels or
changing the source error location. The source loops retain their different
row bounds: solid includes the last row with the original bottom-neighbor
substitution; fade excludes it.

`test_original_particle_pixel_loops.gd` compares22 cases against retained IR,
checking every defined VM byte (including stack and globals), register, flag
and x87 state. Cases cover running/stopped mixing, changing/equal backgrounds,
dimensions, arbitrary QWORD fade fractions, negative channels, upper clamping,
aliased rows, missing rows, sparse unknown stacks and out-of-range factors.
The complete66-frame/60-tick native chemistry and particle
corpus also passes with `--production-pixel-loop`.
