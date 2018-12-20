const url = require('url');//url.parse()
const {URL, URLSearchParams} = require('url');//WHATWG	对象的解构赋值,提取json有奇效

const old_url = url.parse('https://user:pass@sub.host.com:8080/p/a/t/h?query=string#hash');
const whatwg_url = new URL('https://user:pass@sub.host.com:8080/p/a/t/h?query=string#hash');

console.log(old_url.href);
console.log(old_url.host);
console.log(old_url.search);
console.log(old_url.hash);

// official demo------------------
const myURL = new URL('https://example.org/?abc=123');
console.log(myURL.searchParams.get('abc'));
// 输出 123

myURL.searchParams.append('abc', 'xyz');
console.log(myURL.href);
// 输出 https://example.org/?abc=123&abc=xyz

myURL.searchParams.delete('abc');
myURL.searchParams.set('a', 'b');
console.log(myURL.href);
// 输出 https://example.org/?a=b

const newSearchParams = new URLSearchParams(myURL.searchParams);
// 上面的代码等同于
newSearchParams.append('a', 'c');
console.log(myURL.href);
// 输出 https://example.org/?a=b
console.log(newSearchParams.toString());
// 输出 a=b&a=c

// newSearchParams.toString() 被隐式调用
myURL.search = newSearchParams;
console.log(myURL.href);
// 输出 https://example.org/?a=b&a=c
newSearchParams.delete('a');
console.log(myURL.href);
// 输出 https://example.org/?a=b&a=c

// 格式化
console.log(url.format(myURL, { fragment: true, unicode: true, auth: false, search: false }));