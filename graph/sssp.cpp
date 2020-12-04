#include<bits/stdc++.h>
// #include "debug.cpp"
using namespace std;
#define pb push_back
vector<int> g[100005],dist(100005);
bool vis[100005];
void addEdge(int u,int v){
    g[u].pb(v);
    g[v].pb(u);
}
// void printgraph(int n){
//     for(int i=0;i<n;i++){
//         cout<<i<<"-> ";print(g[i]);
//     }
//     cout<<"\n";
// }

void dfs(int s){
    vis[s]=1;
    // dist[s] = min(dist[s],d);
    for(auto x:g[s]){
        if(!vis[x]){
            dfs(x);
        }
    }
}
// void sssp(int s,int n ){
//     int i;
//     for(i=0;i<n;i++){
//         dist[i]=1e9;
//     }
//     dist[s]=0;
//     dfs(s,0);
//
// }
int main(){

    int n,i,m;
    cin>>n>>m;
    for(i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--;v--;
        addEdge(u,v);
    }
    int count =0;
    for(i=0;i<n;i++){
        if(!vis[i]){
            count++;
            dfs(i);
        }
    }
    count==1 and m==n-1 ?cout<<"YES\n":cout<<"NO\n";
    // printgraph(n);
    // int source;
    // cout<<"Enter source vertex-";
    // cin>>source;
    // dist.resize(n);
    // sssp(source,n);
    // print(dist);
    return 0;
}
