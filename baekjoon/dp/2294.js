const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];
let testCase = -1;
let target = -1;
rl.on("line", function (line) {
  if (testCase === -1) {
    [testCase, target] = line.split(" ").map((v) => parseInt(v));
  } else {
    input.push(parseInt(line));
    testCase--;
    if (!testCase) rl.close();
  }
}).on("close", function () {
  const coins = input
    .sort((a, b) => b - a)
    .filter((val, idx) => val !== input[idx - 1]);
  const dp = new Array(target + 1).fill(-1);

  dp[0] = 0;
  for (let i = 1; i <= target; i++) {
    const sus = [];
    for (let coin of coins) {
      if (i < coin) continue;
      if (dp[i - coin] !== -1) {
        sus.push(dp[i - coin] + 1);
      }
    }
    if (sus.length) dp[i] = min(sus);
  }

  console.log(dp[target]);

  process.exit();
});

function min(arr) {
  let minVal = arr[0];
  for (let val of arr) {
    if (minVal > val) minVal = val;
  }
  return minVal;
}
