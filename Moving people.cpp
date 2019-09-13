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
const int SIZE = 1000005;
ll mat[1002][1002], tot[1002][1002];
char ch;
int main(){
    mem(mat, 0);
    int q,n,m;
    cin>>n>>m>>q;
    rep(i,1,n){
        rep(j,1,m) {cin>>ch;mat[i][j]=ch-'0';}
    }
    mem(tot, 0);
    rep(i,1,n){
        rep(j,1,m){
            tot[i][j] = mat[i][j] + tot[i-1][j] + tot[i][j-1] - tot[i-1][j-1];
        }
    }
    ll l=1,r=m,u=1,d=n;
    ll tr=m, tl=1, tu=1, td=n;
    while(q--){
        int a,x,y;
        cin>>a;
        if(a==1){
            cin>>x>>y;
            l += x;
            r += x;
            u += y;
            d += y;
            tr = min(tr, r);
            tl = max(tl, l);
            tu = max(tu, u);
            td = min(td, d);  
        }
        else{
            ll ans = 0;
            if(tu>td || tl>tr){
                cout<<0<<endl;
                continue;
            }
            ans = tot[td][tr] - tot[tu-1][tr] - tot[td][tl-1] + tot[tu-1][tl-1];
            cout<<max(ans, 0ll)<<endl;
        }
    }
}

