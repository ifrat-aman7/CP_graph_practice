//https://vjudge.net/problem/aizu-alds1_11_b
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+9;
vector<int> g[N];
bool vis[N];
int t=1;
int d[N],f[N];

void dfs(int u){
    vis[u]=true;
    d[u]=t;
    t++;
    for(auto v:g[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
    f[u]=t;
    t++;

}

int32_t main(){
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        int u,k; cin>>u>>k;
        for(int j=0;j<k;j++){
            int v; cin>>v;
            g[u].push_back(v);
        }
    }

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    for(int i=1;i<=n;i++){
        cout<<i<<' '<<d[i]<<' '<<f[i]<<'\n';
    }

}
