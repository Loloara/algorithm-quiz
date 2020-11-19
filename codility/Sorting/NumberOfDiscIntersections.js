function solution(A) {
  const MAX_VALUE = 10000000;
  let ans = 0;
  const disc = A.map((v, i) => [i - v, i + v]);
  disc.sort((a, b) => a[0] - b[0]);

  for (let i = 0; i < disc.length; i++) {
    for (let j = i + 1; j < disc.length; j++) {
      if (disc[i][1] >= disc[j][0]) ans++;
      else break;
      if (ans > MAX_VALUE) return -1;
    }
  }

  return ans;
}

console.log(solution([1, 5, 2, 1, 4, 0])); //11
