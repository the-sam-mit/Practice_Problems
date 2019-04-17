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
    int n,diff=0;
    cin>>n;
    int a[n+1];
    rep(i,1,n) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i+=2){
        diff+=a[i+1]-a[i];
    }
    cout<<diff<<endl;
}
