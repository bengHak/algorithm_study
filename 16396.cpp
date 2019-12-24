#include "iostream"
using namespace std;
int main(){
    int arr[10001];
    int N, X, Y, cnt=0;
    cin >> N;
    for(int i=0; i<10001; ++i)
        arr[i]=0;
    for(int i=0; i<N; ++i){
        cin >> X >> Y;
        if(X > Y){
            int copy = X;
            X = Y;
            Y = copy;
        }
        while(Y-X > 0){
            arr[X]=1;
            ++X;
        }
    }
    for(int i=0; i<10001; ++i)
        if(arr[i]==1)
            ++cnt;
    cout << cnt << endl;
    return 0;
}