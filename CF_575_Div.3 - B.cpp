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
ll power(ll a,ll b){if(b==0) return 1;	if(b==1) return a%M; ll x=power(a,b/2)%M; if(b&1){return (a*((x*x)%M))%M;}return (x*x)%M;}
 
const ll INF=1e18; 
const int SIZE = 100005;
 
int main(){
	testcase(t){
		int n,k;
		cin>>n>>k;
		ll a[n+1];
		inp1(a,n)
		ll sum[n+1];
		mem(sum,0);
		rep(i,1,n){
			sum[i]+=sum[i-1]+a[i];
		}
		bool flag=true;
		if(k%2==0 && sum[n]%2==1){
			flag=false;
		}
		else if(k%2==1 && sum[n]%2==0){
			flag=false;
		}
		if(flag==false){
			cout<<"NO\n";
			continue;
		}
		int kk=k;
		int i=1;
		int x=1;
		vector<ll> ans;
		ans.clear();
		if(k==1 && sum[n]%2==1){
			cout<<"YES\n";
			cout<<n<<endl;
			continue;
		}
		while(i<=n && k-1>0){
			if(sum[i]%2==1 && x==1){
				ans.pb(i);
				x=x^1;
			}
			else if(sum[i]%2==0 && x==0){
				ans.pb(i);
				x=x^1;	
			}
			if(sz(ans)==k-1) break;
			i++;
		}
		if((sum[n]-sum[i])%2==1) ans.pb(n);
		if(sz(ans)==kk){
			cout<<"YES\n";
			for(auto it:ans) cout<<it<<" ";
				cout<<endl;
		}
		else cout<<"NO\n";
	}
} 
