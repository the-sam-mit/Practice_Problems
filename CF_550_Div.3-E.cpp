// String Addition and Subtraction(Character Array Arithmetic)
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
    string s,t;
    cin>>s>>t;
    int diff[n]={0};
    bfor(i,n-1,0){
    	int x=(t[i]-96),y=(s[i]-96);
    	if(x >= y) diff[i]=x-y;
    	else{
    		diff[i]=x-y+26;
    		t[i-1]--;
    	}
    }
   ffor(i,0,n){
    	if(diff[i]%2==0) diff[i]/=2;
    	else{
    		diff[i+1]+=26;
    		diff[i]/=2;
    	}
    }
    bfor(i,n-1,0){
    	int y=(s[i]-96);
    	diff[i]=diff[i]+y;
    	if(diff[i]>26){
    		diff[i-1]+=1;
    		diff[i]%=26;
    		if(diff[i]==0) diff[i]=26;
    	}
    }
    ffor(i,0,n) cout<<(char)(diff[i]+96);
}
