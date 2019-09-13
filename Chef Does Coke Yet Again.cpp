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
const int SIZE = 100005;
const int SSIZE = 1000005;

ll arr[SIZE], tr[4*SIZE];

void build(int start, int end, int node){
    if(start > end) return;
    if(start == end) tr[node] = arr[start];
    else{
        int mid = (start+end)/2;
        build(start, mid, 2*node);
        build(mid+1, end, 2*node+1);
        tr[node] = min(tr[2*node], tr[2*node+1]);
    }
}

ll query(int start, int end, int l, int r, int node){
    if(r < start || l > end || start > end) return INT_MAX;
    if(l <= start && end <= r) return tr[node];
    int mid = (start + end)/2;
    ll p1 = query(start, mid, l, r, 2*node);
    ll p2 = query(mid+1, end, l, r, 2*node+1);
    return min(p1, p2);
}

int main(){
    testcase(t){
        vector<pll> v;
        ll n,q,k,l,r,x,y;
        cin>>n>>q>>k>>l>>r;
        rep(i,1,n){
            cin>>x>>y;
            v.pb(mp(x, y));
        }
        sort(all(v));
        ll f1[n+1];
        rep(i,1,n) {arr[i] = v[i-1].ss;f1[i] = v[i-1].ff;}
        build(1, n, 1);

        rep(j,1,q){
            if(k<l && k<r){ l++; r++;}
            else if(k>l && k>r){ l--; r--;}
            else if(l<=k && k<=r){l--; r++;}
            // cout<<"-l--"<<l<<" "<<r<<"---"<<endl;

            int lb = lower_bound(f1+1, f1+1+n, l)-f1;
            int ub = upper_bound(f1+1, f1+1+n, r)-f1-1;
            // cout<<"---"<<lb<<" "<<ub<<"---"<<endl;

            if(ub<lb || lb<1 || lb>n || ub<1 || ub>n) cout<<"-1 ";
            else cout<<query(1, n, lb, ub, 1)<<" ";
        }
        cout<<endl;
    }

}
