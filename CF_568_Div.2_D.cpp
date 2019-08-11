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
#define M 1000000007
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
ll gcd(ll n1, ll n2){if(n2!=0) return gcd(n2, n1%n2); else return n1;}
ll power(ll a,ll b){if(b==0) return 1;  if(b==1) return a; ll x=power(a,b/2); if(b&1){return a*x*x;}return x*x;}


const ll INF=1e9; 
const int SIZE = 1e6;
int main(){
    ll n,k;
    cin>>n>>k;
    char s[2005][2005];
    rep(i,1,n){
        rep(j,1,n) cin>>s[i][j];
    }
    ll cnt = 0;
    ll sum[2005][2005];
    mem(sum, 0);
    rep(i,1,n){
        ll mx = 0, mn = n+1;
        rep(j,1,n){
            if(s[i][j]=='B'){
                mx = max(mx, j);
                mn = min(mn, j);
            }
        }
        if(mx == 0) {cnt++;continue;}
        if(mx - mn + 1 > k) continue;
        ll lx, ly, rx, ry;
        lx = max(1ll, i-k+1);
        ly = max(1ll, mx-k+1);
        rx = min(n-k+1, i)+1;
        ry = min(n-k+1, mn)+1;
        sum[lx][ly]++; sum[rx][ry]++; sum[lx][ry]--; sum[rx][ly]--;
    }

    rep(i,1,n){
        ll mx = 0, mn = n+1;
        rep(j,1,n){
            if(s[j][i]=='B'){
                mx = max(mx, j);
                mn = min(mn, j);
            }
        }
        if(mx == 0) {cnt++;continue;}
        if(mx - mn + 1 > k) continue;
        ll lx, ly, rx, ry;
        ly = max(1ll, i-k+1);
        lx = max(1ll, mx-k+1);
        ry = min(n-k+1, i)+1;
        rx = min(n-k+1, mn)+1;
        sum[lx][ly]++; sum[rx][ry]++; sum[lx][ry]--; sum[rx][ly]--;
    }
    ll ans = 0;
    rep(i,1,n){
        rep(j,1,n){
        
            sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
            // cout<<sum[i][j]<<" ";
            ans = max(sum[i][j], ans);
        }
        cout<<endl;
    }
    cout<<ans+cnt<<endl;
}
