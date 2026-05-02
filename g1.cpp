//https://vjudge.net/problem/aizu-alds1_11_a
#include<bits/stdc++.h>
using namespace std;

const int N = 101;
int g[N][N];

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    int tm=t;
    while(t--){
        int u,k; cin>>u>>k;
        for(int i=0;i<k;i++){
            int v; cin>>v;
            g[u][v]=1;
        }

    }

    for(int i=1;i<=tm;i++){
        for(int j=1;j<=tm;j++){
            if(j>1) cout<<' ';
            cout<<g[i][j];
        }
        cout<<"\n";
    }
}
