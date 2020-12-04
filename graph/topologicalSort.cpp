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
vector<int> g[mx],vis(mx),in(mx),out(mx),topoSort;
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
    topoSort.clear();
}
void dfs(int u){
    vis[u] = 1;

    in[u]= timer++;
    for(auto child : g[u] ){
        if(!vis[child])
            dfs(child);
    }
    topoSort.push_back(u);
    out[u]=timer++;

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
        // g[v].push_back(u);

    }
     printg(n);
     int flag = 0;
     for(i=0;i<n;i++){
         if(!vis[i]){
             dfs(i);
         }
     }
     reverse(topoSort.begin(),topoSort.end());
     print(topoSort);





}
