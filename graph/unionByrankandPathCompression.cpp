#include<bits/stdc++.h>
#include"debug.cpp"
using namespace std;
const int mx = 1e5+5;

struct node{
    int parent;
    int rank;
};
vector<pair<int,int>> edges;
vector<node> dsu;


int find(int v){
    if(dsu[v].parent==-1)return v;
    return dsu[v].parent = find(dsu[v].parent);
}

void unionDSU(int from,int to){

    // from = find(from);
    // to = find(to);
    // parent[from]  = to;

    if(dsu[from].rank>dsu[to].rank){ // from AP has higher rank so from will become parent of to
        dsu[to].parent = from;
    }
    else if(dsu[from].rank<dsu[to].rank){ //to AP has higher rank so to will become the parent of from
        dsu[from].parent = to;
    }
    else{
        dsu[from].parent = to;
        dsu[to].rank +=1 ; // same rank so any will become parent and rank will increase
    }

}
bool isCyclic(int n){

    for(auto u : edges){
        int from = find(u.first);
        int to = find(u.second);

        if(from == to) return true;
        // parent[from] = to;
        unionDSU(from,to); //useless here we can directly assign parent[from] = to or parent[to] = from
    }


    return false;

}

int main(){

    int v,e;
    cin>>v>>e;
    dsu.resize(v);
    for(int i=0;i<v;i++){
        dsu[i].parent = -1;
        dsu[i].rank = 0;


    }

    for(int i=0;i<e;i++){
        int from,to;
        cin>>from>>to;
        edges.push_back({from,to});

    }
    if(isCyclic(v))cout<<"yes\n";
    else cout<<"No\n";

    return 0;
}
