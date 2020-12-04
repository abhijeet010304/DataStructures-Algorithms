#include<bits/stdc++.h>
using namespace std ;
	#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	#define lli long long int
	#define ulli unsigned long long int
	#define ff first
	#define ss second
	#define mp make_pair
	#define pb push_back
	#define pf pop_front()
	#define lb lower_bound
	#define ub upper_bound
	#define bs binary_search
	#define fo(i,a,b) for(lli i=a;i<b;i++)
	#define fop(i,a,b) for(lli i=a;i<=b;i++)
	#define all(v) v.begin(), v.end()
	#define mod 1000000007
	#define inf 100000000000000000
	#define lld long double
	#define pll pair<long long int,long long int>
	#define pii pair<int,int>
	#define vll vector<lli>
	#define vii vector<int>
	#define endl '\n'
	#define pie  acosl(-1.0);
	#define setp(k, x) fixed << setprecision(k) << (x)
	#define deb(x) cerr << #x << ": " << x << " " << endl;
	#define reach(x) cout << "m here-" <<#x<<" ..."<<"\n";
	#define printa(a,n) for(lli i=0;i<n;i++) cout<<a[i]<<" "; cout<<"\n";
  #define printv(a) for(lli i=0;i<a.size();i++) cout<<a[i]<<" "; cout<<"\n";
	bool sortcol( const vector<lli>& v1, const vector<lli>& v2 ) //sort on basis of column //use- sort(vect.begin(), vect.end(),sortcol);
      { return v1[1] < v2[1]; }//[] o based indexing in column
	bool sortpair(const pair<lli, lli> &a, const pair<lli, lli> &b)
			{return a.second < b.second;}
	struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
// if you want to use pair inside  unordered_map
struct hash_pair {
template <class T1, class T2>
size_t operator()(const pair<T1, T2>& p) const
{
	auto hash1 = hash<T1>{}(p.first);
	auto hash2 = hash<T2>{}(p.second);
	return hash1 ^ hash2;
}
};

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
////////////////////////////////////////////////////////////

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "debug.cpp"
#endif

/////////////////
/////////////////////////////////////////////////////////////////////////////
void solve(lli tt,lli n,lli m);
//////////////////////////////////////////////////////////////////////////////////////////////
bool vis[105][105];
int xx[] = { 0, 1,1,1,0,-1,-1,-1};
int yy[] = {-1,-1,0,1,1, 1, 0,-1};
int g[105][105]={0};

bool isvalid(int i,int j,int n,int m)
{
    return (i>=0 && i<n && j>=0 && j<m);
}
int  dfs(int i,int j,int n,int m,char c ,int count ){
    int dx,dy;
    vis[i][j] = true;
    if(g[i][j]+'A'!=c) return count;
    char ch = g[i][j]+'A';
    // debug(ch,i,j);
    int ans =  count +1;
    for(int k = 0;k<8;k++){
        dx = i+ xx[k];
        dy = j+ yy[k];
        // debug(dx,dy);

        if(isvalid(dx,dy,n,m) and !vis[dx][dy] and g[dx][dy]==c+1-'A'){

            int temp  = dfs(dx,dy,n,m,c+1,count+1);
            ans = max(ans,temp);
        }
    }
    // debug(ans);
    return ans ;
}

int main ()
{
	// fastio

 	lli  t,tt = 1,n,m;
 	// cin>>t;
    while(true){
        cin>>n>>m;

        if(n+m){
            solve(tt,n,m);
            tt++;
        }
        else break;
    }
}
///////////////////////////////////////////
void solve(lli tt,lli n, lli m)
{
	lli i,d,a,b,c,j,k;

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            char ch;
            cin>>ch;
            g[i][j]=ch-'A';

        }
    }

    int temp = 0,count = 0;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            temp = dfs(i,j,n,m,'A',0);
            memset(vis,false,sizeof(vis));
            count =max(count ,temp);
        }
        // cout<<"\n";
    }
    cout<<"Case "<<tt<<": ";
    cout<<count<<"\n";
    // cout<<"\n";








}
