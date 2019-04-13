// Basic Maths
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

int is_sqrt(ll n){
    long double sq = sqrt(n);
    if(sq - floor(sq) == 0) return sq;
    return 0;
}

int main(){
    reflex;
    ll n;
    while(true){
        cin>>n;
        if(n==-1) break;
        if((n-1)%3==0){
            n=(n-1)/3;
            if(is_sqrt(1+(4*n)) && (is_sqrt(1+(4*n))-1)%2==0) {cout<<"Y\n";continue;}
        }
        cout<<"N\n";
    }
}
