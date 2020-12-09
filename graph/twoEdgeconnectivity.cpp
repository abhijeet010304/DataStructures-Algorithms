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
vector<int> g[mx],vis(mx),out(mx);
void printg(int n){
    for(int i=0;i<n;i++){
        print(g[i]);
    }
}
void resizeall(int n){
    vis.resize(n);

    out.resize(n);
}

void DFS(int u , vector<int> &in,vector<int> &low,vector<int> &parent, vector<pair<int,int>> &bridges){
    static int time = 0;
    in[u] = low[u] = time++;
    for(auto v:g[u]){
        if(in[v]==-1){
            parent[v]= u;
            DFS(v,in,low,parent,bridges);// after backtrack update the low time of u
            low[u] = min(low[u],low[v]);

            if(low[v]>in[u]){                   // check for bridge of edge u->v
                bridges.push_back({u,v});
            }
        }
        else if(v!=parent[u]){
            low[u] = min(low[u],in[v]); //back edge case  ---> low[node] = min(low[node],disc[child]);

        }
    }
}

void findBridge_Tarjan(int n){
    vector<int> in(n,-1),low(n,-1),parent(n,-1);
    vector<pair<int,int>> bridges;

    for(int i=0;i<n;i++){
        if(in[i]==-1){
            DFS(i,in,low,parent,bridges);
        }
    }

    cout<<"bridges are -\n";
    for(auto x: bridges){
        cout<<x.first<<" ---> "<<x.second<<"\n";
    }
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
        g[v].push_back(u);

    }
    findBridge_Tarjan(n);



}
