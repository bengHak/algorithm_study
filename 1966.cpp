#include "iostream"
using namespace std;

struct Node{
    int val;
    bool printed = false;
};
bool isMax(Node arr[], int id, int N){
    int max = arr[id].val;
    for(int i=0; i<N; ++i){
        if(max < arr[i].val && !arr[i].printed)
            return false;
    }
    return true;
}

int main(){
    int Total, N, M, cnt;
    Node arr[100];
    cin >> Total;
    while(Total-- > 0){
        cin >> N >> M;
        cnt=0;
        for(int i=0; i<N; ++i)
            arr[i].printed = false;
        for(int i=0; i<N; ++i)
            cin >> arr[i].val;
        while(!arr[M].printed)
            for(int i=0; i<N; ++i)
                if(!arr[i].printed)
                    if(isMax(arr, i, N)){
                        arr[i].printed = true;
                        cnt++;
                        if(M == i){
                            cout << cnt << endl;
                            break;
                        }
                    }
    }
    return 0;
}