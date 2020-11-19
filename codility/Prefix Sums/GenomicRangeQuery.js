function solution(S, P, Q) {
  const dna = ["A", "C", "G", "T"];
  const ans = new Array(P.length);
  const weights = {};
  for (const ch of dna) {
    weights[ch] = new Array(S.length).fill(0);
  }
  weights[S[0]][0] = 1;

  for (let i = 1; i < S.length; i++) {
    for (const ch of dna) {
      weights[ch][i] = weights[ch][i - 1];
    }
    weights[S[i]][i]++;
  }

  for (let i = 0; i < P.length; i++) {
    if (P[i] === 0) {
      for (const [idx, ch] of dna.entries()) {
        if (weights[ch][Q[i]] > 0) {
          ans[i] = idx + 1;
          break;
        }
      }
    } else {
      for (const [idx, ch] of dna.entries()) {
        if (weights[ch][Q[i]] > weights[ch][P[i] - 1]) {
          ans[i] = idx + 1;
          break;
        }
      }
    }
  }

  return ans;
}

console.log(solution("CAGCCTA", [2, 5, 0], [4, 5, 6])); //  [2,4,1]
console.log(solution("CAGCCTA", [1, 5, 0], [4, 5, 6])); //  [2,4,1]
