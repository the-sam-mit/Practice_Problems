// Ad - Hoc  (Maths)
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

ll max_prime_factor(ll n){
    ll maxx = -1;
    while(n % 2 == 0){
        maxx =2;
        n /= 2;
    }
    for (int i = 3; i <= sqrt(n); i += 2){
        while(n % i == 0){
            maxx = i;
            n /= i;
        }     
    }
    return maxx; 
}

int main(){
    reflex;
    testcase(t){
        ll n,k;
        cin >> n >> k;
        ll a[n+2];
        rep(i,1,n) cin>>a[i];
        ll g = a[1];
        rep(i,2,n) g = __gcd(g, a[i]);
        ll maxx = max_prime_factor(g);
        if(maxx == -1) maxx = g; 
        if(maxx <= k ) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
