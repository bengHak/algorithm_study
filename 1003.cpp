#include <iostream>
 
int a[2] = { 0 };
 
int fibonacci(int n) {
    if (n == 0) {
        ::a[0]++;
        return 0;
    }
    else if (n == 1) {
        ::a[1]++;
        return 1;
    }
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}
 
int main() {
    int n;
    scanf("%d", &n);
 
    for (int i = 0; i < n; ++i) {
        int m;
        scanf("%d", &m);
        fibonacci(m);
 
        printf("%d %d\n", ::a[0], ::a[1]);
        ::a[0] = 0;
        ::a[1] = 0;
    }
 
    return 0;
}
