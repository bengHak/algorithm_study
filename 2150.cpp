#include "iostream"
#include "vector"
#include "list"
#include "utility"

using namespace std;

int cnt = 1;

//정점 v에서 시작하는 깊이우선탐색 코드입니다.
void dfs(vector<pair<pair<int, int>,list<int>>> &G, bool visited[], int v)
{
    visited[v] = true;
    G[v].first.first = cnt++;
    list<int>::iterator itr;
    for(itr = G[v].second.begin(); itr != G[v].second.end(); itr++)
    {
        int w = *itr;
        if(!visited[w])
            dfs(G, visited, w);
    }
    G[v].first.second = cnt++;
}

void transpose(vector<pair<pair<int, int>,list<int>>> &G, int n){
    vector<pair<pair<int, int>,list<int>>> tempG(n+1);

    for(int i=0; i<G.size(); ++i){
        list<int>::iterator itr;
        for(itr = G[i].second.begin(); itr != G[i].second.end(); itr++)
            tempG[*itr].second.push_back(i);
    }
    G = tempG;
}

int main()
{
    int n, m;
    cin >>n >>m;
    vector<pair<pair<int, int>,list<int>>> G(n+1); //가중치가 있는 vector of lists 그래프
    bool visited[n+1];
    bool visited2[n+1];

    for(int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >>v1 >>v2;
        G[v1].first = make_pair(0,0);
        G[v1].second.push_back(v2);
    }

    dfs(G, visited, 1); //1에서 시작하는 깊이우선 탐색

    cout <<endl <<"Result" <<endl; //그래프가 연결되었는지 확인합니다.
    for(int i = 1; i < (int)G.size(); i++)
    {
        cout <<"G[" <<i <<"]"<<"(" << G[i].first.first << ", "<< G[i].first.second <<")";
        list<int>::iterator itr;
        for(itr = G[i].second.begin(); itr != G[i].second.end(); itr++)
            cout <<" -> " <<*itr;
        cout <<endl;
    }

    transpose(G, n);

    for(int j=1; j<n+1; ++j){
        cnt = 1;
        dfs(G, visited2, j);

        cout <<endl <<"Result Transposed" <<endl; //그래프가 연결되었는지 확인합니다.
        for(int i = 1; i < (int)G.size(); i++)
        {
            cout <<"G[" <<i <<"]"<<"(" << G[i].first.first << ", "<< G[i].first.second <<")";
            list<int>::iterator itr;
            for(itr = G[i].second.begin(); itr != G[i].second.end(); itr++)
                cout <<" -> " <<*itr;
            cout <<endl;
        }
    }
}