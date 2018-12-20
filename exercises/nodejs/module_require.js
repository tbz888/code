const circle = require('./module_export.js');
console.log(`半径为 4 的圆的面积是 ${circle.area(4)}`);
console.log(module);

const square = require('./module_export2.js');
const t = new square(3);
console.log(t.area());
console.log(module);

