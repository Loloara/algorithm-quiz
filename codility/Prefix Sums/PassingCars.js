function solution(A) {
  const MAX_VALUE = 1000000000;
  let base = 0;
  let count = 0;
  for (let car of A) {
    if (car === 1) count += base;
    else base++;
    if (count > MAX_VALUE) return -1;
  }
  return count;
}

console.log(solution([0, 1, 0, 1, 1])); //5
