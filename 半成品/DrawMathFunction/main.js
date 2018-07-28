//variable + result
var f = function(x) {return Math.sin(x) * x / Math.tan(x);};

const precision = 0.1;
const range = 300;        // abs(x) < range
const factor = 20;        // scale

//_________________________implement____________________________
// ready
var canvas = document.getElementById('figure');
var context = canvas.getContext('2d');
context.strokeStyle = "black";
// Create gradient
var gradient = context.createLinearGradient(0, 0, canvas.width, 0);
gradient.addColorStop("0.00", "pink");
gradient.addColorStop("0.10", "magenta");
gradient.addColorStop("0.25", "blue");
gradient.addColorStop("0.40", "green");
gradient.addColorStop("0.55", "yellow");
gradient.addColorStop("0.70", "red");
gradient.addColorStop("0.85", "orange");
gradient.addColorStop("1.00", "saddlebrown");
// Fill with gradient
context.fillStyle=gradient;

// plan
context.beginPath();
const axis_y0 = canvas.height/2;
var x = null;
context.moveTo(0, axis_y0);
for (var i = -range; i <= range; i += precision) {
    // fix: translate and scale
    x = i*factor + canvas.width/2 - 100;
    var y = (axis_y0 - f(i)*factor);

    context.lineTo(x, y);
};
context.lineTo(x, axis_y0);
context.lineTo(0, axis_y0);
context.closePath();

// draw
context.stroke();
context.fill();

// axis
context.strokeStyle = "blue";
context.lineWidth = 2;
context.beginPath();    // y-axis
context.moveTo(canvas.width/2 - 100, canvas.height);
context.lineTo(canvas.width/2 - 100, 0);
context.lineTo(canvas.width/2 - 90, 20);
context.lineTo(canvas.width/2 - 100, 0);
context.lineTo(canvas.width/2 - 110, 20);
context.lineTo(canvas.width/2 - 100, 0);
context.closePath();
context.stroke();

context.beginPath();    // x-axis
context.moveTo(0, axis_y0);
context.lineTo(canvas.width, axis_y0);
context.lineTo(canvas.width-20, axis_y0+10);
context.lineTo(canvas.width, axis_y0);
context.lineTo(canvas.width-20, axis_y0-10);
context.lineTo(canvas.width, axis_y0);
context.closePath();
context.stroke();

// decorate
context.fillStyle = "black";
context.font = "20px Verdana";
context.fillText(" y ", canvas.width/2 - 90, 25);
context.fillText(" x ", canvas.width - 25, axis_y0 -20);
context.font = "12px Verdana";
context.fillText(f.toString(), canvas.width/11*7, 20);