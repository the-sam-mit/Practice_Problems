//Basic Maths
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
#define reflex ios_base::sync_with_stdio(false);cin.tie(NULL)

int main(){
    ll a, b, c;
    while(cin>>a>>b>>c){
        if(a==0 && b==0 && c==0) break;
        if(2*b==a+c){cout<<"AP "<<c+(b-a)<<endl;}
        else cout<<"GP "<<c*(b/a)<<endl;
    }
}