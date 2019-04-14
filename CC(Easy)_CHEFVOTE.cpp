// Ad-Hoc.....Can also be solved by Digraph Realization(To be done)
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define ff first 
#define ss second
#define pb(x) push_back(x)
#define testcase(t) int t;cin>>t;while(t--)
#define mp(x,y) make_pair(x,y)
#define in(x) insert(x)
#define rep(i,a,b)  for (__typeof((b)) i=(a);i<=(b);i++)
#define nrep(i,a,b)  for (__typeof((b)) i=(b);i>=(a);i--)
#define PI 3.14159265358979323846
#define SP(x) setprecision(x)
#define reflex ios_base::sync_with_stdio(false);cin.tie(NULL)
#define M 1000000007
int main(){
    reflex;
    testcase(t){
        ll n;
        cin>>n;
        ll c[n+2]={0};ll sum = 0, ans[n+2]={0};
        int flag=1;
        rep(i,1,n){
            cin>>c[i];
            if(c[i] >= n) flag = 0;
            sum += c[i];
        }
        if(sum != n || flag == 0){
            cout<<"-1\n"; continue;
        }
        priority_queue <pair<ll, ll>>q;
        rep(i,1,n){
            q.push(mp(c[i], i));
        } 
        int cnt = n;
        while(cnt){
            ll x = q.top().ss;
            ll y = q.top().ff;
            q.pop();
            if(y<=0) continue;
            rep(i,1,n){
                if((ans[i] == 0) && (x != i)){
                    ans[i] = x;
                    q.push(mp(y-1, x));

                    break;
                }
                
            }
            cnt--;
        }
        rep(i,1,n) cout<<ans[i]<<" ";
        cout<<endl;
    }
}
