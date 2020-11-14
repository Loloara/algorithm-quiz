import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        final int[] firstLine = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        final int V = firstLine[0];
        final int E = firstLine[1];
        final int K = Integer.parseInt(br.readLine());
        final List<Edge>[] board = new ArrayList[V + 1];

        final int[] mem = new int[V + 1];
        for (int i = 0; i <= V; i++) {
            mem[i] = Integer.MAX_VALUE;
            board[i] = new ArrayList<>();
        }

        for (int i = 0; i < E; i++) {
            final int[] edgeData = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            board[edgeData[0]].add(new Edge(edgeData[1], edgeData[2]));
        }

        final boolean[] isVisited = new boolean[V + 1];
        final PriorityQueue<Edge> q = new PriorityQueue<>();
        mem[K] = 0;
        q.add(new Edge(K, 0));
        while (!q.isEmpty()) {
            final Edge cur = q.poll();
            final int curTarget = cur.getTarget();
            final int curWeight = cur.getWeight();

            if (isVisited[curTarget]) {
                continue;
            }
            isVisited[curTarget] = true;

            for (final Edge node : board[curTarget]) {
                final int target = node.getTarget();
                final int weight = curWeight + node.getWeight();

                if (mem[target] > weight) {
                    mem[target] = weight;
                    q.add(new Edge(target, weight));
                }
            }
        }

        final StringBuilder sb = new StringBuilder();
        for (int i = 1; i <= V; i++) {
            if (mem[i] == Integer.MAX_VALUE) {
                sb.append("INF\n");
                continue;
            }
            sb.append(mem[i]);
            sb.append("\n");
        }

        System.out.print(sb.toString());
    }
}

class Edge implements Comparable<Edge> {
    private final int target;
    private final int weight;

    Edge(final int target, final int weight) {
        this.target = target;
        this.weight = weight;
    }

    public int getTarget() {
        return target;
    }

    public int getWeight() {
        return weight;
    }

    @Override
    public int compareTo(final Edge edge) {
        return weight - edge.getWeight();
    }
}
