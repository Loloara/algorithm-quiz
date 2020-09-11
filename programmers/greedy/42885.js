function solution(people, limit) {
  let answer = 0;
  let lPtr = 0;
  let rPtr = people.length - 1;

  people.sort((a, b) => b - a);
  while (lPtr <= rPtr) {
    let weight = people[lPtr] + people[rPtr];
    if (weight > limit) {
      lPtr++;
    } else {
      lPtr++;
      rPtr--;
    }
    answer++;
  }

  return answer;
}

console.log(solution([70, 50, 80, 50], 100));
console.log(solution([70, 80, 50], 100));
