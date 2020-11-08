import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    private static int n, m, count = 0, answer = Integer.MAX_VALUE;
    private static int[][] map;
    private static boolean[] check;
    private static ArrayList<Index> virus = new ArrayList<>();
    private static final int[] dx = {0, 0, -1, 1};
    private static final int[] dy = {-1, 1, 0, 0};

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        map = new int[n][n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
                if (map[i][j] == 2) virus.add(new Index(i, j));
                if (map[i][j] == 0) count++;
            }
        }
        check = new boolean[virus.size()];
        if (count != 0) comb(0, 0);
        else answer = 0;
        System.out.println((answer == Integer.MAX_VALUE) ? -1 : answer);
    }

    private static void comb(int depth, int start) {
        if (depth == m) {
            int[][] copyMap = copy();
            bfs(copyMap, count);
            return;
        }
        for (int i = start; i < virus.size(); i++) {
            check[i] = true;
            comb(depth + 1, i + 1);
            check[i] = false;
        }
    }

    private static void bfs(int[][] map, int count) {
        Queue<Index> queue = new LinkedList<>();
        for (int i = 0; i < virus.size(); i++) {
            if (check[i]) queue.add(virus.get(i));
        }
        int time = 0, nx, ny;
        while (!queue.isEmpty()) {
            if (answer <= time) break;
            int len = queue.size();
            for (int t = 0; t < len; t++) {
                Index index = queue.poll();
                for (int i = 0; i < 4; i++) {
                    nx = index.x + dx[i];
                    ny = index.y + dy[i];
                    if (!isValid(nx, ny) || map[nx][ny] == 1 || map[nx][ny] == 2) continue;
                    if (map[nx][ny] == 0) count--;
                    map[nx][ny] = 2;
                    queue.add(new Index(nx, ny));
                }
            }
            time++;
            if (count == 0) {
                answer = time;
                return;
            }
        }
    }

    private static int[][] copy() {
        int[][] result = new int[n][n];
        for (int i = 0; i < n; i++) {
            System.arraycopy(map[i], 0, result[i], 0, n);
        }
        for (int i = 0; i < virus.size(); i++) {
            if (!check[i]) {
                Index index = virus.get(i);
                result[index.x][index.y] = 3; // 선택되지 않은 바이러스는 3으로
            }
        }
        return result;
    }

    private static boolean isValid(int x, int y) {
        return x >= 0 && y >= 0 && x < n && y < n;
    }
}

class Index {
    int x;
    int y;

    Index(int x, int y) {
        this.x = x;
        this.y = y;
    }
}