const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on("line", function (line) {
  input.push(
    line.split(" ").reduce((prev, cur) => {
      prev.push(parseInt(cur));
      return prev;
    }, [])
  );
}).on("close", function () {
  const people = input[0][0];
  const tree = input.reduce(
    (prev, cur, idx) => {
      if (idx === 0) return prev;
      prev[cur[0]].push(cur[1]);
      prev[cur[1]].push(cur[0]);

      return prev;
    },
    Array.from(Array(people + 1), () => [])
  );
  const mem = Array.from(new Array(people + 1), () => new Array(2));
  const visited = new Array(people + 1).fill(false);

  const dp = (index) => {
    visited[index] = true;
    mem[index][0] = 0;
    mem[index][1] = 1;

    for (let node of tree[index]) {
      if (visited[node]) continue;
      dp(node);
      mem[index][0] += mem[node][1];
      mem[index][1] +=
        mem[node][0] < mem[node][1] ? mem[node][0] : mem[node][1];
    }
  };

  dp(1);
  console.log(mem[1][0] > mem[1][1] ? mem[1][1] : mem[1][0]);

  process.exit();
});
