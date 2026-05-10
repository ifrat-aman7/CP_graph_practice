//https://cses.fi/problemset/task/1667
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+9;
vector<int> g[N];
int d[N];
int par[N];
int inf = N;

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m; cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        d[i]=inf;
    }
    q.push(1);
    d[1]=0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v:g[u]){
            if(d[u]+1<d[v]){
                d[v]=d[u]+1;
                par[v]=u;
                q.push(v);
            }
        }
    }

    if(d[n]==inf){
        cout<<"IMPOSSIBLE"<<'\n';
    }else{
        cout<<d[n]+1<<'\n';
        vector<int> path;
        int u=n;
        while(u!=1){
            path.push_back(u);
            u=par[u];
        }
        path.push_back(1);
        reverse(path.begin(),path.end());
        for(auto u: path){
            cout<<u<<' ';
        }
        cout<<'\n';

    }

    
}
