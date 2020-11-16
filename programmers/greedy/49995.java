class Solution {
    public int solution(int[] cookie) {
        int answer = 0;
        int lo, hi, loSum, hiSum;

        for (int mid = 0; mid < cookie.length - 1; mid++) {
            lo = mid;
            hi = mid + 1;
            loSum = cookie[lo];
            hiSum = cookie[hi];
            if (loSum == hiSum) {
                answer = Math.max(answer, loSum);
            }

            while (true) {
                if (loSum == hiSum) {
                    answer = Math.max(answer, loSum);
                    if (lo > 0) {
                        loSum += cookie[--lo];
                    } else if (hi < cookie.length - 1) {
                        hiSum += cookie[++hi];
                    } else {
                        break;
                    }
                } else if (loSum < hiSum) {
                    if (lo == 0) {
                        break;
                    }
                    loSum += cookie[--lo];
                } else {
                    if (hi == cookie.length - 1) {
                        break;
                    }
                    hiSum += cookie[++hi];
                }
            }
        }

        return answer;
    }
}