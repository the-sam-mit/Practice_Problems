#include<bits/stdc++.h>
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
#define sz(a) (int)a.size()
#define endl "\n"
#define all(v) v.begin(), v.end()
#define mem(arr,val) memset(arr,val,sizeof(arr)) //For "0" and "-1"                  
#define inp0(a,n) rep(i,0,n-1) cin>>a[i];
#define inp1(a,n) rep(i,1,n) cin>>a[i]; 
#define prll(x) printf("%lld",x)
#define nth_ele(v,n) nth_element(v.begin(), v.begin()+n ,v.end())//O(N)
#define M 1000000007

typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
ll gcd(ll n1, ll n2){if(n2!=0) return gcd(n2, n1%n2); else return n1;}
ll power(ll a,ll b){if(b==0) return 1;	if(b==1) return a; ll x=power(a,b/2); if(b&1){return a*x*x;}return x*x;}

const ll PINF = numeric_limits<ll>::max();
const ll NINF = numeric_limits<ll>::min();
const int SIZE = 200005;
ll aa,bb;

ll n1=32027,n2=32001;

int main() {
	// #ifndef ONLINE_JUDGE
  	//   freopen("input.txt", "r", stdin);
  	//   freopen("output.txt", "w", stdout);
	// #endif
	testcase(t){
		ll x=n1*n1,y=n2*n2,a,b;
		cout<<"1 32027\n";
		flush(cout);
		cin>>aa;
		if(aa==-1) return 0;
		a=x-aa;
		
		cout<<"1 32001\n";
		flush(cout);
		cin>>bb;
		if(bb==-1) return 0;
		b=y-bb;
		
		ll g=__gcd(a,b);
		vector<ll> v;
		if(g%2==0){
			v.pb(2);
			while(g%2==0) g/=2;
		}
		for(ll i=3;i<=sqrt(g);i+=2){
			if(g%i==0){
				v.pb(i);
				while(g%i==0){
					g/=i;
				}		
			}
		}
	    if(g>2) {v.pb(g);}
		rep(i,0,sz(v)-1){
			ll p=v[i];
			if(x%p==aa && y%p==bb){
				cout<<"2 "<<p<<endl;
				flush(cout);
				break;
			}
		}
		
		string s;
		cin>>s;
		if(s=="No") return 0;
	}	
}
