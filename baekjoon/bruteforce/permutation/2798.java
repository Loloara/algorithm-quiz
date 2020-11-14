import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;

public class Main {
    private static final PriorityQueue<Integer> comb = new PriorityQueue<>((a, b) -> b - a);
    private static final int L = 3;
    private static int[] cards;
    private static int N;
    private static int M;

    public static void main(String[] args) throws IOException {
        final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        final int[] firstLine = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        N = firstLine[0];
        M = firstLine[1];
        cards = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

        combGenerator(0, 0, 0);

        System.out.println(comb.peek());
    }

    private static void combGenerator(final int index, final int depth, final int sum) {
        if (L == depth) {
            comb.add(sum);
            return;
        }

        if (N - index < L - depth) {
            return;
        }

        for (int i = index; i < N; i++) {
            if (sum + cards[i] > M) {
                continue;
            }
            combGenerator(i + 1, depth + 1, sum + cards[i]);
        }
    }
}