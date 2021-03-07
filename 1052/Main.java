import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        int a = 0;

        for (int i = 0; i < K; ++i) {
            a = 0;

            while (N > (int) Math.round(Math.pow(2, a + 1)))
                a += 1;

            N -= (int) Math.round(Math.pow(2, a));

            if (N == 0)
                break;
        }

        if (N == 0) {
            System.out.println(0);
        } else {
            System.out.println((int) Math.round(Math.pow(2, a)) - N);
        }
    }
}

/*
 * N = 10 K = 3
 * 
 * k개의 물병을 2^n으로 만들기 2341
 * 
 * 2048
 * 
 * 255
 * 
 * 38 + 26
 */