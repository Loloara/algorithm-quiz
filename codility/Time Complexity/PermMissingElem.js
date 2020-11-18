function solution(A) {
  return (
    ((A.length + 2) / 2) * (A.length + 1) -
    A.reduce((prev, cur) => prev + cur, 0)
  );
}

console.log(solution([2, 3, 1, 5])); //4
