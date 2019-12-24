#include "iostream"
#include "string"
using namespace std;
int main(){
    int N,tmp,cnt;

    for(int i=0; i<10; i++){
        cout << "숫자 N을 입력하세요 <0 < N <= 1,000,000>: ";
        cin >> N;
        cnt=0;
        while(N!=0){
            tmp=N;
            while(tmp>=1){
                if(tmp%10 < 4 && tmp%10 > 0)
                    cnt+=1;
                tmp/=10;
            }
            N-=1;
        }
        cout << cnt << endl;
    }

    return 0;
}