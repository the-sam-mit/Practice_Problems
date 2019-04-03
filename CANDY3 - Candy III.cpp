//SPOJ - Modulus 
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
    	ll n;
    	cin>>n;
    	ll sum=0,x;
    	ffor(i,0,n){
    		cin>>x;
    		sum+=x;
    		sum%=n;
    	}
    	if(sum==0) cout<<"YES\n";
    	else cout<<"NO\n";
    }		
}

