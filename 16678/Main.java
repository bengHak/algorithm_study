import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

public class Main {
    static int N;
    static int ans = 0;
    static ArrayList<Integer> arr = new ArrayList<Integer>();

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());

        for (int i = 0; i < N; i++) {
            arr.add(Integer.parseInt(br.readLine()));
        }

        Collections.sort(arr);

        for (int i = 0; i < N - 1; i++) {
            if (i == 0 && arr.get(i) != 1) {
                ans = arr.get(i) - 1;
                arr.set(i, 1);
            }
            if (arr.get(i) < arr.get(i + 1)) {
                ans = ans + (arr.get(i + 1) - arr.get(i) - 1);
                arr.set(i + 1, 1 + arr.get(i));
            }
        }

        System.out.println(ans);
        br.close();
    }
}