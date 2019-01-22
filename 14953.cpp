#include "iostream"
#include "vector"
using namespace std;
struct City{
    int cityNum = -1;
    bool visited = false;
    int size = 0;
    vector<int> linkedCity;
};
City city[100001];
int dp[100001];
int dfs(int c){
    if(dp[c] != -1) return dp[c];
    int cnt = 1;
    for(int i = 0; i < city[c].size; ++i){
        if(!city[city[c].linkedCity[i]].visited && city[c].size < city[city[c].linkedCity[i]].size)
            cnt = max(cnt, 1 + dfs(city[c].linkedCity[i]));
    }
    dp[c] = cnt;
    return dp[c];
}
int main(){
    int n, m, cityNum, neighbor, cntVisit, max = -1;
    cin >> n >> m;
    //m
    for(int i=0; i<m; ++i){
        int tmpLinked;

        cin >> cityNum >> neighbor;

        if(city[cityNum].cityNum != -1){
            if(city[neighbor].cityNum == -1){
                city[neighbor].cityNum = neighbor;
            }
            tmpLinked = cityNum;
            city[neighbor].linkedCity.push_back(tmpLinked);
            tmpLinked = neighbor;
            city[cityNum].linkedCity.push_back(tmpLinked);
        } else {
            if(city[neighbor].cityNum != -1){
                city[cityNum].cityNum = cityNum;
            } else {
                city[cityNum].cityNum = cityNum;
                city[neighbor].cityNum = neighbor;
            }
            tmpLinked = cityNum;
            city[neighbor].linkedCity.push_back(tmpLinked);
            tmpLinked = neighbor;
            city[cityNum].linkedCity.push_back(tmpLinked);
        }
    }
    for(int i=0; i<n; ++i)
        city[i].size = (int)city[i].linkedCity.size();

    for(int i=0; i<n; ++i)
        dp[i] = -1;
    for(int i=0; i<n; ++i){
        cntVisit = dfs(i);
        if(max < cntVisit){
            max = cntVisit;
        }
    }

    cout << max;
    return 0;
}