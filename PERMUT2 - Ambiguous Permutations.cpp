//Ad-Hoc
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define ff first 
#define ss second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define in(x) insert(x)
#define rep(i,a,b)  for (__typeof((b)) i=(a);i<=(b);i++)
#define nrep(i,a,b)  for (__typeof((b)) i=(b);i>=(a);i--)
#define ffor(i,a,b) for(int i=a;i<b;i++)
#define bfor(i,a,b) for(int i=a;i>=b;i--)
#define PI 3.14159265358979323846
#define SP(x) setprecision(x)
#define reflex ios_base::sync_with_stdio(false);cin.tie(NULL)
#define M 1000000007
int main(){
    reflex;
    int n;
    while(true){
        cin>>n;
        int flag=0;
        if(n==0) break;
        ll a[n+2], ans[n+2];
        rep(i,1,n) cin>>a[i];
        rep(i,1,n){
            ans[a[i]]=i;
        }
        rep(i,1,n){
            if(ans[i]!=a[i]) {flag=1;break;}
        }
        if(flag==0) cout<<"ambiguous\n";
        if(flag==1) cout<<"not ambiguous\n";continue;
                
    }
    
}
