//
// Created by 고병학 on 2019-02-27.
//
#include "iostream"
using namespace std;
int Generator(int N){
    int result = 0;
    result += N;
    while(N>=1){
        result += N%10;
        N /= 10;
    }
    return result;
}
int Reverse(int M){
    int cnt=0;
    int MCopied = M;
    int result = 0;
    while(MCopied>=1){
        MCopied/=10;
        ++cnt;
    }
    for(int i=1; i<=cnt*9; ++i){
        if(M == Generator(M-i))
            result = M-i;
    }
    return result;
}
int main(){
    int N;
    cin >> N;
    cout << Reverse(N) << endl;
    return 0;
}