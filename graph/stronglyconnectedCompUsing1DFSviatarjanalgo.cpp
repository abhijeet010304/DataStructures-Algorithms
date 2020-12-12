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

void DFS(int u , vector<int> &in,vector<int> &low,stack<int> &mystack, vector<bool> &parentInStack){
    static int time = 0;
    in[u] = low[u] = time ;
    time++;
    mystack.push(u);
    parentInStack[u]=true;

    //perform DFScheck
    for(auto v: g[u]){
        if(in[v]==-1){//v is not visited
            DFS(v,in,low,mystack,parentInStack);
            /*
                when we backtrack then we minimise the parent using child's low time
                perform this for all child
            */
            low[u] = min(low[u],low[v]);

        }
        else if(parentInStack[v]){
            //child is already visited case 
            //if parent is in stack and the child is already
                                    //visited then it is a back edge
                                    //and we minimise the low time of parent  using discovery time of child
                                    //we just ignore in case of Cross egde
            low[u] = min(low[u],in[v]);
        }
    }

    // after traversing all the outgoing edges we check for the head
    // ie can the current node U become the head or not
    // conditon for head is low[node]==in[node]
    if(low[u]==in[u]){
        debug(u);
        cout<<"SCC is: ";
        while(mystack.top()!=u){//pop all the elements till we reach the current head
            cout<<mystack.top()<<" ";

            parentInStack[mystack.top()] = false;
            mystack.pop();

        }
        cout<<mystack.top()<<"\n";
        parentInStack[mystack.top()] = false;
        mystack.pop();

    }


}

void findSCC_Tarjan(int n){
    vector<int> in(n,-1),low(n,-1);
    vector<bool> parentInStack(n,false);
    stack<int> mystack;

    for(int i=0;i<n;i++){
        if(in[i]==-1){
            DFS(i,in,low,mystack,parentInStack);
        }
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
        // g[v].push_back(u);

    }
    findSCC_Tarjan(n);



}
