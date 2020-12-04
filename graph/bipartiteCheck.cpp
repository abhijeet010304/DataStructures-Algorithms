//buglife problem spoj
#include<bits/stdc++.h>
// #include"debug.cpp"
using namespace std;
#define pb push_back
vector<int>g[100005],col(100005);
bool vis[100005];
void addEdge(int u,int v){
    g[u].pb(v);
    g[v].pb(u);
}
int flag = 1;
bool dfs(int v,int c){
    vis[v]=true;
    col[v]=c;
    for(auto x:g[v]){
        if(!vis[x]){
            if(!dfs(x,c^1))return false;
        }
        else{
             if(col[x]==col[v]){
                return false;
            }

        }
    }
    return true;

}
bool bipartite(int n){

    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(dfs(i,0)==false) return false ;
        }
    }
    return true;
}
// void printg(int n ){
//     for(int i=0;i<n;i++){
//         cout<<i<<"->";
//         print(g[i]);
//     }
//     cout<<"\n";
// }
void clearall(int n){
    for(int i=0;i<n;i++){
        g[i].clear();
    }
    memset(vis,false,sizeof(vis));
    col.clear();
    flag =1;
}
int main(){
    int t,p=1;
    cin>>t;
    while(t--){
        int n,m,i;
        cin>>n>>m;
        col.resize(n);
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            u--;
            v--;
            addEdge(u,v);
        }
        // printg(n);
        // bipartite(n)?cout<<"T\n":cout<<"F\n";
        bipartite(n)?cout<<"Scenario #"<<p<<":\nNo suspicious bugs found!\n":cout<<"Scenario #"<<p<<":\nSuspicious bugs found!\n";
        clearall(n);
        p++;
    }
    return 0;
}
