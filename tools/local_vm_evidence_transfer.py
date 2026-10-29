"""One bounded evidence transfer on the Mac's private VMware bridge.

Only two named files are served/accepted. The upload must have an already
observed SHA256 and cannot overwrite different evidence. No directory browser,
arbitrary paths, authentication data, target-process operations or public bind.
"""
import argparse
import hashlib
import hmac
from http.server import BaseHTTPRequestHandler, HTTPServer
from pathlib import Path
import secrets
import time

ROOT = Path(__file__).resolve().parents[1]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--receive', required=True, choices=['vcl-pen-results.zip', 'gas-operand-results.zip'])
    parser.add_argument('--sha256', required=True)
    args = parser.parse_args()
    if len(args.sha256) != 64 or any(c not in '0123456789abcdef' for c in args.sha256):
        parser.error('A previously observed SHA256 is required')
    token = secrets.token_hex(16)
    incoming = ROOT / 'build/windows-reference' / args.receive
    outgoing = ROOT / 'build/windows-reference/gas-operand-probes.zip'

    class Handler(BaseHTTPRequestHandler):
        def log_message(self, *unused):
            pass

        def do_GET(self):
            if not hmac.compare_digest(self.path, '/' + token + '/gas-operand-probes.zip'):
                self.send_error(404)
                return
            raw = outgoing.read_bytes()
            self.send_response(200)
            self.send_header('Content-Type', 'application/zip')
            self.send_header('Content-Length', str(len(raw)))
            self.end_headers()
            self.wfile.write(raw)
            print('Served reviewed gas probe archive', flush=True)

        def do_POST(self):
            if not hmac.compare_digest(self.path, '/' + token + '/' + args.receive):
                self.send_error(404)
                return
            if self.headers.get('Transfer-Encoding') is not None:
                self.send_error(400)
                return
            try:
                length = int(self.headers['Content-Length'])
                if not 0 < length <= 10_000_000:
                    raise ValueError()
            except (TypeError, ValueError):
                self.send_error(400)
                return
            self.connection.settimeout(20)
            raw = self.rfile.read(length)
            if len(raw) != length or hashlib.sha256(raw).hexdigest() != args.sha256:
                self.send_error(422, 'Evidence digest differs; no file written')
                return
            if incoming.exists():
                if incoming.read_bytes() != raw:
                    self.send_error(409, 'Preserve existing evidence')
                    return
            else:
                with incoming.open('xb') as output:
                    output.write(raw)
            self.send_response(200)
            self.send_header('Content-Length', '2')
            self.end_headers()
            self.wfile.write(b'OK')
            print('Received exact evidence ' + args.receive + ' ' + args.sha256, flush=True)

    # bridge100 is the inspected Fusion NAT interface, not Wi-Fi/public IP.
    server = HTTPServer(('172.16.23.1', 17719), Handler)
    server.timeout = 10
    print('Private VM transfer token: ' + token, flush=True)
    expires = time.monotonic() + 900
    try:
        while time.monotonic() < expires:
            server.handle_request()
    finally:
        server.server_close()


if __name__ == '__main__':
    main()
