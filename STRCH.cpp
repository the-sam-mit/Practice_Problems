//Ad-Hoc
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
    	int n;string s;char ch;
    	cin>>n>>s>>ch;
    	ll sum=0,pos=-1;
    	ffor(i,0,n){
    		if(pos==-1 && ch==s[i]){
    			sum=(i+1)*(n-i);
    			pos=i;
    		}
    		else if(pos!=-1 && ch==s[i]){
    			sum+=(i-pos)*(n-i);
    			pos=i;
    		}
    	}
    	cout<<sum<<endl;
    }
}
