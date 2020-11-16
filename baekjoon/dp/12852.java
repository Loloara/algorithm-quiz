import java.util.Arrays;
import java.util.Scanner;
import java.util.Stack;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int[][] mem = new int[x + 1][2];
        for (int[] arr : mem) {
            Arrays.fill(arr, Integer.MAX_VALUE);
        }
        mem[x][0] = 0;
        mem[x][1] = x;

        for (int i = x - 1; i > 0; i--) {
            int divTwo = Integer.MAX_VALUE;
            int divThree = Integer.MAX_VALUE;
            if (i * 2 <= x) {
                divTwo = mem[i * 2][0];
            }
            if (i * 3 <= x) {
                divThree = mem[i * 3][0];
            }
            mem[i][0] = Math.min(Math.min(mem[i + 1][0], divTwo), divThree);
            if (mem[i][0] == mem[i + 1][0]) {
                mem[i][1] = i + 1;
            } else if (mem[i][0] == divTwo) {
                mem[i][1] = i * 2;
            } else if (mem[i][0] == divThree) {
                mem[i][1] = i * 3;
            }
            mem[i][0]++;
        }


        StringBuilder sb = new StringBuilder();
        sb.append(mem[1][0]);
        sb.append("\n");
        Stack<Integer> st = new Stack<>();
        for (int i = 1; i < x; i = mem[i][1]) {
            st.add(mem[i][1]);
        }
        while (!st.empty()) {
            sb.append(st.pop());
            sb.append(" ");
        }
        sb.append(1);
        System.out.println(sb.toString());
    }
}
