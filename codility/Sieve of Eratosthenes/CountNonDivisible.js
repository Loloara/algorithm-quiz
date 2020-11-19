function solution(A) {
  const ans = new Array(A.length);
  let counter = new Array(A.length * 2 + 1).fill(0);

  for (let num of A) {
    counter[num]++;
  }

  for (let i = 0; i < A.length; i++) {
    let cnt = 0;

    for (let j = 1; j * j <= A[i]; j++) {
      if (A[i] % j === 0) {
        cnt += counter[j];
        if (A[i] / j !== j) {
          cnt += counter[A[i] / j];
        }
      }
    }
    ans[i] = A.length - cnt;
  }

  return ans;
}

console.log(solution([3, 1, 2, 3, 6])); //[2,4,3,2,0]
