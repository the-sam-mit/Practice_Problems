//Ad-Hoc
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
#define set_bit(x) __builtin_popcount(x)

int main(){
    reflex;
    int b, k;
    cin>>b>>k;
    int cnt=0;
    int a[k];
    ffor(i,0,k) cin>>a[i];
    if(b%2==0){
        if(a[k-1]%2==0) cout<<"even";
        else cout<<"odd";
        return 0;
    }
    ffor(i,0,k){if(a[i]%2!=0)cnt++;}
    if(cnt%2==0) cout<<"even";
    else cout<<"odd";
}
