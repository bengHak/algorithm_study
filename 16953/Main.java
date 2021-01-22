import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int a, b;

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        a = Integer.parseInt(st.nextToken());
        b = Integer.parseInt(st.nextToken());

        int cnt = 0;

        while (true) {
            if (a > b) {
                System.out.println(-1);
                break;
            }
            if (a == b) {
                System.out.println(cnt + 1);
                break;
            }

            if (b % 10 == 1) {
                b /= 10;
            } else if (b % 2 == 0) {
                b /= 2;
            } else {
                System.out.println(-1);
                break;
            }
            cnt++;
        }
    }
}
