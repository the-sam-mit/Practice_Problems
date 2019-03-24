//Ad-Hoc
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define INF 1000000000
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define in(x) insert(x)
#define ffor(i,a,b) for(int i=a;i<b;i++)
#define bfor(i,a,b) for(int i=a;i>=b;i--)
#define PI 3.14159265358979323846
#define SP(x) setprecision(x)
#define M 1000000007
#define reflex ios_base::sync_with_stdio(false);cin.tie(NULL)
#define SIZE 300000+5

int main(){
   reflex;
   int n, q;
   cin>>n>>q;
   ll k;
   ll a[n+2]={0};
   ffor(i,1,n+1) cin>>a[i];
   ll ans[n+2]={0};
   ffor(i,1,n+1){
        ans[i]=ans[i-1]^a[i];
   }
   while(q--){
        cin>>k;
        ll y= k%(n+1);
        cout<<ans[y]<<endl;

   }
}
