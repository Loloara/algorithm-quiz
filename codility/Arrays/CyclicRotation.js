function solution(A, K) {
  const move = K % A.length;
  return A.slice(A.length - move).concat(A.slice(0, A.length - move));
}

console.log(solution([1, 2, 3, 4], 4)); //[1,2,3,4]
console.log(solution([0, 0, 0], 1)); //[0, 0, 0]
console.log(solution([3, 8, 9, 7, 6], 3)); //[9, 7, 6, 3, 8]
