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
ll power(ll a,ll b){if(b==0) return 1;	if(b==1) return a; ll x=power(a,b/2); if(b&1){return a*x*x;}return x*x;}

const int SIZE = 100005;

//The MOD func plays a major role in this problem!!

ll mod(ll x, ll n){
	if(x<n) return x;
	else return x-n;
}

ll dp[405][405],sum[405][405];

ll func(ll i, ll j, ll n){
	if(dp[i][j]!=-1) return dp[i][j];
	if(i==j) return dp[i][j]=0;
	if(mod(i+1,n)==j) return dp[i][j]=sum[i][j];
	ll res=1e18;
	for(int p=i;p!=j;p=mod(p+1,n)){
		res=min(res,func(i,mod(p,n),n)+func(mod(p+1,n),j,n)+sum[i][j]);
	}
	return dp[i][j]=res;
}

int main() {
	// #ifndef ONLINE_JUDGE
  	//   freopen("input.txt", "r", stdin);
  	//   freopen("output.txt", "w", stdout);
	// #endif
	reflex;
	testcase(t){
		mem(dp,-1);
		int n;
		cin>>n;
		ll a[n];
		inp0(a,n)
		rep(i,0,n-1){
			sum[i][i]=a[i];
			rep(j,1,n-1){
				sum[i][mod(i+j,n)]=sum[i][mod(mod(j+i-1+n,n),n)]+a[mod(i+j,n)];
				// cout<<sum[i][j]<<" ";
			}
			// cout<<endl;
		}
		ll ans=1e18;
		rep(i,0,n-1){
			  ans=min(ans,func(mod(i,n),mod(mod(i+n-1,n),n),n));
		}
		cout<<ans<<endl;
	}	
}
