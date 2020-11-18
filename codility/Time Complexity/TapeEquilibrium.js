function solution(A) {
  const mem = new Array(A.length);
  const sum = A.reduce((prev, cur, idx) => {
    mem[idx] = prev + cur;
    return mem[idx];
  }, 0);

  return mem.reduce((prev, cur, idx) => {
    if (idx === mem.length - 1) return prev;
    const num = Math.abs(cur * 2 - sum);
    return Math.min(num, prev);
  }, Infinity);
}

console.log(solution([3, 1, 2, 4, 3])); //1
console.log(solution([-1000, 1000])); //2000
