// Basic
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
    int n;
    cin>>n;
    int a[n+2], maxx=0, pos=0, freq[212345]={0};
    ffor(i,1,n+1){cin>>a[i];freq[a[i]]++;}
    ffor(i,0,200001){
    	if(maxx < freq[i]){
    		maxx=freq[i];
    		pos=i;
    	}
	}
	maxx=pos;
	cout<<n-freq[pos]<<endl;
	ffor(i,1,n+1){
		if(a[i]==maxx){pos=i;break;}
	}
	bfor(i,pos-1,1){
		if(a[i]>maxx) cout<<"2 "<<i<<" "<<i+1<<endl;
		else if(a[i]<maxx) cout<<"1 "<<i<<" "<<i+1<<endl;
	}
	ffor(i,pos,n+1){
		if(a[i]>maxx) cout<<"2 "<<i<<" "<<i-1<<endl;
		else if(a[i]<maxx) cout<<"1 "<<i<<" "<<i-1<<endl;
	}
}
