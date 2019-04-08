#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define ff first 
#define ss second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define in(x) insert(x)
#define rep(i,a,b)  for (__typeof((b)) i=(a);i<=(b);i++)
#define nrep(i,a,b)  for (__typeof((b)) i=(b);i>=(a);i--)
#define ffor(i,a,b) for(int i=a;i<b;i++)
#define bfor(i,a,b) for(int i=a;i>=b;i--)
#define PI 3.14159265358979323846
#define SP(x) setprecision(x)
#define reflex ios_base::sync_with_stdio(false);cin.tie(NULL)
#define M 1000000007

long long int power(long long int a,long long int b){
    if(b==0)
        return 1;
    if(b==1)
        return a;
    if(b%2==0){
        long long int x=power(a,b/2);
        return((x*x)%M);
    }
    else{
        long long int x=power(a,b/2);
        x=(x*x)%M;
        return((x*a)%M);
    }
}

int main(){
    reflex;
    int n,q;
    cin>>n>>q;
    ll e=0;
    e=2*(power(2,n)-1);
    ll a=(n+1)%M,b=power(2,n),c=1;
    while(q--){
    	int x,y;
    	cin>>x;
    	if(x==1){
    		cin>>y;
    		if(y==1 || y==2){
    			e=(((2*e)%M)+a)%M;
    			b=(b*2)%M;c=(c*2)%M;
    		}
    		else{
	    		if(y==3){e=(((2*e)%M)+c)%M;c=b;} 
	    		else {e=(((2*e)%M)+b)%M;b=c;}

    			a=(a*2)%M;
    		}
    	}
    	else cout<<e<<endl;
    }
}
