#include <iostream>

using namespace std;

int n, m;
bool visit[10];
int arr[10];

void go(int count, int min) {
    if(count == m) {
        for(int i=0; i<m ; i++) {
            cout << arr[i] + 1;
        }
        cout << endl;
    }

    for(int i=min; i<n; i++) {
        if(!visit[i]) {
            visit[i] = true;
            arr[count] = i;
            go(count+1, i+1);
            visit[i] = false;
        }
    }
}

int main() {
    cin >> n >> m;
    go(0, 0);
    return 0;
}