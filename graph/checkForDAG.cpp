#include<bits/stdc++.h>
using namespace std ;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "debug.cpp"
#endif

//////////////////////////////////////////////////////////////////////////////////////////////
void solve();
//////////////////////////////////////////////////////////////////////////////////////////////
const int mx = 1e5+5;
vector<int> g[mx],vis(mx),in(mx),out(mx);
int timer = 0;
void printg(int n){
    for(int i=0;i<n;i++){
        print(g[i]);
    }
}
void resizeall(int n){
    vis.resize(n);
    in.resize(n);
    out.resize(n);
}
void dfs(int u){
    vis[u] = 1;
    in[u]= timer++;
    for(auto child : g[u] ){
        if(!vis[child]){
            dfs(child);
        }
    }
    out[u]=timer++;
}
bool checkDAG(int n){
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i);
        }
    }

    bool flag = false;
    vector<pair<int,int>> backEdge;
    for(int u= 0;u<n;u++){
        for(auto v:g[u]){
            if(out[u]<out[v]){
                flag = true;
                backEdge.push_back({u,v});

            }
        }
    }
    if(backEdge.size()){
        cout<<"Back Edges are -\n";
        for(auto x: backEdge)cout<<x.first<<"--->"<<x.second<<"\n";

    }
    return !flag;
}
int main ()
{
	// fastio

 	// int  t;
 	// cin>>t;
 	// while(t--)
 	{
	solve();

 	}
}
///////////////////////////////////////////
void solve()
{
	int n,i,d,a,b,c,j,k,m;
    cin>>n>>m;
    resizeall(n);
    for(i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);


    }
    if(checkDAG(n))cout<<"Yes graph is DAG\n";
    else cout<<"No graph is not DAG\n";



}
