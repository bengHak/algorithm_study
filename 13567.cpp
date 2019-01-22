//
// Created by 고병학 on 2019-01-18.
//

#include "iostream"
#include "string"
using namespace std;
int main(){
    int S,N,n,X=0,Y=0,d=1;
    int x[4]={0,1,0,-1};
    int y[4]={1,0,-1,0};
    string a;
    cin >>S>>N;
    for(int i=0;i<N;++i){
        cin>>a>>n;
        if(a=="MOVE"){
            X+=x[d]*n;
            Y+=y[d]*n;
            if(X<0||Y<0||X>S||Y>S){
                cout<<-1;
                return 0;
            }
        }else{
            if(n==0)--d;
            else ++d;
            d%=4;
            d=d<0?d+4:d;
        }
    }
    cout<<X<<" "<<Y;
    return 0;
}