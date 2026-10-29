// Temporary private-VM transfer endpoint. Only prepared reference files are
// served; capture uploads stay in the task's evidence directory.
import http from 'node:http';
import {readFile,writeFile,mkdir} from 'node:fs/promises';
import {resolve,basename} from 'node:path';
const root=resolve('build/windows-reference');
const captures=resolve('evidence/windows-runtime');
await mkdir(captures,{recursive:true});
const server=http.createServer(async(req,res)=>{
  const peer=req.socket.remoteAddress;
  if(!['192.168.177.128','192.168.177.1'].includes(peer)){res.writeHead(403);res.end();return;}
  const path=decodeURIComponent(new URL(req.url,'http://local').pathname).slice(1);
  if(path!==basename(path)||!path.match(/^[a-zA-Z0-9._-]+$/)){res.writeHead(400);res.end();return;}
  try {
    if(req.method==='GET'||req.method==='HEAD'){
      const data=await readFile(resolve(root,path));
      res.writeHead(200,{'Content-Type':'application/octet-stream','Content-Length':data.length});
      res.end(req.method==='HEAD'?undefined:data);
      console.log(`${req.method} ${path} ${data.length}`);
    }else if(req.method==='POST'&&path.endsWith('.json')){
      const chunks=[];let size=0;
      for await(const chunk of req){size+=chunk.length;if(size>10*1024*1024)throw Error('capture too large');chunks.push(chunk);}
      const data=Buffer.concat(chunks);JSON.parse(data.toString('utf8').replace(/^\uFEFF/,''));
      await writeFile(resolve(captures,path),data);res.writeHead(201);res.end('saved');
      console.log(`Captured ${path} ${data.length}`);
    }else{res.writeHead(405);res.end();}
  }catch(e){console.log(String(e));res.writeHead(500);res.end('transfer failed');}
});
server.on('clientError',e=>console.log(`client error ${e}`));
server.listen(8765,'192.168.177.1',()=>console.log('Private VM reference transfer ready'));
