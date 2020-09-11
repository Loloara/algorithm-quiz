function isDone(name, index, dir) {
  if (dir === 1) {
    for (let i = index + 1; i < name.length; i++) {
      if (name[i] !== "A") return false;
    }
    return true;
  } else {
    for (let i = index - 1; i > 0; i--) {
      if (name[i] !== "A") return false;
    }
    return true;
  }
}

function solution(name) {
  let left = 0;
  let right = 0;

  let tmp = name.charCodeAt(0) - 65;
  if (tmp > 13) tmp = 26 - tmp;
  right = tmp;
  left = tmp;

  for (let i = 1; i < name.length; i++) {
    right++;
    let tmp = name.charCodeAt(i) - 65;
    if (tmp > 13) tmp = 26 - tmp;
    right += tmp;
    if (isDone(name, parseInt(i), 1)) break;
  }

  for (let i = name.length - 1; i > 0; i--) {
    left++;
    let tmp = name.charCodeAt(i) - 65;
    if (tmp > 13) tmp = 26 - tmp;
    left += tmp;
    if (isDone(name, parseInt(i), 2)) break;
  }

  return left < right ? left : right;
}

console.log(solution("JEROEN"));
console.log(solution("JAN"));
