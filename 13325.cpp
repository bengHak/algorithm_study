#include "iostream"
#include "cmath"
#define MAX(a,b) a>b?a:b
using namespace std;
int main(){
    short a[2097151];
    int h,n,w,i,l,s=0;
    cin>>h;
    n=pow(2,h+1)-1;
    for(i=1;i<n;++i){
        cin>>w;
        a[i]=w+a[(i-1)/2];
        s+=w;
    }
    for(i=(n-2)/2;i>=0;--i){
        l=(i*2)+1;
        s+=abs(a[l]-a[l+1]);
        a[i]=MAX(a[l],a[l+1]);
    }
    cout<<s;
    return 0;
}