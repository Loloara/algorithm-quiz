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
  const addString = (a, b) => {
    if (a.length < b.length) {
      let tmp = a;
      a = b;
      b = tmp;
    }

    let result = [];
    let next = 0;
    let j = a.length - 1;
    for (let i = b.length - 1; i >= 0; i--, j--) {
      let sum = parseInt(a[j]) + parseInt(b[i]) + next;
      result.unshift(sum % 10);
      next = Math.floor(sum / 10);
    }

    while (next) {
      let sum = next;
      if (j >= 0) sum += parseInt(a[j--]);
      result.unshift(sum % 10);
      next = Math.floor(sum / 10);
    }

    return a.substr(0, j + 1).concat(result.join(""));
  };

  const fb = new Array(maxVal + 1).fill(0);
  fb[0] = "1";
  fb[1] = "1";
  fb[2] = "2";
  fb[3] = "4";
  for (let i = 4; i <= maxVal; i++) {
    fb[i] = addString(
      addString(addString(fb[i - 1], fb[i - 2]), fb[i - 3]),
      fb[i - 4]
    );
  }

  for (index of input) console.log(fb[index]);

  process.exit();
});
