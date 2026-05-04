//https://lightoj.com/problem/equalizing-money
#include<bits/stdc++.h>
using namespace std;

const int N=1e3+9;
vector<int> g[N];
bool vis[N];
vector<int> vec(N);
int sum,nodes;

void dfs(int u){
    vis[u]=true;
    sum+=vec[u];
    nodes++;
    for(auto v:g[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    int cs=1;
    while(t--){
        int n,m; cin>>n>>m;
        for(int i=1;i<=n;i++){
            vis[i]=false;
            g[i].clear();
        }
        for(int i=1;i<=n;i++){
            cin>>vec[i];
        }
        for(int i=0;i<m;i++){
            int u,v; cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        // int cnt=0;
        bool flg=true;
        set<int> s;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                sum=0;
                nodes=0;
                dfs(i);
                if(sum%nodes!=0){
                    flg=false;
                    break;
                }
                s.insert(sum/nodes);
                
            }
        }

        if(flg and s.size()==1) cout<<"Case "<<cs<<": Yes"<<"\n";
        else cout<<"Case "<<cs<<": No"<<"\n";
        cs++;



    }
}
