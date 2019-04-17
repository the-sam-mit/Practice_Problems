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
        int n,k;
        cin>>n>>k;
        int diff=n/k;
        rep(i,0,k-1){
            rep(j,1,diff) cout<<(char)('a'+i);
        }
        diff=n-(diff*k);
        rep(i,1,diff) cout<<'a';
        cout<<endl;
    }
}
