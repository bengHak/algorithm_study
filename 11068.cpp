#include"iostream"
using namespace std;
int main(){
    int mod[20],N,num,tmp,l,i,j,k,b;
    cin>>N;
    for(i=0;i<N;++i){
        cin>>num;
        for(j=2;j<=64;++j){
            tmp=num;
            b=1;
            for(k=0;tmp>=1;++k){
                mod[k]=tmp%j;
                tmp/=j;
            }
            for(l=0;l<=k/2;++l)
                if(mod[l]==mod[k-l-1]) continue;
                else{
                    b=0;
                    break;
                }
            if(b==1) break;
        }
        cout<<b<<endl;
    }
    return 0;
}