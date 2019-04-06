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
    int n,m;
    cin>>n>>m;
    int a[n][m],b[n][m];
    ffor(i,0,n){
    	ffor(j,0,m) cin>>a[i][j];
    }
    ffor(i,0,n){
    	ffor(j,0,m) cin>>b[i][j];
    }
    int rc=0,cc=0,c=0,r=0;
    ffor(i,0,n){
    	c=0;
    	ffor(j,0,m){
    		if(a[i][j]!=b[i][j]) c++;
    	}
    	if(c%2!=0){
    		cout<<"No\n"; return 0;
    	}
    }
    ffor(i,0,m){
    	r=0;
    	ffor(j,0,n){
    		if(a[j][i]!=b[j][i]) r++;
    	}
    	if(r%2!=0){
    		cout<<"No\n"; return 0;
    	}
    }
    cout<<"Yes\n";
    
}
