#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb(x) push_back(x)
#define ffor(i,a,b) for(int i=a;i<b;i++)
#define bfor(i,a,b) for(int i=a;i>=b;i--)
#define PI 3.14159265358979323846
#define SP setprecision
#define M 1000000007
#define reflex ios_base::sync_with_stdio(false)

int main(){
    reflex;
    map<int,int>cnt[2];
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll x=0;
    ll ans=0;
    
    
    cnt[1][0]=1;

    for(int i=0;i<n;i++){
        x=x^a[i];
        ans=ans+cnt[i%2][x];
           cnt[i%2][x]++;
    }
    cout<<ans<<endl;
}


/*Here Xor values are stored continuously in x 
and then we are incrementing answer by the number of combinations till now for which that value will give us zero*/
