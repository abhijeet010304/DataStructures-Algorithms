#include<bits/stdc++.h>
#include"debug.cpp"
using namespace std;
#define pb push_back
vector<int>g[100005];
bool vis[100005];
void addEdge(int u,int v){
    g[u].pb(v);
    g[v].pb(u);
}


void printg(int n ){
    for(int i=0;i<n;i++){
        cout<<i<<"->";
        print(g[i]);
    }
    cout<<"\n";
}
void clearall(int n){
    for(int i=0;i<n;i++){
        g[i].clear();
    }
    memset(vis,false,sizeof(vis));

}

bool dfs(int c,int p){
    vis[c]=true;
    for(auto x :g[c]){
        if(!vis[x]){
            bool res;
            res = dfs(x,c);
            if(res==true)return true;


        }
        else {
            if(x!=p)return true;
        }
    }
    return false;
}
bool checkCycle(int n){
    for(int i=0;i<n;i++){
        if(dfs(i,-1))return true;
    }
    return false;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,i;
        cin>>n>>m;
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            u--;
            v--;
            addEdge(u,v);
        }
        printg(n);
        cout<<checkCycle(n)<<"\n";
    }
    return 0;
}
