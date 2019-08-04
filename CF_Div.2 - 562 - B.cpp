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
	ll n,m,a,b;
	cin>>n>>m;
	vector<pair<ll,ll>> v;
	rep(i,1,m){
		cin>>a>>b;
		v.pb(mp(a,b));
	}
	ll x,y1,y2;
	x=v[0].ff;
	int flag=0;
	rep(i,0,m-1){
		if(v[i].ff!=x && v[i].ss!=x){
			y1=v[i].ff;
			y2=v[i].ss;
			flag=1;
			break;
		}
	}
	if(flag==0){
		cout<<"YES\n";
		return 0;
	}
	flag=0;
	rep(i,0,m-1){
		if(v[i].ff!=x && v[i].ss!=x){
			if(v[i].ff!=y1 && v[i].ss!=y1){
				flag=1;
				break;
			}
		}
	}
	if(flag==0){
		cout<<"YES\n";
		return 0;
	}
	flag=0;
	rep(i,0,m-1){
		if(v[i].ff!=x && v[i].ss!=x){
			if(v[i].ff!=y2 && v[i].ss!=y2){
				flag=1;
				break;
			}
		}
	}
	if(flag==0){
		cout<<"YES\n";
		return 0;
	}
	//cout<<x<<" "<<y1<<" "<<y2<<endl;
	x=v[0].ss;
	flag=0;
	rep(i,0,m-1){
		if(v[i].ff!=x && v[i].ss!=x){
			y1=v[i].ff;
			y2=v[i].ss;
			flag=1;
			break;
		}
	}
	if(flag==0){
		cout<<"YES\n";
		return 0;
	}
	flag=0;
	rep(i,0,m-1){
		if(v[i].ff!=x && v[i].ss!=x){
			if(v[i].ff!=y1 && v[i].ss!=y1){
				flag=1;
				break;
			}
		}
	}
	if(flag==0){
		cout<<"YES\n";
		return 0;
	}
	flag=0;
	rep(i,0,m-1){
		if(v[i].ff!=x && v[i].ss!=x){
			if(v[i].ff!=y2 && v[i].ss!=y2){
				flag=1;
				break;
			}
		}
	}
	//cout<<x<<" "<<y1<<" "<<y2<<endl;
	if(flag==0){
		cout<<"YES\n";
		return 0;
	}
	cout<<"NO\n";
}
