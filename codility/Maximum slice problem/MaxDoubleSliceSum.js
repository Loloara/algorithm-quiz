function solution(A) {
  const left = new Array(A.length).fill(0);
  const right = new Array(A.length).fill(0);

  for (let i = 1; i < A.length - 2; i++) {
    left[i] = Math.max(0, left[i - 1] + A[i]);
  }
  for (let i = A.length - 2; i > 1; i--) {
    right[i] = Math.max(0, right[i + 1] + A[i]);
  }

  let maxVal = 0;
  for (let i = 0; i < A.length - 2; i++) {
    maxVal = Math.max(maxVal, left[i] + right[i + 2]);
  }

  return maxVal;
}

console.log(solution([3, 2, 6, -1, 4, 5, -1, 2])); // 17
console.log(solution([6, 1, 5, 6, 4, 2, 9, 4])); // 26
