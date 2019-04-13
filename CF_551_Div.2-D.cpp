// DFS and Similar
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define ff first 
#define ss second
#define pb(x) push_back(x)
#define testcase(t) int t;cin>>t;while(t--)
#define mp(x,y) make_pair(x,y)
#define in(x) insert(x)
#define rep(i,a,b)  for (__typeof((b)) i=(a);i<=(b);i++)
#define nrep(i,a,b)  for (__typeof((b)) i=(b);i>=(a);i--)
#define PI 3.14159265358979323846
#define SP(x) setprecision(x)
#define reflex ios_base::sync_with_stdio(false);cin.tie(NULL)

vector <int> v[300000+5];
int val[300000+5];

int dfs(int x){
    if(v[x].size() == 0) return 1;
    int rank = 0;
    if(val[x] == 1) rank=INT_MAX;

    rep(i,0,(int)v[x].size()-1){
        int z = dfs(v[x][i]);
        if(val[x] == 1) rank = min(rank, z);
        else rank += z;
    }
    return rank;
}

int main(){
    reflex;
    int n,a,b;
    cin>>n;
    rep(i,1,n) cin>>val[i];
    rep(i,2,n) {cin>>a;v[a].pb(i);}
   
    
    int c=0;
    for(int i=1;i<=n;i++){
        if(v[i].size()==0)
        c++;
    }

    cout<<c-dfs(1)+1<<endl;
}
