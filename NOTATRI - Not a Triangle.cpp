//Maths
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
    int n;
    while(true){
    	cin>>n;
    	if(n==0) break;
    	ll x;
    	vector<ll> v;
    	ffor(i,0,n){ cin>>x;v.pb(x);}
    	sort(v.begin(), v.end());
    	ll ans=0;
    	ffor(i,0,n-1){
    		ffor(j,i+1,n){
    			ll sum=v[i]+v[j];
    			auto it=upper_bound(v.begin(), v.end(), sum);
    			ans+=(v.end()-it);
    		}
    	}
    	cout<<ans<<endl;
    }
}
