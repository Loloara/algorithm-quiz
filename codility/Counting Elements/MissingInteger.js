function solution(A) {
  A.sort((a, b) => a - b);

  let num = 1;
  let i = 0;
  while (i < A.length && num >= A[i]) {
    if (num === A[i]) {
      num++;
    }
    i++;
  }

  return num;
}

// console.log(solution([1, 3, 6, 4, 1, 2])); //5
// console.log(solution([1, 2, 3])); //4
// console.log(solution([-1, -3])); //1

const arr = [];
for (let i = 0; i <= 100; i++) {
  arr.push(i);
}
for (let i = 102; i <= 200; i++) {
  arr.push(i);
}
console.log(solution(arr));
