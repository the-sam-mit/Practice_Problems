//2-Dimensional DP
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

struct node{
    ll val, price;
    int isalbum, songcnt; 
}s[2005];

ll dp[2005][2005];

int main(){
   reflex;
   int n, m, ai, x, y, bef;
   int prices;
   cin>>n>>m>>prices;
   vector<pair<ll, ll>>album[2005];
   ffor(i,0,n){
        cin>>ai>>x>>y;
        album[ai].pb(mp(x,y));
   }
   ll b[2005]={0};
   ffor(i,1,m+1) cin>>b[i];
   memset(dp, 0, sizeof(dp));
   int c=1;
   ffor(i,1,m+1){
        ll av=0, ap=0;
        for(auto j:album[i]){
            s[c].val=j.second;
            s[c].price=j.first;
            s[c].isalbum=0;
            s[c].songcnt=0;
            av+=s[c].val;
            ap+=s[c].price;
            c++;
        }
        s[c].isalbum=1;
        s[c].songcnt=(int)album[i].size();
        s[c].val=av;
        s[c].price=b[i];
        c++;
   }
   c--;
   ffor(i,1,c+1){
        ffor(j,1,prices+1){
            if(s[i].price<=j){
                if(s[i].isalbum){
                    bef=i-s[i].songcnt-1;
                    dp[i][j]=max(dp[bef][j-s[i].price]+s[i].val, dp[bef][j]);
                }
                else{
                    dp[i][j]=max(dp[i-1][j-s[i].price]+s[i].val, dp[i-1][j]);
                }
            }
        }
        ffor(j,0,prices+1){
            dp[i][j]=max(dp[i][j], dp[i-1][j]);
        }
   }
   ll ans=0;
   ffor(i,0,prices+1){ans=max(ans, dp[c][i]);} 
   cout<<ans<<endl;

}
