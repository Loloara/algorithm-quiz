import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.stream.Collectors;

public class Main {
    static Map<Integer, ArrayList<Integer>> board;
    static List<Integer> track;
    static int[] weights;
    static int[][] mem;
    static boolean[] visited;

    public static void dfs(int idx) {
        mem[idx][0] = 0;
        mem[idx][1] = weights[idx - 1];

        for (int child : board.get(idx)) {
            if (visited[child]) {
                continue;
            }
            visited[child] = true;
            dfs(child);
            mem[idx][0] += Math.max(mem[child][1], mem[child][0]);
            mem[idx][1] += mem[child][0];
        }
    }

    public static void trace(int idx, boolean available) {
        if (mem[idx][1] > mem[idx][0] && available) {
            track.add(idx);
            available = false;
        } else {
            available = true;
        }

        for (int child : board.get(idx)) {
            if (visited[child]) {
                continue;
            }
            visited[child] = true;
            trace(child, available);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        board = new HashMap<>();
        track = new ArrayList<>();

        int n = Integer.parseInt(br.readLine());
        weights = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

        String line = "";
        while ((line = br.readLine()) != null && line.length() != 0) {
            int[] edge = Arrays.stream(line.split(" ")).mapToInt(Integer::parseInt).toArray();
            if (board.containsKey(edge[0])) {
                board.get(edge[0]).add(edge[1]);
            } else {
                board.put(edge[0], new ArrayList<>(Collections.singletonList(edge[1])));
            }
            if (board.containsKey(edge[1])) {
                board.get(edge[1]).add(edge[0]);
            } else {
                board.put(edge[1], new ArrayList<>(Collections.singletonList(edge[0])));
            }
        }

        visited = new boolean[n + 1];
        mem = new int[n + 1][2];
        visited[1] = true;
        dfs(1);
        int maxSize = Math.max(mem[1][0], mem[1][1]);

        visited = new boolean[n + 1];
        visited[1] = true;
        trace(1, true);
        System.out.println(maxSize);
        track.sort((a, b) -> a - b);
        System.out.println(track.stream().map(Object::toString).collect(Collectors.joining(" ")));
    }
}