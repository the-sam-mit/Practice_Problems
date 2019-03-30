//Number Theory
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
#define M 1000000007
#define reflex ios_base::sync_with_stdio(false);cin.tie(NULL)
#define SIZE 1000004


int main(){
    reflex;
    int k,n;
    cin>>n>>k;
    ll a[n];
    int cnt[k+2]={0};
    ffor(i,0,n){cin>>a[i];cnt[a[i]%k]++;}
    ll ans=cnt[0]/2;
    ffor(i,1,(k/2)+1){ ll xd=min(cnt[i],cnt[k-i]); if(i==k-i)xd/=2; ans+=xd;}
    cout<<ans*2<<endl;
}
