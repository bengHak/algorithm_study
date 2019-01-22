#include "iostream"
using namespace std;
int main(){
    int a,b,n,w,an,bn,cnt=0;
    cin >> a >> b >> n >> w;
    for(int i=1; i<n; ++i)
        if(i*a+(n-i)*b == w){
            an = i;
            bn = n-i;
            ++cnt;
        }
    if(cnt != 1)
        cout << -1;
    else
        cout << an << " " << bn;
    return 0;
}