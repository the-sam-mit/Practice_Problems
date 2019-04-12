//DFS
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define ff first 
#define ss second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define in(x) insert(x)
#define rep(i,a,b)  for (__typeof((b)) i=(a);i<=(b);i++)
#define nrep(i,a,b)  for (__typeof((b)) i=(b);i>=(a);i--)
#define ffor(i,a,b) for(int i=a;i<b;i++)
#define bfor(i,a,b) for(int i=a;i>=b;i--)
#define PI 3.14159265358979323846
#define SP(x) setprecision(x)
#define reflex ios_base::sync_with_stdio(false);cin.tie(NULL)


ll X=0;
vector <ll> v[100000+2];
ll val[100000+2];
int vis[100000+2]={0};

void dfs(ll x){
    vis[x]=1;
    for(int i=0;i<v[x].size();i++){
        if(vis[v[x][i]]==0){
            vis[v[x][i]]=1;
            dfs(v[x][i]);
            //cout<<val[v[x][i]]<<endl;
            val[x]+=val[v[x][i]];
            
        }
    }
    if(val[x] < -X) val[x]=-X;
    
}

int main(){
    reflex;
    int t;
    cin>>t;
    while(t--){
        ll n,a,b;
        cin>>n>>X;
        rep(i,1,n){
            cin>>val[i];
        }
        for(int i=0;i<n-1;i++){
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        vis[1]=1;
        dfs(1);
        cout<<val[1]<<endl;
        rep(i,1,100000){
            vis[i]=0,val[i]=0;v[i].clear();
        }
    }
}
