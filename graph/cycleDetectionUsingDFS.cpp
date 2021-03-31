#include<bits/stdc++.h>
#include"debug.cpp"
using namespace std;
#define pb push_back
vector<int>g[100005];

void addEdge(int u,int v){
    g[u].pb(v);
    // g[v].pb(u);
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
    // memset(vis,false,sizeof(vis));

}

bool dfs(int c,int p,vector<bool> vis){
    vis[c] = true;
    for(auto x :g[c]){
        if(!vis[x]){
            bool res;
            res = dfs(x,c,vis);
            if(res==true)return true;


        }
        else {
            if(x!=p)return true;
        }
    }
    vis[c] = false;
    return false;
}
bool checkCycle(int n){
    vector<bool> vis(n,false);
    bool flag = false;
    for(int i=0;i<n;i++){
        vis[i] = true;
        if(dfs(i,-1,vis))return true;
        vis[i] = false;
    }
    return false;
}

int main(){
    int t;
    // cin>>t;
    t = 1;
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
