function solution(X, A) {
  let index = -1;
  let count = 0;
  const visited = new Array(X + 1).fill(false);
  while (index < A.length && count < X) {
    index++;
    if (A[index] > X) continue;
    if (visited[A[index]]) continue;
    visited[A[index]] = true;
    count++;
  }
  return index < A.length ? index : -1;
}

console.log(solution(5, [1, 3, 1, 4, 2, 3, 5, 4])); //6
