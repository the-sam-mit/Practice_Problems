#include<bits/stdc++.h>
using namespace std;
#define ll long long int
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
    int t;
    cin>>t;
    while(t--){
		ll n,m,k,x,y;
		cin>>n>>m>>k;
		ll cnt=0;
		set<pair<ll,ll> >s;
		ffor(i,0,k){
			cin>>x>>y;
			s.in(mp(x,y));
		}
		auto it = s.begin();
		while(k--){
			x = it->ff , y = it->ss;
			if(s.find(mp(x-1,y))==s.end()) cnt++;
			if(s.find(mp(x+1,y))==s.end()) cnt++;
			if(s.find(mp(x,y-1))==s.end()) cnt++;
			if(s.find(mp(x,y+1))==s.end()) cnt++;
			it++;
		}
		cout<<cnt<<endl;
	}
}
