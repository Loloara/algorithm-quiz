function solution(number, k) {
  let answer = [];
  let start = 0;
  let targetLength = number.length - k;

  while (k !== 0 && start < number.length && answer.length !== targetLength) {
    const prev = k;

    let maxIndex = start;
    for (let i = start + 1; i < start + k + 1; i++) {
      if (number[maxIndex] == 9) break;
      if (number[maxIndex] < number[i]) {
        maxIndex = i;
      }
    }
    k -= maxIndex - start;
    answer.push(number[maxIndex]);
    start = maxIndex + 1;
  }

  while (start != number.length && answer.length != targetLength)
    answer.push(number[start++]);

  return answer.join("");
}

console.log(solution("1924", 2));
console.log(solution("1231234", 3));
console.log(solution("4177252841", 4));
console.log(solution("999999999999999", 5));
