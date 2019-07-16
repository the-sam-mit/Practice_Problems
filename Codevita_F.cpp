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
ll power(ll a,ll b){if(b==0) return 1;  if(b==1) return a; ll x=power(a,b/2); if(b&1){return a*x*x;}return x*x;}

ll DP[1000001][2];
ll countWays(ll n, ll chk) 
{ 
    DP[0][0] = DP[1][0] = 1;DP[2][0] = 2; 
    DP[0][1]=DP[1][1]=1;DP[2][1]=2;
    DP[3][1]=3;DP[3][0]=4;
    for (ll i = 4; i <= n; i++)  {
            DP[i][0] = (DP[i - 1][0] + DP[i - 2][0] + DP[i-3][1])%M;
             DP[i][1]=(DP[i-1][1]+DP[i-2][1])%M;
    } 
      
    return DP[n][0]%M; 
} 
   
int main() 
{ 
    ll n ;
    cin>>n;
    mem(DP,0); 
    cout << countWays(n,0)<<endl; 
    return 0; 
} 