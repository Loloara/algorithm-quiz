function solution(A) {
  const box = new Set();
  let maxNum = 0;
  let sum = A.reduce((prev, cur) => {
    box.add(cur);
    if (maxNum < cur) {
      maxNum = cur;
    }
    return prev + cur;
  }, 0);

  if (box.size === maxNum && maxNum === A.length) return 1;
  else return 0;
}

console.log(solution([3, 1, 3, 3, 5, 6, 7])); //0
console.log(solution([4, 1, 3, 2])); //1
console.log(solution([3, 1, 3, 2])); //0
console.log(solution([4, 1, 3])); //0
