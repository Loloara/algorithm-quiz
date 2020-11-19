function solution(A, B) {
  let count = 0;
  for (let i = 0; i < A.length; i++) {
    if (A[i] === B[i]) {
      count++;
      continue;
    }
    let a = A[i];
    let b = B[i];
    let gcd = GCD(a, b);

    let tmpGcd = gcd;
    while ((a /= tmpGcd) !== 1 && tmpGcd !== 1) {
      tmpGcd = GCD(a, tmpGcd);
    }
    if (tmpGcd === 1) continue;

    tmpGcd = gcd;
    while ((b /= tmpGcd) !== 1 && tmpGcd !== 1) {
      tmpGcd = GCD(b, tmpGcd);
    }
    if (tmpGcd === 1) continue;

    count++;
  }
  return count;
}

function GCD(a, b) {
  if (a % b === 0) {
    return b;
  } else {
    return GCD(b, a % b);
  }
}

console.log(solution([15, 10, 3], [75, 30, 5])); // 1
console.log(solution([1], [1])); // 1
