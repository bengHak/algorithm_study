import java.io.*;
import java.util.Arrays;

public class Main {

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        long ans = 0;
        int[] arr = new int[N];

        for (int i = 0; i < N; i++) {
            arr[i] = (Integer.parseInt(br.readLine()));
        }

        Arrays.sort(arr);

        if (arr[0] != 1) {
            ans = arr[0] - 1;
            arr[0] = 1;
        }

        for (int i = 0; i < N - 1; i++) {

            if (arr[i] < arr[i + 1]) {
                ans = ans + (arr[i + 1] - arr[i] - 1);
                arr[i + 1] = 1 + arr[i];
            }
        }

        System.out.println(ans);
        br.close();
    }
}