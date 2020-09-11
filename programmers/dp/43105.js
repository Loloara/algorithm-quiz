function solution(triangle) {
  let answer = 0;
  let mem = [];

  for (let i in triangle) mem.push(new Array(parseInt(i) + 1).fill(-1));
  mem[0][0] = triangle[0][0];

  for (let i = 0; i < triangle.length - 1; i++) {
    for (let j = 0; j < triangle[i].length; j++) {
      for (let k = 0; k < 2; k++) {
        let tmp = mem[i][j] + triangle[i + 1][j + k];
        if (mem[i + 1][j + k] < tmp) mem[i + 1][j + k] = tmp;
      }
    }
  }

  for (let val of mem[mem.length - 1]) {
    if (val > answer) answer = val;
  }

  return answer;
}

console.log(solution([[7], [3, 8], [8, 1, 0], [2, 7, 4, 4], [4, 5, 2, 6, 5]]));
