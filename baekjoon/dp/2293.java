import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        int n = Integer.parseInt(line[0]);
        int k = Integer.parseInt(line[1]);
        int[] coins = new int[n];
        int[] mem = new int[k + 1];
        for (int i = 0; i < n; i++) {
            coins[i] = Integer.parseInt(br.readLine());
        }
        Arrays.sort(coins);

        mem[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = coins[i]; j <= k; j++) {
                mem[j] += mem[j - coins[i]];
            }
        }

        System.out.println(mem[k]);
    }
}

