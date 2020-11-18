function solution(N) {
  let maxVal = 0;

  const arr = [...N.toString(2)];
  let counter = 0;
  for (const ch of arr) {
    if (ch === "1") {
      if (maxVal < counter) {
        maxVal = counter;
      }
      counter = 0;
    } else {
      counter++;
    }
  }

  return maxVal;
}

console.log(solution(32)); //0
console.log(solution(15)); //0
console.log(solution(20)); //1
console.log(solution(529)); //4
console.log(solution(1041)); //5
