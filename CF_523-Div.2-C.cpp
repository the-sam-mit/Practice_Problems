// Transforming 2(D)-DP into DP- 1(D) 
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
#define SIZE 1000004

int main(){
    reflex;
    int n;
    cin>>n;
    int a[n+1];
    ffor(i,1,n+1) cin>>a[i];
    ll dp[1000004]={0};
    dp[0]=1;
    ffor(i,1,n+1){
        vector<int> fac;
        for(int j=1;j*j<=a[i];j++){
            if(a[i]%j==0){
                fac.pb(j);
                if(j!=a[i]/j) fac.pb(a[i]/j);
            }
        }
        sort(fac.begin(), fac.end());
        reverse(fac.begin(), fac.end());
        for(auto &it : fac){
            int xy=(it);
            dp[xy]=dp[xy-1]+dp[xy];
            dp[xy]%=M;
        }    
    }
    ll ans=0;
    ffor(i,1,n+1) ans+=dp[i];
    ans%=M;
    cout<<ans<<endl;
}
