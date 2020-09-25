const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];
let maxVal = 0;
let testCase = -1;
rl.on("line", function (line) {
  line = parseInt(line);
  if (testCase === -1) {
    testCase = line;
  } else {
    if (line > maxVal) maxVal = line;
    input.push(line);
    testCase--;
    if (!testCase) rl.close();
  }
}).on("close", function () {
  const fb = new Array(maxVal + 1);
  fb[0] = [1, 0];
  fb[1] = [0, 1];
  for (let i = 2; i <= maxVal; i++) {
    fb[i] = [fb[i - 1][0] + fb[i - 2][0], fb[i - 1][1] + fb[i - 2][1]];
  }

  for (index of input) console.log(fb[index][0], fb[index][1]);

  process.exit();
});
