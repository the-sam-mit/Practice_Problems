//Uses Greedy Approach
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
   int n,m,g;
   cin>>n>>m>>g;
   ll t[n], a[m];
   ffor(i,0,n) cin>>t[i];
   ffor(i,0,m) cin>>a[i];
   ll diff=0, maxx=0;
   sort(a, a+m);
   ffor(i,1,n){
        diff=t[i]-t[i-1];
        maxx=max(diff,maxx);
   }
   ll cnt=0;
   ffor(i,0,m){
        if(a[i]<=maxx) cnt++;
        else break;
   }
   cout<<cnt<<endl;
}
