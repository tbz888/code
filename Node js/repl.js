// Read-Eval-Print-Loop
const repl = require('repl');

// 上下文
const msg = 'message';
const r = repl.start({ prompt: '> ' });
r.context.var1 = msg;

const net = require('net');
let connections = 0;
// 创建多实例
repl.start({
  prompt: 'Node.js 使用 stdin> ',
  input: process.stdin,
  output: process.stdout
});

net.createServer((socket) => {
  connections += 1;
  repl.start({
    prompt: 'Node.js 使用 TCP socket> ',
    input: socket,
    output: socket
  }).on('exit', () => {
    socket.end();
  });
}).listen(5001);

// .clear对应reset事件
r.on('reset', (context) => {context.m = 'reset';});

// 增加命令
r.defineCommand('hi', {
  help: '打招呼',
  action(name) {
    // this.lineParser.reset();
    this.bufferedCommand = '';
    console.log(`你好,${name}！`);
    this.displayPrompt();
  }
});
r.defineCommand('bye', function saybye() {
  console.log('再见！');
  this.close();
});