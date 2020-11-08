import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[] charArr = br.readLine().toCharArray();
        boolean[][] isPallin = new boolean[charArr.length][charArr.length];
        int[] mem = new int[charArr.length];

        for (int i = 0; i < charArr.length - 1; i++) {
            isPallin[i][i] = true;
            if (charArr[i] == charArr[i + 1]) {
                isPallin[i][i + 1] = true;
            }
        }
        isPallin[charArr.length - 1][charArr.length - 1] = true;

        for (int i = 2; i < charArr.length; i++) {
            for (int j = 0; j < charArr.length - i; j++) {
                if (charArr[j] == charArr[j + i]) {
                    if (isPallin[j + 1][j + i - 1]) {
                        isPallin[j][j + i] = true;
                    }
                }
            }
        }

        mem[0] = 1;
        for (int i = 1; i < charArr.length; i++) {
            int min = mem[i - 1];
            for (int j = 0; j <= i; j++) {
                if (isPallin[j][i]) {
                    if (j == 0) {
                        min = 0;
                        break;
                    } else {
                        min = Math.min(mem[j - 1], min);
                    }
                }
            }
            mem[i] = min + 1;
        }

        System.out.println(mem[charArr.length - 1]);
    }
}