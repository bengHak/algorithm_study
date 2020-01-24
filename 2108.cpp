#include "iostream"
#include "algorithm"
#include "cmath"

using namespace std;
int main(){
    int N;
    int arr[500000];
    
    cin >> N;

    for(int i=0; i<N; i++)
        cin >> arr[i];
    
    sort(arr, arr+N);
    
    int mode[8001] = {0,};
    double mean=0;
    int medium = arr[N/2];
    int min=4001;
    int max = -4001;
    for(int i=0; i<N; i++) {
        mode[arr[i]+4000] += 1;
        if(min > arr[i]) {
            min = arr[i];
        }
        if(max < arr[i]) {
            max = arr[i];
        }
        mean += arr[i];
    }
    
    int maxMode = -1;
    int modeIndex = -1;
    bool second = false;
    for(int i=0; i<8001; i++) {
        if(maxMode < mode[i]) {
            maxMode = mode[i];
            modeIndex = i;
            second = false;
        } else if(maxMode == mode[i] && !second) {
            modeIndex = i;
            second = true;
        }
    }
    
    mean = mean/N;
    cout << round(mean) << endl << medium<< endl << modeIndex-4000 <<endl << max-min << endl;
    
    return 0;
}
