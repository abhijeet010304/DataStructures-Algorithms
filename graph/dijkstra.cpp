#include<bits/stdc++.h>
using namespace std;
#include"debug.cpp"
#define pb push_back
#define inf INT_MAX
const int mx = 1e5+4;
vector<pair<int,int>> g[mx];
struct edge{
    int s,d,w;
};
struct node{
    int source,weight;
};
void printg(int n ){
    for(int i = 0;i<n;i++){
        print(g[i]);
    }
}
void printRoute( std::vector<int> path,int i){
    if(path[i]<0) return;
    printRoute(path,path[i]);
    cout<<i<<" ";
}
class comp{
public:
    bool operator()(node &l,node &r){
        return (l.weight>r.weight);
    }

};
void dijkstraSP(int n , vector<edge> edges,int u){

    vector<int> dist(n,inf);
    vector<bool> vis(n,false);

    priority_queue<node,vector<node>,comp> q;
    dist[u] = 0;
    q.push({u,0});
    vector<int> path(n,-1);
    while(q.size()>0){
        int proNode = q.top().source;
        int proWeight = q.top().weight;
        debug(proNode,proWeight);
        q.pop();
        for(auto child : g[proNode]){
            if(!vis[child.first] and (proWeight+child.second)<dist[child.first] ){
                dist[child.first] = proWeight+child.second;
                q.push({child.first,dist[child.first]});
                path[child.first] = proNode;
            }
        }

        vis[proNode] = true;
    }

    for(int i =0;i<n;i++){
        cout<<"from : "<<u<<" to : "<<i<<" weight: "<<dist[i]<<" Path-->";
        printRoute(path,i);
        cout<<"\n";
    }
    cout<<"\n";
}
int main(){
    vector<edge> edges;
    int n ,m,i;
    cin>>n>>m;
    // g.resize(n);
    for(i=0;i<m;i++){
        int u,v,we;
        cin>>u>>v>>we;
        edges.pb({u,v,we});
        g[u].pb({v,we});
        // g[v].pb({u,we});

    }
    int u;
    cin>>u;
    dijkstraSP(n,edges,u);

    return 0;
}
