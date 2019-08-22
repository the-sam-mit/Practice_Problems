#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include<bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define ff first 
#define ss second
#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define start_routine() int begtime = clock();
#define end_routine() int endtime = clock(); \
                      cerr << "\n\n" << "Time elapsed: " << \
                      (endtime - begtime)*1000/CLOCKS_PER_SEC << " ms\n\n"; \
                      return 0
#define testcase(t) int t;cin>>t;while(t--)
#define mp(x,y) make_pair(x,y)
#define in(x) insert(x)
#define rep(i,a,b)  for (__typeof((b)) i=(a);i<=(b);i++)
#define nrep(i,a,b)  for (__typeof((b)) i=(b);i>=(a);i--)
#define PI 3.14159265358979323846
#define SP(x) setprecision(x)
#define reflex ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define M 998244853
#define sz(a) (int)a.size()
#define endl "\n"
#define all(v) v.begin(), v.end()
#define mem(arr,val) memset(arr,val,sizeof(arr)) //For "0" and "-1"                  
#define inp0(a,n) rep(i,0,n-1) cin>>a[i];
#define inp1(a,n) rep(i,1,n) cin>>a[i]; 
#define prll(x) printf("%lld",x)
#define nth_ele(v,n) nth_element(v.begin(), v.begin()+n ,v.end())//O(N)
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
ll gcd(ll n1, ll n2){if(n2!=0) return gcd(n2, n1%n2);else return n1;}
ll powerM(ll a,ll b){if(b==0) return 1;  if(b==1) return a%M; ll x=powerM(a,b/2)%M; if(b&1){return ((((a%M)*(x%M))%M)*(x%M))%M;}return ((x%M)*(x%M))%M;}
ll power(ll a,ll b){if(b==0) return 1;  if(b==1) return a; ll x=power(a,b/2); if(b&1){return ((((a)*(x)))*(x));}return ((x)*(x));}
 

 
const ll INF=1e18; 
const int SIZE = 100005;
ll n,m,k;
vector<int> v[SIZE];
int ct[SIZE], vis[SIZE];
vector<int> cyc;

int dfs(int x, int par, int time){
    if(vis[x]==1){
        if(abs(time-ct[x])>k) return 1;
        else return 0;
    }
    vis[x]=1;
    ct[x]=time;
    int st=0;
    for(auto it:v[x]){
      if(it==par) continue;
      int y = dfs(it, x, time+1);
      st = st|y;
      if(st==1){
        cyc.pb(it);
        break;
      }
    }
    return st;
}



int main(){
    cin>>n>>m>>k;
    int a,b;
    rep(i,1,m){
      cin>>a>>b;
      v[a].pb(b);
      v[b].pb(a);
    }
    dfs(1,-1,1);
    set<int> s;
    for(auto it:cyc){
      if(s.find(it)!=s.end()){
        break;
      }
      s.in(it);
    }
    cout<<sz(s)<<endl;
    s.clear();
    for(auto it:cyc){
      if(s.find(it)!=s.end()){
        break;
      }
      cout<<it<<" ";
      s.in(it);
    }
    cout<<endl;
}
