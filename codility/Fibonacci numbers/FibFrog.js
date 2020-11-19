function solution(A) {
  const F = [0, 1];
  let i = 1;
  while (F[i++] < A.length + 1) {
    F.push(F[i - 1] + F[i - 2]);
  }

  const reachable = new Array(A.length + 2).fill(Infinity);
  reachable[0] = 0;
  for (let i = 1; i < reachable.length; i++) {
    if (i > A.length || A[i - 1] === 1) {
      for (let j = 0; F[j] <= i; j++) {
        if (reachable[i] > reachable[i - F[j]] + 1) {
          reachable[i] = reachable[i - F[j]] + 1;
        }
      }
    }
  }

  return reachable[reachable.length - 1] === Infinity
    ? -1
    : reachable[reachable.length - 1];
}

console.log(solution([0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0])); // 3
