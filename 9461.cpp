#include <stdio.h>
 
int main(void){
    int testcase;
    long long Dp[101] = { 1, 1, 1, 1, 2, 2, };
 
    scanf("%d",&testcase);
 
    for (int i = 6; i <= 100; i++)
        Dp[i] = Dp[i - 1] + Dp[i - 5];
 
    while (testcase--){
        int n;
        scanf("%d", &n);
        printf("%lld\n", Dp[n]);
    }
 
}