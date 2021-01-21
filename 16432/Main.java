import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N;
    static int[][] p = new int[1001][10];
    static boolean[][] check = new boolean[1001][10];
    static int ans[] = new int[1001];

    static boolean dfs(int pos, int prev) {
        if (pos == N - 1) {
            for (int i = 0; i < 10; i++) {
                if (i == prev)
                    continue;
                if (p[pos][i] != 0) {
                    ans[pos] = i;
                    return true;
                }
            }
        }
        // 각 날마다 다음날 떡으로 탐색을 진행한다.
        for (int i = 0; i < 10; i++) {
            if (i == prev)
                continue;
            if ((p[pos][i] != 0) && !check[pos + 1][i]) {
                check[pos + 1][i] = true;
                ans[pos] = i;
                if (dfs(pos + 1, i))
                    return true;
            }
        }
        return false;
    }

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine()); // 떡 파는 일 수
        StringTokenizer st;

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int j = Integer.parseInt(st.nextToken());
            for (int k = 0; k < j; k++) {
                p[i][k] = Integer.parseInt(st.nextToken());
            }
        }

        if (dfs(0, 0)) {
            for (int i = 0; i < N; i++)
                System.out.println(p[i][ans[i]]);
        } else
            System.out.println("-1");

    }
}