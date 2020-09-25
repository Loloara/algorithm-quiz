const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];
let testCase = -1;
rl.on("line", function (line) {
  line = line.split(" ").map((v) => parseInt(v));
  if (testCase === -1) {
    testCase = line;
  } else {
    input.push(line);
    testCase--;
    if (!testCase) rl.close();
  }
}).on("close", function () {
  const HOUSE = input.length;
  const dp = Array.from(new Array(HOUSE), () => new Array(3).fill(0));
  dp[0] = [...input[0]];
  for (let i = 1; i < HOUSE; i++) {
    dp[i][0] = min([dp[i - 1][1], dp[i - 1][2]]) + input[i][0];
    dp[i][1] = min([dp[i - 1][0], dp[i - 1][2]]) + input[i][1];
    dp[i][2] = min([dp[i - 1][0], dp[i - 1][1]]) + input[i][2];
  }

  console.log(min(dp[HOUSE - 1]));

  process.exit();
});

function min(arr) {
  let minVal = arr[0];
  for (let val of arr) {
    if (minVal > val) minVal = val;
  }

  return minVal;
}
