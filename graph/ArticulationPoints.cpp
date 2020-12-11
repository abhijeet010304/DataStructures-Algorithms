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

void DFS(int u , vector<int> &in,vector<int> &low,vector<int> &parent, vector<bool> &AP){
    static int time = 0;
    in[u] = low[u] = time;
    time++;
    int totalChild = 0;
    for(auto v:g[u]){
        if(in[v]==-1){
            totalChild+=1;
            parent[v]= u;
            DFS(v,in,low,parent,AP);
            low[u] = min(low[u],low[v]);

            if(parent[u]==-1 and totalChild>1){  //case 1 --> u is root
                AP[u] = true;
            }

            if(parent[u]!=-1 and low[v]>=in[u]){ //case -2 --> atleast 1 component will get seperated
                AP[u]= true;
            }
        }
        else if(v!=parent[u]){
            low[u] = min(low[u],in[v]);

        }
    }
}

void findAP_Tarjan(int n){
    vector<int> in(n,-1),low(n,-1),parent(n,-1);
    vector<bool> AP(n,false);

    for(int i=0;i<n;i++){
        if(in[i]==-1){
            DFS(i,in,low,parent,AP);
        }
    }

    cout<<"APs are -\n";
    for(int i=0;i<n;i++){
        if(AP[i])cout<<i<<" ";
    }
    cout<<"\n";
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
    findAP_Tarjan(n);



}
