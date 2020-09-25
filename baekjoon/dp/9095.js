const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];
let testCase = -1;
let maxVal = -1;
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
  const dp = new Array(maxVal + 1);
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;

  for (let i = 4; i <= maxVal; i++) {
    dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
  }

  for (index of input) console.log(dp[index]);

  process.exit();
});
