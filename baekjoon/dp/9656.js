const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

rl.on("line", function (line) {
  let n = parseInt(line);

  const dp = new Array(n + 1).fill(null);
  dp[1] = false;
  dp[2] = true;
  dp[3] = false;
  for (let i = 4; i <= n; i++) {
    if (dp[i - 3] || dp[i - 1]) dp[i] = false;
    else dp[i] = true;
  }

  console.log(dp[n] ? "SK" : "CY");

  rl.close();
}).on("close", function () {
  process.exit();
});
