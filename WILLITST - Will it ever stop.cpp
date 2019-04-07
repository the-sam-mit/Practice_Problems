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
#define ffor(i,a,b) for(int i=a;i<b;i++)
#define bfor(i,a,b) for(int i=a;i>=b;i--)
#define PI 3.14159265358979323846
#define SP(x) setprecision(x)
#define reflex ios_base::sync_with_stdio(false);cin.tie(NULL)

int main(){
    reflex;
    set<ll> s;
    ll x=1;
    ffor(i,0,50){
    	s.in(x);
    	x*=2;
    	if(x>100000000000000) break;
    }
    ll n;
    cin>>n;
    if(s.find(n)!=s.end() || n<1) cout<<"TAK\n";
    else cout<<"NIE\n";
}
