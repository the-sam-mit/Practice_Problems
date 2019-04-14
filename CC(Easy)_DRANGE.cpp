// Difference Arrays
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
        ll m,n,x,y,z,w;
        cin>>n>>m;
        ll diff[n+3]={0}, ans[n+3]={0};
        while(m--){
            cin>>x>>y>>z>>w;
            if(x==1){
                diff[y] += w;
                diff[z+1] += (-w);      
            }
            else{
                diff[y] += (-w);
                diff[z+1] += w;
            }
        }
        rep(i,1,n){
            diff[i] += diff[i-1];
            ans[i] = (i) + diff[i];
        }
        ll maxx=LONG_MIN, minn=LONG_MAX;
        rep(i,1,n){
            minn = min(minn, ans[i]);
            maxx = max(maxx, ans[i]);
        }
        cout<<maxx-minn<<endl;
    }
}
