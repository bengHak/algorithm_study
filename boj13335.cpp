//
// Created by 고병학 on 2018-12-25.
//

#include "iostream"
#include "queue"
using namespace std;
struct OnBridge{
    int weight;
    int cnt;
};
int main(){
    int n, w, L, a, time = 0;

    queue<OnBridge> q;
    OnBridge tmp;
    cin >> n >> w >> L;
    for(int i=0; i<n; ++i){
        cin >> a;
        tmp.weight = a;
        tmp.cnt = w;
    }
    return 0;
}