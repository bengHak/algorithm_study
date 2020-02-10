#include <stdio.h>
#include <stdlib.h>

int zero, one;

int fibonacci(int n){
    if (n == 0){
        zero ++;
        return 0;
    }
    else if(n == 1 ){
        one ++;
        return 1;
    }
    else
        return fibonacci(n-1) + fibonacci(n-2);
}

int main ()
{
    int T; //testCase
    scanf("%d",&T);

    for(int i = 0 ; i < T ;i++){
        zero = 0; one =0;
        int temp;

        scanf("%d", &temp);
        fibonacci(temp);
        printf("%d %d\n",zero,one);
    }

    return 0;
}