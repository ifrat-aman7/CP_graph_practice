//https://codeforces.com/problemset/problem/24/A
#include<bits/stdc++.h>
using namespace std;

const int N = 105;
vector<pair<int,int>> g[N];
bool vis[N];
int cost=0;
void dfs(int u,int p=0){
    vis[u]=true;
    for(auto [v,w]:g[u]){
        if(!vis[v]){
            cost+=w;
            dfs(v,u);
        }else if(v==1 and p!=1){
            cost+=w;
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++){
        int u,v,w; cin>>u>>v>>w;
        g[u].push_back({v,0});
        g[v].push_back({u,w});
        sum+=w;
    }
    dfs(1);
    cout<<min(cost,sum-cost)<<"\n";
}
