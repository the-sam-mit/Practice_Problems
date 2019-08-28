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

int main(){
	int n;
	cin>>n;
	ll a[n+1], b[n+1], c[n+1];
	inp1(a,n);
	inp1(b,n);
	inp1(c,n);
	ll sum = 0, sum2 = 0;
	rep(i,1,n){
		ll na = a[i], nb = b[i], nc = c[i];
		ll xa[32]={0}, xb[32]={0}, xc[32]={0}, xd[32]={0}, fg = 1, ans[32]={0};
		mem(ans,0);
		sum2 += (a[i]^b[i]);
		nrep(j,0,30){
			xa[j] = na%2;
			xb[j] = nb%2;
			xc[j] = nc%2;
			na /= 2;
			nb /= 2;
			nc /= 2;
			if(xc[j] == 0) {
				xd[j] = 0; 
			}
			else{
				if(xa[j]^xb[j] == 0) xd[j] = 1;
				else xd[j] = 0;
				}
			}
		fg = 1;
		ll val = 0;
		nrep(j,0,30){
			val += (xd[j] * fg);
			fg *= 2;
		}
		if(val <= 0){
			fg = 1;
			nrep(j,0,30){
				if(xc[j] == 1){
					val = fg;
					break;
				}
				fg *= 2;
			}
		}
		
		sum += (a[i]^b[i]^val);
		
	}
		cout<<sum;
		rep(i,1,n){

		}
}
