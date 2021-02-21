import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static int[][] arr = new int[1001][1001];
    static String[] strArr = new String[2];
    static int[] len = new int[2];

    static int maxValue(int i, int j) {
        int max = arr[i - 1][j];
        if (arr[i][j - 1] > max)
            max = arr[i][j - 1];
        return max;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = "";

        strArr[0] = br.readLine();
        strArr[1] = br.readLine();
        len[0] = strArr[0].length();
        len[1] = strArr[1].length();

        for (int i = 1; i <= len[0]; i++) {
            for (int j = 1; j <= len[1]; j++) {
                if (strArr[0].charAt(i - 1) == strArr[1].charAt(j - 1)) {
                    arr[i][j] = arr[i - 1][j - 1] + 1;
                    s = s.concat(Character.toString(strArr[0].charAt(i - 1)));
                } else {
                    arr[i][j] = maxValue(i, j);
                }
            }
        }

        System.out.println(arr[len[0]][len[1]]);
        System.out.println(s);
    }
}
