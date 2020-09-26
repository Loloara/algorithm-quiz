const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const solution = (weights, input) => {
  const tree = input.reduce((prev, cur) => {
    if (prev.has(cur[0])) {
      prev.get(cur[0]).push(cur[1]);
    } else {
      prev.set(cur[0], [cur[1]]);
    }

    return prev;
  }, new Map());

  const dp = Array.from(new Array(weights.length + 1), () =>
    new Array(2).fill(0)
  );

  const max = (a, b) => (a > b ? a : b);
  const dfs = (idx) => {
    if (!tree.has(idx)) {
      dp[idx][0] = weights[idx - 1];
      dp[idx][1] = 0;
      return;
    }

    for (let child of tree.get(idx)) {
      dfs(child);
      dp[idx][0] += dp[child][1];
      dp[idx][1] += max(dp[child][0], dp[child][1]);
    }
    dp[idx][0] += weights[idx - 1];
  };

  const arr = [];
  const findArr = (idx, available) => {
    if (dp[idx][0] > dp[idx][1] && available) {
      arr.push(idx);
      available = false;
    } else {
      available = true;
    }
    if (!tree.has(idx)) return;
    for (let child of tree.get(idx)) {
      findArr(child, available);
    }
  };

  dfs(1);
  findArr(1, true);

  const max_size = max(dp[1][0], dp[1][1]);
  return [max_size, arr.sort()];
};

const input = [];
let weights = [];

let testcase = -1;

rl.on("line", function (line) {
  if (testcase === -1) {
    testcase = parseInt(line);
  } else if (testcase !== 0) {
    testcase = 0;
    weights = line.split(" ").map((v) => parseInt(v));
  } else {
    input.push(
      line
        .split(" ")
        .map((v) => parseInt(v))
        .sort()
    );
  }
}).on("close", function () {
  const [max_size, arr] = solution(weights, input);
  console.log(max_size);
  if (arr.length) console.log(arr.join(" "));

  process.exit();
});
