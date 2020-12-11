#include<bits/stdc++.h>
#include"debug.cpp"
using namespace std;
const int mx = 1e5+5;
vector<int> parent(mx,-1);
vector<pair<int,int>> edges;


int find(int v){
    if(parent[v]==-1)return v;
    return find(parent[v]);
}

void unionDSU(int from,int to){
    from = find(from);
    to = find(to);
    parent[from]  = to;
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
    parent.resize(v);

    for(int i=0;i<e;i++){
        int from,to;
        cin>>from>>to;
        edges.push_back({from,to});

    }
    if(isCyclic(v))cout<<"yes\n";
    else cout<<"No\n";

    return 0;
}
