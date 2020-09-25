const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

rl.on("line", function (weight) {
  weight = parseInt(weight);
  const dp = new Array(weight + 1).fill(-1);
  dp[3] = 1;
  dp[5] = 1;
  for (let i = 6; i <= weight; i++) {
    dp[i] =
      dp[i - 5] !== -1 ? dp[i - 5] + 1 : dp[i - 3] !== -1 ? dp[i - 3] + 1 : -1;
  }

  console.log(dp[weight]);
  rl.close();
}).on("close", function () {
  process.exit();
});
