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
vector<int> g[mx],vis(mx),inDeg(mx),out(mx),topoSort;
int timer = 0;
void printg(int n){
    for(int i=0;i<n;i++){
        print(g[i]);
    }
}
void resizeall(int n){
    vis.resize(n);
    inDeg.resize(n);
    out.resize(n);
    topoSort.clear();
}
void kahntoposort(int n){
    queue<int> q;
    vector<int> kahnsort;
    for(int i=0;i<n;i++){
        if(inDeg[i]==0){
            q.push(i);
        }
    }

    while(q.size()>0){
        kahnsort.push_back(q.front());
        for(auto x : g[q.front()]){
            inDeg[x]--;
            if(inDeg[x]==0){
                q.push(x);
            }
        }
        q.pop();
    }
    int flag = 0;
    for(int i=0;i<n;i++){
        if(inDeg[i])flag = 1;

    }
    if(flag)cout<<"Contains cycle\n";
    else {
        cout<<"Output - ";
        print(kahnsort);
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
        inDeg[v]++;
        // g[v].push_back(u);

    }
    print(inDeg);

    kahntoposort(n);






}
