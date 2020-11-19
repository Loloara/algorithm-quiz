function solution(A) {
  const left = new Map();
  const right = new Map();
  let count = 0;

  for (let i = 0; i < A.length; i++) {
    let val = 1;
    if (right.has(A[i])) {
      val += right.get(A[i]);
    }
    right.set(A[i], val);
  }

  let lMax = A[0];
  for (let i = 0; i < A.length - 1; i++) {
    let val = 1;
    if (left.has(A[i])) {
      val += left.get(A[i]);
    }
    left.set(A[i], val);
    right.set(A[i], right.get(A[i]) - 1);
    if (val > (i + 1) / 2) {
      lMax = A[i];
    }
    if (
      left.get(lMax) > (i + 1) / 2 &&
      right.get(lMax) > (A.length - 1 - i) / 2
    ) {
      count++;
    }
  }

  return count;
}

console.log(solution([4, 3, 4, 4, 4, 2])); // 2
