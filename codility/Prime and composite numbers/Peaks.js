function solution(A) {
  const peeks = new Array(A.length).fill(0);
  let MAX_PEEK = 0;
  for (let i = 1; i < A.length - 1; i++) {
    if (A[i - 1] < A[i] && A[i] > A[i + 1]) MAX_PEEK++;
    peeks[i] = MAX_PEEK;
  }
  peeks[A.length - 1] = MAX_PEEK;

  let answer = 0;
  for (let i = MAX_PEEK; i > 0; i--) {
    if (A.length % i !== 0) continue;
    const block = A.length / i;
    let done = true;
    if (peeks[0] === peeks[block - 1]) continue;
    for (let j = block; j < A.length; j += block) {
      if (peeks[j + block - 1] === peeks[j - 1]) {
        done = false;
        break;
      }
    }
    if (done) {
      answer = i;
      break;
    }
  }

  return answer;
}

console.log(solution([1, 2, 3, 4, 3, 4, 1, 2, 3, 4, 6, 2])); //3
console.log(solution([1, 3, 2, 1])); //1
