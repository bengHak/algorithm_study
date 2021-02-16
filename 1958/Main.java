import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static int[][][] arr = new int[101][101][101];
    static String[] strArr = new String[3];
    static int[] len = new int[3];

    static int maxValue(int i, int j, int k) {
        int max = arr[i - 1][j][k];
        if (arr[i][j - 1][k] > max)
            max = arr[i][j - 1][k];
        if (arr[i][j][k - 1] > max)
            max = arr[i][j][k - 1];
        return max;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        strArr[0] = br.readLine();
        strArr[1] = br.readLine();
        strArr[2] = br.readLine();
        len[0] = strArr[0].length();
        len[1] = strArr[1].length();
        len[2] = strArr[2].length();

        for (int i = 1; i <= len[0]; i++) {
            for (int j = 1; j <= len[1]; j++) {
                for (int k = 1; k <= len[2]; k++) {
                    if (strArr[0].charAt(i - 1) == strArr[1].charAt(j - 1)
                            && strArr[0].charAt(i - 1) == strArr[2].charAt(k - 1)) {
                        arr[i][j][k] = arr[i - 1][j - 1][k - 1] + 1;
                    } else {
                        arr[i][j][k] = maxValue(i, j, k);
                    }
                }
            }
        }

        System.out.print(arr[len[0]][len[1]][len[2]]);
    }
}
