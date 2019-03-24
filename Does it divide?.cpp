//Uses Ad-hoc Maths
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
   int t;
   cin>>t;
   while(t--){
        ll n;
        cin>>n;
        if(n%2==0){
            ll x=n+1;
            int cnt=0;
            ffor(i,2,sqrt(x)+1){
                if(x%i==0){ cnt++;break;}
            }
            if(cnt>0) cout<<"YES\n";
            else cout<<"NO\n";
        }
        else cout<<"YES\n";
    }  
}
