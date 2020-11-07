import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        String[] q = new String[2000000];
        int qi = 0;
        int qj = 0;
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < N; i++) {
            String line = br.readLine();
            String[] cmd = line.split(" ");
            switch (cmd[0]) {
                case "push":
                    q[qj++] = cmd[1];
                    break;
                case "pop":
                    if (qj - qi <= 0) {
                        sb.append(-1).append("\n");
                    } else {
                        sb.append(q[qi++]).append("\n");
                    }
                    break;
                case "size":
                    sb.append(qj - qi).append("\n");
                    break;
                case "empty":
                    if (qj - qi <= 0) {
                        sb.append(1).append("\n");
                    } else {
                        sb.append(0).append("\n");
                    }
                    break;
                case "front":
                    if (qj - qi <= 0) {
                        sb.append(-1).append("\n");
                    } else {
                        sb.append(q[qi]).append("\n");
                    }
                    break;
                case "back":
                    if (qj - qi <= 0) {
                        sb.append(-1).append("\n");
                    } else {
                        sb.append(q[qj - 1]).append("\n");
                    }
                    break;
            }
        }

        System.out.print(sb.toString());
    }
}