#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define ff first 
#define ss second
#define pb(x) push_back(x)
#define pf(x) push_front(x)
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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
ll gcd(ll n1, ll n2){if(n2!=0) return gcd(n2, n1%n2); else return n1;}
ll power(ll a,ll b){if(b==0) return 1;	if(b==1) return a; ll x=power(a,b/2); if(b&1){return a*x*x;}return x*x;}

const int SIZE = 200005;


 

int main() {
	// #ifndef ONLINE_JUDGE
  	//   freopen("input.txt", "r", stdin);
  	//   freopen("output.txt", "w", stdout);
	// #endif
	ll n,t;
	cin>>n>>t;
	ll a[n+1][t+2];
	ll dis[n+1][t+2];
	mem(dis,0);
	rep(i,1,n){
		rep(j,1,t){
			cin>>a[i][j];
		}
		cin>>a[i][t+1];
	}
	rep(i,1,n){
		rep(j,1,t){
			dis[i][j]=a[i][j]*a[i][t+1];
		}
	}
	rep(i,1,n){
		rep(j,1,t){
			dis[i][j]+=dis[i][j-1];
			// cout<<dis[i][j]<<" ";
		}
		// cout<<endl;
	}
	map<ll,ll> ms;
	for(int j=2;j<=t-1;j++){
		ll mx=0,pos=0;
		rep(i,1,n){
			mx=max(mx,a[i][j]);
		}
		rep(i,1,n){
			if(mx==a[i][j]) ms[i]++;
		}
	}
	int ans=ms.begin()->ss,pp=ms.begin()->ff;
	for(auto it:ms){
		if(ans<it.ss){
			pp=it.ff;
			ans=it.ss;
		}
	}
	cout<<pp<<endl;
}
