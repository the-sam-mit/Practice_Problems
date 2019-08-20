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
 
 
const ll INF=1e7; 
const int SIZE = 1e5+5;
#define V 100
int dist[V][V];
void floydWarshall (int graph[][V])  
{  
    int i, j, k;  
    for (i = 0; i < V; i++)  
        for (j = 0; j < V; j++)  
            dist[i][j] = graph[i][j];  
    for (k = 0; k < V; k++)  
    {  
        for (i = 0; i < V; i++)  
        {  
            for (j = 0; j < V; j++)  
            {  
                if (dist[i][k] + dist[k][j] < dist[i][j])  
                    dist[i][j] = dist[i][k] + dist[k][j];  
            }  
        }  
    }  
}  
  
int main()  
{  
	int n;
	cin>>n;
	int graph[V][V];
	rep(i,0,V-1){
		rep(j,0,V-1) graph[i][j]=INF;
	}
	char c;
	rep(i,0,n-1){
		rep(j,0,n-1) {
			cin>>c;
			graph[i][j]=c-'0';
			if(graph[i][j]==0 && i!=j){
				graph[i][j] = INF;
			}
		}
		// cout<<endl;
	}
    floydWarshall(graph);
    int vv;
    cin>>vv;
    ll p[vv];
    inp0(p,vv)
    vector<int> vvv;
    vvv.pb(p[0]);
    int j=0;
    rep(i,1,vv-2){
    	// cout<<vvv[sz(vvv)-1]<<" "<<p[i+1]<<" "<<i<<" "<<j<<" "<<dist[vvv[sz(vvv)-1]-1][p[i+1]-1]<<endl;
    	if(dist[vvv[sz(vvv)-1]-1][p[i+1]-1] < i-j+1 ){
    		vvv.pb(p[i]);
    		// cout<<p[i]<<endl;
    		j=i;
    	}
    }

    vvv.pb(p[vv-1]);
    cout<<sz(vvv)<<endl;
    for(auto it:vvv) cout<<it<<" ";
    	cout<<endl;
    return 0;  
}  
