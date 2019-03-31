//Bit Masking
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
#define SIZE 1000004
int x[11], y[11], n;int mask[10]={119, 36, 93, 109, 46, 107, 123, 37, 127, 111};
int func(int mskans){
    ffor(i,0,n){
        int cnt=0;
        ffor(j,0,7){
            if((mask[x[i]] & (1<<j)) && !(mskans & (1<<j))) cnt++;
        }
        if(cnt != y[i]) return 0;
    }
    return 1;
}

int main(){
    reflex;
    int t;
    cin>>t;
    while(t--){
       
        cin>>n;
        ffor(i,0,n){cin>>x[i]>>y[i];}
        int flag=0, maxx, minn;
        for(int i=0;i<(1<<7);i++){
            if(func(i)){
                if(flag==0){
                    maxx=__builtin_popcount(i);
                    minn=maxx;
                    flag=1;
                }
                else{
                    maxx=max(maxx, __builtin_popcount(i));
                    minn=min(minn, __builtin_popcount(i));
                }
            }
        }
        if(flag==0) cout<<"invalid\n";
        else cout<<minn<<" "<<maxx<<endl;
    }
}
