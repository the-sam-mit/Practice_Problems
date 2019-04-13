//Ad-Hoc
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

int main(){
    reflex;
    ll n;
    string s;
    cin>>n>>s;
    if(n%2!=0){cout<<":("<<endl;return 0;}
    int cnt=0;
    rep(i,0,n-1){
        if(s[i]=='(') cnt++;
    }
    rep(i,0,n-1){
        if(s[i]=='?'){
            if(cnt<(n/2)) {cnt++;s[i]='(';}
            else {s[i]=')';}
        }
    }
    cnt=0;
    rep(i,0,n-1){
        if(s[i]=='(') cnt++;
        else cnt--;
        if((cnt==0 && (n-1!=i)) || cnt<0){cout<<":("<<endl;return 0;}
    }
    if(cnt!=0) {cout<<":("<<endl;return 0;}
    cout<<s<<endl;
}
