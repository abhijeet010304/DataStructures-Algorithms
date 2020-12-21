#include<bits/stdc++.h>
using namespace std;
const int mx = 1e5;
struct node{
    int s,d,w;
};
vector<node> edges(mx);
vector<int> parent(mx,-1),rankk(mx,0);
class comp{
    public:
    bool operator()(node &a,node &b){
        if(a.w<b.w)return true;
        else return false;
    }
};
int findDSU(int a){
    if(parent[a]==-1)return a;
    return parent[a] = findDSU(parent[a]);

}
void unionDSU(int from,int to){
    // from = findDSU(from);
    // to = findDSU(to);
    // parent[from] = to;
    //by path compression and union by rank

    if(rankk[from]>rankk[to]){
        parent[to] = from;
    }
    else if(rankk[from]<rankk[to]){
        parent[from] = to ;

    }
    else{
        parent[from] = to;
        rankk[to]++;
    }


}


void kruskalMST(vector<node>edges,int n ){
    sort(edges.begin(),edges.end(),comp());
    cout<<"edges"<<":\n";
    for(auto x: edges){
        cout<<x.s<<" "<<x.d<<" "<<x.w<<"\n";
    }
    int count =0 ;
    vector<node> MST;
    for(int i =0;i<edges.size();i++){
        int u = edges[i].s;
        int v = edges[i].d;
        int w = edges[i].w;

        int parentOfu = findDSU(u);
        int parentofv = findDSU(v);

        if(parentOfu!=parentofv){
            unionDSU(parentOfu,parentofv);
            count++;
            MST.push_back({u,v,w});
        }

        if(count == n-1)break;
    }
    cout<<"MST:\n";
    for(auto x:MST){
        cout<<x.s<<" "<<x.d<<" "<<x.w<<"\n";
    }
}
int main(){

    int n,m,i;
    cin>>n>>m;
    edges.resize(m);
    parent.resize(n);
    rankk.resize(n);
    for(i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges[i] = {u,v,w};
        
    }
    // cout<<"edges"<<":\n";
    // for(auto x: edges){
    //     cout<<x.s<<" "<<x.d<<" "<<x.w<<"\n";
    // }
    kruskalMST(edges,n);
    return 0 ;

}
