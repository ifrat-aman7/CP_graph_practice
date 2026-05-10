//https://vjudge.net/problem/aizu-alds1_11_c
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+9;
vector<int> g[N];
bool vis[N];
int dist[N];


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    int tm=n;
    while(tm--){
        int u,t;
        cin>>u>>t;
        for(int i=0;i<t;i++){
            int v; cin>>v;
            g[u].push_back(v);
        } 
    }
    dist[1]=0;
    for(int i=2;i<=102;i++){
        dist[i]=101;
    }
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        vis[v]=true;
        for(auto e:g[v]){
            if(!vis[e]){
                q.push(e);
                dist[e]=min(dist[e],dist[v]+1);
            }
        }

    }

    for(int i=1;i<=n;i++){
        if(dist[i]==101 and i!=1){
            cout<<i<<' '<<-1<<'\n';
        }else{
            cout<<i<<' '<<dist[i]<<'\n';
        }
    }
}
