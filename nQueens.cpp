#include <iostream>

using namespace std;

bool place(int i, int val, int x[]){
    for(int k=1; k<i; ++k){
        if(x[k] == val)
            return false;
        if( ((x[k]-val)/(k-i)) == 1 || ((x[k]-val)/(k-i)) == -1)
            return false;
    }
    return true;
}

bool nQueens(int i, int n, int x[]){
    for(int k=1; k<=n; ++k)
        cout << x[k] << " ";
    cout << endl;
    for(int val=1; val<=n; ++val){
        if(!place(i, val, x))
            continue;

        x[i] = val;
        if(i == n)
            return true;
        else
            if(nQueens(i+1, n, x))
                return true;
    }
    return false;
}

int main(int argc, const char * argv[]) {
    int n;
    int x[100];
    cin >> n;
    if(nQueens(1, n, x))
        for(int i=1; i<=n; i++)
            cout << x[i] << " ";

    return 0;
}
