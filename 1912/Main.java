import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collections;

public class Main {
    static int N;
    static Integer[] arr = new Integer[100001];
    static Integer[] ans;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        ans = new Integer[N];

        String[] s = br.readLine().split(" ");

        for (int i = 0; i < N; ++i) {
            arr[i] = Integer.parseInt(s[i]);
        }

        if (N == 1) {
            System.out.println(arr[0]);
            return;
        }

        ans[0] = arr[0];
        for (int i = 1; i < N; ++i) {
            ans[i] = Math.max(0, ans[i - 1]) + arr[i];
        }

        System.out.println(Collections.max(Arrays.asList(ans)));

        return;
    }
}