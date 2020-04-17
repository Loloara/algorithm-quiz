// 1890 DP

import java.util.Scanner;

public class Main {
    private int N;
    private int[][] board;
    private long[][] dp;

    Main() {
        board = new int[100][100];
        dp = new long[100][100];
    }

    public void initData() {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                board[i][j] = sc.nextInt();
                dp[i][j] = -1;
            }
        }
    }

    public long solution() {
        initData();
        return dfs(0,0);
    }

    public long dfs(int x, int y) {
        if(dp[x][y] != -1) return dp[x][y];
        if(x == N-1 && y == N-1) return 1;
        dp[x][y] = 0;
        if(board[x][y] == 0) return 0;
        if(x+board[x][y] < N) {
            dp[x][y] += dfs(x + board[x][y], y);
        }
        if(y+board[x][y] < N) {
            dp[x][y] += dfs(x,y+board[x][y]);
        }
        return dp[x][y];
    }

    public static void main(String[] args) {
        Main s = new Main();
        System.out.println(s.solution());
    }
}
