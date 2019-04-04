// Ad-Hoc
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
    int a[n];
    vector<int> odd, even;
    ll tot=0;
    ffor(i,0,n){
    	cin>>a[i];
    	tot+=a[i];
    	if(a[i]%2==0) odd.pb(a[i]);
    	else even.pb(a[i]);
    }
    sort(odd.rbegin(), odd.rend());
    sort(even.rbegin(), even.rend());
    int maxx=min(odd.size(), even.size());
    int i=0;
    ll sum=0;
    while(i<maxx){
    	sum+=odd[i]+even[i];
    	i++;
    }
    if(odd.size()<even.size()) sum+=even[i];
    else if(odd.size()>even.size()) sum+=odd[i];
    cout<<tot-sum<<endl;
}
