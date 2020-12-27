#include<bits/stdc++.h>
#include"debug.cpp"
using namespace std;
#define pb push_back
const int mx = 1e5+5;
struct edge{
    int s,d,w;
};
struct node{
    int source,weight;
};
vector<pair<int,int>> g[mx];
void printg(int n){
    for(int i=0;i<n;i++){
        print(g[i]);
    }
}
void printEdge(vector<edge> edges,int n){
    for(int i=0;i<edges.size();i++){
        cout<<edges[i].s<<" "<<edges[i].d<<" "<<edges[i].w<<"\n";
    }
}
void printPath(vector<int> parent,int u){
    if(u<0)return;
    // debug("wegwe");
    printPath(parent, parent[u]);
    cout<<u<<" ";
}
void bellmanFord(vector<edge> edges,int n,int source){
    int i;
    int inf = INT_MAX;
    vector<int> dist(n,inf),parent(n,-1);
    dist[source] = 0;
    parent[source] = -1;
    bool nextrelaxationneeded = false;
    for(i=0;i<n-1;i++){
        nextrelaxationneeded = false;
        for(int j=0;j<edges.size();j++){
            int u,v,w;
            u = edges[j].s;
            v = edges[j].d;
            w = edges[j].w;
            if(dist[u]!=inf and dist[u]+w<dist[v]){// important point is here that initial  dist[u]!=inf  other wise you will get segmentation fault
                parent[v] = u;
                dist[v] = dist[u]+w;
                nextrelaxationneeded = true;
            }
        }
        if(nextrelaxationneeded==false){
            // debug(i);//if no further relaxation can be done
            break;
        }
    }
    bool negativeCycle = false;
    for(i=0;i<edges.size();i++){
        int u,v,w;
        u = edges[i].s;
        v = edges[i].d;
        w = edges[i].w;
        if(dist[u]+w<dist[v]){
            negativeCycle = true;
        }
    }
    if(negativeCycle){
        cout<<"negative Cycle present\n";
    }
    else{
        print(parent);
        for(i=0;i<n;i++){
            
            cout<<source<<" to node "<<i<<" - ";
            cout<<dist[i]<<" path : ";
            printPath(parent,i);
            cout<<"\n";
        }

    }


}
int main(){
    int n,m,i;
    cin>>n>>m;
    vector<edge> edges;
    for(i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.pb({u,v,w});
        g[u].pb({v,w});
    }
    // printEdge(edges,n);
    // printg(n);
    cout<<"source:\n";
    int u;
    cin>>u;
    bellmanFord(edges,n,u);
    return 0;
}
