#include<bits/stdc++.h>
#include "debug.cpp"
using namespace std;
const int mx= 1e5+5;
vector<int> g[mx],rev[mx];
void printg(int n){
    for(int i=0;i<n;i++){
        print(g[i]);
    }

}
void DFS1(int u ,stack<int>& mystack,vector<bool> &vis){
    vis[u]=true;
    for(auto v:g[u]){
        if(!vis[v]){
            DFS1(v,mystack,vis);
        }
    }
    mystack.push(u);
}
void reverseEdge(int n){
    for(int u=0;u<n;u++){
        for(auto v:g[u]){
            rev[v].push_back(u);
        }
    }
}
void DFS2(int u,vector<bool>& vis){
    cout<<u<<" ";
    vis[u]=true;
    for(auto v:rev[u]){
        if(!vis[v]){
            DFS2(v,vis);
        }
    }

}
void kosarajuSCC(int n){
    stack<int> mystack;
    vector<bool> vis(n,false);
    for(int i=0;i<n;i++){
        if(vis[i]==false){
            DFS1(i,mystack,vis );
        }
    }

    reverseEdge(n);
    for(int i=0;i<n;i++){
        vis[i]=false;
    }
    cout<<"Stongly Connected Components are - : \n";
    while(mystack.size()>0){
        int current= mystack.top();
        mystack.pop();
        if(!vis[current]){
            DFS2(current,vis);
            cout<<"\n";
        }

    }
}
int main(){
    int n,m,i;
    cin>>n>>m;
    for(i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
    }
    kosarajuSCC(n);


    return 0;
}
