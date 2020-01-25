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
#define UNIQUE(x) x.resize(distance(x.begin(), unique(all(x))))
#define mem(arr,val) memset(arr,val,sizeof(arr)) //For "0" and "-1"                  
#define inp0(a,n) rep(i,0,n-1) cin>>a[i];
#define inp1(a,n) rep(i,1,n) cin>>a[i]; 
#define prll(x) printf("%lld",x)
#define nth_ele(v,n) nth_element(v.begin(), v.begin()+n ,v.end())//O(N)
#define DEBUG(x) cerr << (#x) << ": " << (x) << endl
#define DEBUGV(x) for(auto IT:x) cout<<IT<<" "; cout<<endl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
ll gcd(ll n1, ll n2){if(n2!=0) return gcd(n2, n1%n2);else return n1;}
ll powerM(ll a,ll b){if(b==0) return 1;  if(b==1) return a%M; ll x=powerM(a,b/2)%M; if(b&1){return ((((a%M)*(x%M))%M)*(x%M))%M;}return ((x%M)*(x%M))%M;}
ll power(ll a,ll b){if(b==0) return 1;  if(b==1) return a; ll x=power(a,b/2); if(b&1){return ((((a)*(x)))*(x));}return ((x)*(x));}
 
const ll INF=1e18; 
const int SIZE = 100005;

int main(){
    testcase(T){
        ll n,m,w,h;
        cin>>n>>m>>w>>h;
        string s;
        cin>>s;
        vector<pair<double,double>> v;
        rep(i,1,m){
            ll x,y;
            cin>>x>>y;
            v.pb(mp(x,y));
        }
        double ans=INT_MAX;
        rep(i,0,m-2){
            rep(j,i+1,m-1){
                double x1=v[i].ff;
                double y1=v[i].ss;
                double x2=v[j].ff;
                double y2=v[j].ss;
                double dist = (double)sqrt(abs(x2-x1)*abs(x2-x1) + abs(y2-y1)*abs(y2-y1));
                ans=min(ans, dist);
            }
        }
        int U=0, L=0, R=0, D=0;
        rep(i,0,n-1){
            if(s[i]=='U') U++;
            if(s[i]=='D') D++;
            if(s[i]=='L') L++;
            if(s[i]=='R') R++;
        }
        if(U||D>1){
            rep(i,0,m-1){
                ans=min(ans, (double)(h-v[i].ss)*2.0);
            }            
        }
        if(D||U>1){
            rep(i,0,m-1){
                ans=min(ans, (double)(v[i].ss)*2.0);
            }
        }
        if(L||R>1){
            rep(i,0,m-1){
                ans=min(ans, (double)(v[i].ff)*2.0);
            }
        }
        if(R||L>1){
            rep(i,0,m-1){
                ans=min(ans, (double)(w-v[i].ff)*2.0);
            }
        }
        cout<<fixed<<SP(12)<<ans<<endl;
    }
}
