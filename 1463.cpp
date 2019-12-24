#include "iostream"
using namespace std;
int main(){
    int N,cnt=0;
    cin>>N;
    while(N!=1){
        if(cnt%3==0){
            N/=3;
            cnt++;
            continue;
        } else if(cnt%2==0){
            N/=2;
            cnt++;
            continue;
        } else{
            N-=1;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}