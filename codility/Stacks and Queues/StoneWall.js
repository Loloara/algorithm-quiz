function solution(H) {
  const st = [0];
  let count = 0;
  for (let i = 0; i < H.length; i++) {
    while (st[st.length - 1] > H[i]) {
      st.pop();
      count++;
    }
    if (st[st.length - 1] === H[i]) continue;
    st.push(H[i]);
  }
  return count + st.length - 1;
}

console.log(solution([8, 8, 5, 7, 9, 8, 7, 4, 8]));
