function solution(A) {
  const counter = new Map();
  for (const num of A) {
    let val = 1;
    if (counter.has(num)) {
      val += counter.get(num);
    }
    counter.set(num, val);
  }

  for (const [key, value] of counter) {
    if (value % 2 === 1) {
      return key;
    }
  }
}

console.log(solution([9, 3, 9, 3, 9, 7, 9]));
