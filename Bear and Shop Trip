#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define INF 1000000000
#define pb(x) push_back(x)
#define in(x) insert(x)
#define ffor(i,a,b) for(int i=a;i<b;i++)
#define bfor(i,a,b) for(int i=a;i>=b;i--)
#define PI 3.14159265358979323846
#define SP(x) setprecision(x)
#define M 1000000007
#define reflex ios_base::sync_with_stdio(false);cin.tie(NULL)
int allmask=0;
double dpx[1<<13][50];
double dist(int source, int destination, int a[][2]){
    double x=sqrt( ((a[source][0]-a[destination][0])*(a[source][0]-a[destination][0])) + (a[source][1]-a[destination][1])*(a[source][1]-a[destination][1]));
    return x;
}

double dp(int shop, int mask, int a[][2], int n, int masks[]){
    if(mask==allmask){return dist(n, shop, a);}
    else{
         double minn=INF;
        ffor(i,0,n){
            if(dpx[mask][shop]!=-1) {return dpx[mask][shop];}
            if(i==shop) continue;
            double d=dist(shop,i,a); 
            int newmask=mask | masks[i];
            if(newmask!=mask){
                minn=min(minn, d + dp(i, newmask, a, n, masks));
            }
        }
        dpx[mask][shop]=minn;
        return dpx[mask][shop];
    }
}

int main(){
    reflex;
    int n,t,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        int a[n+2][2]={0};
        string s[n+2];
        int masks[n+2]={0};
        ffor(i,0,n){
            cin>>a[i][0]>>a[i][1];
        }
        ffor(i,0,n) cin>>s[i];
        ffor(i,0,k){
            ffor(j,0,n){
                masks[j]+=(s[j][k-1-i]-'0')<<i;
            }
        }

        ffor(i,0,(1<<13)){
            ffor(j,0,50)
                 dpx[i][j]=-1;
        }
        allmask=(1<<k)-1;
        a[n][0]=a[n][1]=0;
        double ans=dp(n, 0, a, n, masks);
        if(ans==INF) cout<<"-1\n";
        else cout<<fixed<<SP(9)<<ans<<endl;
    }
}  
