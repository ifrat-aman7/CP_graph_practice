//https://vjudge.net/problem/uva-572
#include<bits/stdc++.h>
using namespace std;

const int N = 109;
bool vis[N][N];
char g[N][N];
int m,n;

void dfs(int i,int j){
    vis[i][j]=true;
    if(j+1<=n && g[i][j+1]=='@' && !vis[i][j+1]) dfs(i,j+1);
    if(j+1<=n && i-1>=1 && g[i-1][j+1]=='@' && !vis[i-1][j+1]) dfs(i-1,j+1);
    if(j+1<=n && i+1<=m && g[i+1][j+1]=='@' && !vis[i+1][j+1]) dfs(i+1,j+1);
    if(i-1>=1 && g[i-1][j]=='@' && !vis[i-1][j]) dfs(i-1,j);
    if(i+1<=m && g[i+1][j]=='@' && !vis[i+1][j]) dfs(i+1,j);
    if(j-1>=1 && g[i][j-1]=='@' && !vis[i][j-1]) dfs(i,j-1);
    if(j-1>=1 && i-1>=1 && g[i-1][j-1]=='@' && !vis[i-1][j-1]) dfs(i-1,j-1);
    if(i+1<=m && j-1>=1 && g[i+1][j-1]=='@' && !vis[i+1][j-1]) dfs(i+1,j-1);
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(1){
        cin>>m>>n;
        if(m==0 && n==0){
            break;
        }

        for(int i=1;i<=100;i++){
            for(int j=1;j<=100;j++){
                vis[i][j]=false;
            }
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                cin>>g[i][j];
            }
        }

        int cnt=0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(!vis[i][j] && g[i][j]=='@'){
                    cnt++;
                    dfs(i,j);
                }
            }
        }
        cout<<cnt<<'\n';

    }

}
