//Spoj:-(Uses DP)
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

map<int,ll> m;
ll calc(int num){
    if(num<12) return m[num]=num;
    if(m[num]!=0) return m[num];
    m[num] = calc(num/2) + calc(num/3) + calc(num/4);
    return m[num];
}

int main(){
    reflex;
    m[0]=0;
    m[1]=1;
    m[2]=2;
    m[3]=3;
    m[4]=4;
    int n;
    while(scanf("%d",&n)!=EOF){
        cout<<calc(n)<<endl;
    }
}
