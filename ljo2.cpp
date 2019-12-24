#include "iostream"
using namespace std;
int main(){
    int N,cnt, cntBlank;
    char a;
    while(1){
        cin >> N;
        cntBlank = N-1;
        if(N==0)
            break;

        for(int i=0; i<N; i++){
            cnt=i;
            a = 65;
            for(int j=0; j<cntBlank; j++){
                cout << " ";
            }
            cntBlank-=1;

            for(int j=0; j<N; j++){
                cout << a <<" ";
                cnt-=1;
                a+=1;
                if(cnt<0){
                    cout << endl;
                    break;
                }
            }
        }

    }
    return 0;
}