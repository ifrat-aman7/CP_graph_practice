//https://cses.fi/problemset/task/1666
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+9;
vector<int> g[N];
bool vis[N];
vector<int> component[N];
int tmp=1;

void dfs(int u){
    vis[u]=true;
    component[tmp].push_back(u);
    for(auto v:g[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int cnt=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
            tmp++; cnt++;
        }
    }

    cout<<cnt-1<<'\n';
    if(cnt>1){
        for(int i=1;i<cnt;i++){
            cout<<component[i][0]<<' '<<component[i+1][0]<<'\n';
        }
    }



}
