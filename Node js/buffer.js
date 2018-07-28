// 创建一个长度为 10、且用 0 填充的 Buffer。
const buf1 = Buffer.alloc(10);
console.log(buf1);

// 创建一个长度为 10、且用 0x1 填充的 Buffer。 
const buf2 = Buffer.alloc(10, 1);
console.log(buf2);

// 创建一个长度为 10、且未初始化的 Buffer。
// 这个方法比调用 Buffer.alloc() 更快，
// 但返回的 Buffer 实例可能包含旧数据，
// 因此需要使用 fill() 或 write() 重写。
const buf3 = Buffer.allocUnsafe(10);
console.log(buf3);

// 创建一个包含 [0x1, 0x2, 0x3] 的 Buffer。
const buf4 = Buffer.from([1, 2, 3]);
console.log(buf4[2]);

// 创建一个包含 UTF-8 字节 [0x74, 0xc3, 0xa9, 0x73, 0x74] 的 Buffer。
const buf5 = Buffer.from('tést');
for (const b of buf5) {
  console.log('-'+b);
}

// 创建一个包含 Latin-1 字节 [0x74, 0xe9, 0x73, 0x74] 的 Buffer。
const buf6 = Buffer.from('tést', 'latin1');
console.log(buf6[0]);

console.log(buf5.toString('hex'));
console.log(buf6.toString('base64'));
//------------------------------------
const arr = new Uint16Array(2);

arr[0] = 5000;
arr[1] = 4000;

// 拷贝 `arr` 的内容
const buf7 = Buffer.from(arr);
// 与 `arr` 共享内存
const buf8 = Buffer.from(arr.buffer);

// 输出: <Buffer 88 a0>
console.log(buf7);
// 输出: <Buffer 88 13 a0 0f>
console.log(buf8);

arr[1] = 6000;
// 输出: <Buffer 88 a0>
console.log(buf7);
// 输出: <Buffer 88 13 70 17>
console.log(buf8);

// slice返回一个指向相同原始内存的新建的 Buffer，但做了偏移且通过 start 和 end 索引进行裁剪。
// 注意，修改这个新建的 Buffer 切片，也会同时修改原始的 Buffer 的内存，因为这两个对象所分配的内存是重叠的。

// 转码
const newBuf = buffer.transcode(Buffer.from('€'), 'utf8', 'ascii');
const buffer = require('buffer');