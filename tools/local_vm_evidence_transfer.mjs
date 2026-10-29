// Bounded own-file transfer on the inspected private VMware interface only.
import http from 'node:http';
import fs from 'node:fs';
import path from 'node:path';
import crypto from 'node:crypto';
const [name, expected] = process.argv.slice(2);
if (!['vcl-pen-results.zip', 'gas-operand-results.zip'].includes(name) || !/^[0-9a-f]{64}$/.test(expected ?? '')) throw Error('Pinned archive name and SHA256 required');
const token = crypto.randomBytes(16).toString('hex');
const directory = path.resolve('build/windows-reference');
const server = http.createServer((req, res) => {
  const reply = (status, text) => { res.writeHead(status, { 'Connection': 'close' }); res.end(text); };
  if (req.method === 'GET' && req.url === `/${token}/gas-operand-probes.zip`) {
    const bytes = fs.readFileSync(path.join(directory, 'gas-operand-probes.zip'));
    res.writeHead(200, { 'Content-Type': 'application/zip', 'Content-Length': bytes.length, 'Connection': 'close' });
    res.end(bytes); console.log('Served reviewed gas probe archive'); return;
  }
  if (req.method !== 'POST' || req.url !== `/${token}/${name}`) { reply(404, 'Unknown transfer'); return; }
  const length = Number(req.headers['content-length']);
  if (req.headers['transfer-encoding'] || !Number.isSafeInteger(length) || length <= 0 || length > 10000000) { reply(400, 'Invalid bounded body'); return; }
  const chunks = []; let total = 0;
  req.setTimeout(20000, () => req.destroy());
  req.on('data', chunk => { total += chunk.length; if (total > length) req.destroy(); else chunks.push(chunk); });
  req.on('end', () => {
    const bytes = Buffer.concat(chunks);
    if (total !== length || crypto.createHash('sha256').update(bytes).digest('hex') !== expected) { reply(422, 'Evidence digest differs; no file written'); return; }
    const output = path.join(directory, name);
    if (fs.existsSync(output)) {
      if (!fs.readFileSync(output).equals(bytes)) { reply(409, 'Preserve existing evidence'); return; }
    } else fs.writeFileSync(output, bytes, { flag: 'wx' });
    reply(200, 'OK'); console.log(`Received exact evidence ${name} ${expected}`);
  });
});
server.requestTimeout = 25000;
server.listen(17719, '172.16.23.1', () => console.log(`Private VM transfer token: ${token}`));
setTimeout(() => server.close(), 900000);
process.on('SIGINT', () => server.close(() => process.exit(0)));
