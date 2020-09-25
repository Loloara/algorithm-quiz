const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];
let testCase = -1;
rl.on("line", function (line) {
  line = parseInt(line);
  if (testCase === -1) {
    testCase = line;
  } else {
    input.push(line);
    testCase--;
    if (!testCase) rl.close();
  }
}).on("close", function () {
  const MAX_STAIR = input.length;
  const dp = Array.from(new Array(MAX_STAIR), () => new Array(2).fill(0));
  dp[0][0] = input[0];
  if (MAX_STAIR > 1) {
    dp[1][1] = dp[0][0] + input[1];
    dp[1][0] = input[1];
  }

  for (let i = 2; i < MAX_STAIR; i++) {
    dp[i][0] = max([dp[i - 2][0], dp[i - 2][1]]) + input[i];
    dp[i][1] = dp[i - 1][0] + input[i];
  }

  console.log(max([dp[MAX_STAIR - 1][0], dp[MAX_STAIR - 1][1]]));

  process.exit();
});

function max(arr) {
  let maxVal = -1;
  for (let v of arr) {
    if (maxVal < v) maxVal = v;
  }
  return maxVal;
}
