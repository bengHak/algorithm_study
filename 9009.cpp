#include "iostream"
using namespace std;
int dfs(unsigned int arr[], int num, int N){
    if(num==1)
        return 1;
    for(int i=N; i>0; --i){
        if(arr[i] > num)
            continue;
        else if(arr[i] == num)
            return num;
        else {
            cout << dfs(arr, num-arr[i], N) << " ";
            return arr[i];
        }
    }
}

int main(){
    unsigned int a=1,b=0, c=0,cnt=0;
    unsigned int arr[44];
    unsigned int max = 1000000000;
    while(c<max){
        c = a+b;
        arr[cnt] = c;
        a = b;
        b = c;
        cnt++;
    }

    int T;
    unsigned int N;
    cin >> T;
    for(int i=0; i<T; ++i){
        cin >> N;
        cout << dfs(arr, N, 44) << endl;
    }
    return 0;
}