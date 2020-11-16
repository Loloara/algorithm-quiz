import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    private static final int[] dx = {0, 1, 0};
    private static final int[] dy = {1, 0, -1};
    private static final int MIN_VALUE = -100000001;
    private static int N;
    private static int M;
    private static int[][] board;
    private static int[][][] mem;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] firstLine = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        N = firstLine[0];
        M = firstLine[1];
        board = new int[N][M];
        mem = new int[N][M][3];         // [i][j] 에서 [dir] 으로 진행헀을 때 최대값을 캐싱
        for (int i = 0; i < N; i++) {
            board[i] = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            for (int j = 0; j < M; j++) {
                mem[i][j][0] = mem[i][j][1] = mem[i][j][2] = MIN_VALUE;
            }
        }

        boolean[][] visited = new boolean[N][M];
        visited[0][0] = true;
        int ans = dfs(0, 0, visited);
        System.out.println(ans);
    }

    private static int dfs(int x, int y, boolean[][] visited) {
        if (x == N - 1 && y == M - 1) {
            return board[x][y];
        }

        int maxVal = MIN_VALUE;     //세 방향으로 갔을 때 최대값을 계산하여 캐싱하고 리턴한다
        for (int i = 0; i < 3; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!isValidatePos(nx, ny) || visited[nx][ny]) continue;
            if (mem[x][y][i] == MIN_VALUE) {
                visited[nx][ny] = true;
                mem[x][y][i] = Math.max(mem[x][y][i], board[x][y] + dfs(nx, ny, visited));
                visited[nx][ny] = false;
            }
            maxVal = Math.max(maxVal, mem[x][y][i]);
        }

        return maxVal;
    }

    private static boolean isValidatePos(int x, int y) {
        return x >= 0 && y >= 0 && x < N && y < M;
    }
}
