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
const int SIZE = 1e7+2;

ll bit[SIZE];

void update(ll val, ll ind, ll n){
	ll i=ind;
	while(i <= n){
		bit[i] += val;
		i += (i&(-i));
	}
}

ll query(ll idx, ll n){
	ll sum = 0;
	ll i = idx;
	while(i>0){
		sum += bit[i];
		i -= (i&(-i));
	}
	return sum;
}

int main(){
	testcase(t){
		ll n;
		cin>>n;
		ll a[n+1];
		mem(bit, 0);
		inp1(a,n)
		ll ans = 0;
		nrep(i,1,n){
			ans += query(a[i]-1,SIZE-1);
			update(1, a[i], SIZE-1);
		}
		cout<<ans<<endl;	
	}
	
		
}

