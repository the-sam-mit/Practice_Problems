//Uses Knapsack DP
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
#define INF 1000000000
#define reflex ios_base::sync_with_stdio(false);cin.tie(NULL)
#define set_bit(x) __builtin_popcount(x)
ll a[10005]={0}, dp1[10005], dp2[10005];
int func_min(int num, int k){
    if(num<=0) return 0;
    if(dp1[num]!=-1) return dp1[num];
    int ans=INF;
    ffor(i,0,k){
        if(a[i]>num) break;
        ans=min(ans, 1+func_min(num-a[i], k));
    }
    return dp1[num]=ans;
}

int func_max(int num, int k){
    if(num<=0) return 0;
    if(dp2[num]!=-1) return dp2[num];
    int ans=-INF;
    ffor(i,0,k){
        if(a[i]>num) break;
        ans=max(ans, 1+func_max(num-a[i], k));
    }
    return dp2[num]=ans;
}

int main(){
    reflex;
    memset(a, -1, sizeof(a));
    memset(dp1, -1, sizeof(dp1));
    memset(dp2, -1, sizeof(dp2));
    int n,k;
    cin>>n>>k;
    ffor(i,0,k){ cin>>a[i];}
    sort(a, a+k);
    ll minans=-1, maxans=-1;
    ll ans=func_min(n, k);
    if(ans>=INF) cout<<"-1 -1\n";
    else{
        cout<<ans<<" ";
        ans=func_max(n, k);
        cout<<ans<<endl;
    }
}
