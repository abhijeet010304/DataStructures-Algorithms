#include<bits/stdc++.h>
#include "debug.cpp"
using namespace std;
int xx[]={2,2,1,-1,-2,-2,-1,1};
int yy[]={1,-1,-2,-2,-1,1,2,2};

bool isvalid(int i,int j){
    if(i>=0 and j>=0 and i<=7 and j<=7)return true;
    else return false;
}

struct node{
    int x,y,dist;
};
int findMinStep(int x1,int y1,int x2,int y2){
    set<pair<int,int>> vis;
    queue<node> que;
    node source = {x1,y1,0};
    node dest = {x2,y2,0};
    que.push(source);
    while(que.size()>0){
        node temp = que.front();
        que.pop();
        int tempx = temp.x,tempy = temp.y,tempdist = temp.dist;
        if(tempx == dest.x and tempy ==dest.y)return temp.dist;

        if(!vis.count({tempx,tempy})){
            vis.insert({tempx,tempy});
            for(int i=0;i<8;i++){
                int checkx = tempx + xx[i];
                int checky = tempy + yy[i];
                if(isvalid(checkx,checky)){
                    
                    que.push({checkx,checky,tempdist+1});
                }
            }
        }
    }
    return INT_MAX;
}

int main(){
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;

    int minStep =findMinStep(x1,y1,x2,y2);
    cout<<minStep<<"\n";

    return 0;
}
