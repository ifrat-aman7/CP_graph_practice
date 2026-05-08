//https://codeforces.com/problemset/problem/580/C
#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+9;
vector<int> g[N];
bool vis[N];
int cat[N],consecutive_cats[N];
int m;
int ans=0;
void dfs(int u,int p){
    vis[u]=true;
    if(cat[u]){
        consecutive_cats[u]=consecutive_cats[p]+1;
    }else{
        consecutive_cats[u]=0;
    }
    if(consecutive_cats[u]>m){
        return;
    }
    bool is_leaf=true;
    for(auto v:g[u]){
        if(!vis[v]){
            dfs(v,u);
            is_leaf=false;
        }
    }
    if(is_leaf){
        ans++;
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>cat[i];
    }
    for(int i=1;i<=n;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1,0);
    cout<<ans<<"\n";

}
