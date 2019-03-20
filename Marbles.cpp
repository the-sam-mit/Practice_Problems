//Distribution of identical objects--NCR(n-1,r-1)
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define INF 1000000000
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define in(x) insert(x)
#define ffor(i,a,b) for(int i=a;i<b;i++)
#define bfor(i,a,b) for(int i=a;i>=b;i--)
#define PI 3.14159265358979323846
#define SP(x) setprecision(x)
#define M 4294967295
#define reflex ios_base::sync_with_stdio(false);cin.tie(NULL)
#define SIZE 300000+5

long long int NCR(long long n,long long r){
    ll x=1,y=1;
    while(r>0){
        x=x*n;
        y=y*r;
        ll m=(ll)__gcd(x,y);
        x=x/m;
        y=y/m;
        n--;
        r--;
    }
    return x;
}

int main(){
    reflex;
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        n--;k--;
        if(n-k<k) k=n-k;
        ll ans=NCR(n,k);
        cout<<ans<<endl;
    }
}
