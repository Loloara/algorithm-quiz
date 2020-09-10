function rent(n, lost, reserve) {
  let answer = n - lost.length;

  for (let i in lost) {
    for (let j in reserve) {
      if (Math.abs(lost[i] - reserve[j]) === 1) {
        const tmp = rent(
          n,
          [...lost.filter((e) => e !== lost[i])],
          [...reserve.filter((e) => e !== reserve[j])]
        );
        if (answer < tmp) answer = tmp;
      }
    }
  }

  return answer;
}

function solution(n, lost, reserve) {
  lost.sort((a, b) => a - b);
  reserve.sort((a, b) => a - b);

  for (let val of reserve) {
    const isDup = lost.indexOf(val);
    if (isDup >= 0) {
      reserve = reserve.filter((e) => e !== val);
      lost = lost.filter((e) => e !== val);
    }
  }

  return rent(n, lost, reserve);
}

console.log(solution(5, [2, 4], [1, 3, 5]));
console.log(solution(5, [2, 4], [3]));
console.log(solution(3, [3], [1]));
