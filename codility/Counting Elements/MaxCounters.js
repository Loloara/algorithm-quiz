function solution(N, A) {
  const arr = new Array(N).fill(0);
  let maxVal = 0;
  let curMax = 0;
  for (let i = 0; i < A.length; i++) {
    if (A[i] === N + 1) {
      maxVal = curMax;
    } else {
      const index = A[i] - 1;
      if (arr[index] < maxVal) {
        arr[index] = maxVal + 1;
      } else {
        arr[index]++;
      }

      if (curMax < arr[index]) {
        curMax = arr[index];
      }
    }
  }

  for (let i = 0; i < N; i++) {
    if (arr[i] < maxVal) {
      arr[i] = maxVal;
    }
  }

  return arr;
}

console.log(solution(5, [3, 4, 4, 6, 1, 4, 4])); //[3, 2, 2, 4, 2]
