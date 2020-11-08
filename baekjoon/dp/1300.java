import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int k = Integer.parseInt(br.readLine());
        int left = 1;
        int right = k;      //찾는 값은 k보다 클 수 없음

        int target = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            int cnt = 0;
            for (int i = 1; i <= Math.min(n, mid); i++) {
                cnt += Math.min(n, mid / i);
            }

            if (cnt < k) {
                left = mid + 1;
            } else {
                target = mid;
                right = mid - 1;
                //조건을 만족하는 가장 작은 값을 찾아야함
            }
        }
        System.out.println(target);
    }
}