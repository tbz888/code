const http = require('http');
const zlib = require('zlib');
const fs = require('fs');

const server = http.createServer((req, res) => {
  // req 是 http.IncomingMessage 的实例，这是一个 Readable Stream
  // res 是 http.ServerResponse 的实例，这是一个 Writable Stream

  let body = '';
  // 接收数据为 utf8 字符串，
  // 如果没有设置字符编码，将接收到 Buffer 对象。
  req.setEncoding('utf8');

  // 如果监听了 'data' 事件，Readable streams 触发 'data' 事件 
  req.on('data', (chunk) => {
    body += chunk;
  });

  // end 事件表明整个 body 都接收完毕了 
  req.on('end', () => {
    try {
      const data = JSON.parse(body);
      // 发送一些信息给用户
      res.write(typeof data);
      console.log(typeof data);
      res.end();
    } catch (er) {
      // json 数据解析失败 
      res.statusCode = 400;
      return res.end(`error: ${er.message}`);
    }
  });
});

server.listen(1337);
// $ curl localhost:1337 -d "{}"
// object
// $ curl localhost:1337 -d "\"foo\""
// string
// $ curl localhost:1337 -d "not json"
// error: Unexpected token o in JSON at position 1

const file = fs.createWriteStream('example.txt');
file.write('hello, ');
file.end('world!');

// stream.cork();
// stream.write('some ');
// stream.cork();
// stream.write('data ');
// process.nextTick(() => {
//   stream.uncork();
//   // 之前的数据只有在 uncork() 被二次调用后才会输出
//   stream.uncork();
// });
const r = fs.createReadStream('example.txt');
const z = zlib.createGzip();
const w = fs.createWriteStream('example.txt.gz');
r.pipe(z).pipe(w);