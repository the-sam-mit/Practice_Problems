#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define ff first 
#define ss second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define in(x) insert(x)
#define rep(i,a,b)  for (__typeof((b)) i=(a);i<=(b);i++)
#define nrep(i,a,b)  for (__typeof((b)) i=(b);i>=(a);i--)
#define ffor(i,a,b) for(int i=a;i<b;i++)
#define bfor(i,a,b) for(int i=a;i>=b;i--)
#define PI 3.14159265358979323846
#define SP(x) setprecision(x)
#define reflex ios_base::sync_with_stdio(false);cin.tie(NULL)
#define M 1000000007
string s;
        
int check_all_nine(int n){
    rep(i,0,n-1){
        if(s[i]!='9') return 0;
    }
    return 1;
}


int main(){
    reflex;
    int t;
    cin>>t;
    while(t--){
        cin>>s;
        int n=s.size(),flag=0;
        //if(n==1) {cout<<"11\n";continue;}
        int mid=(n/2)-1;
        if(check_all_nine(n)==1){
            cout<<"1";
            rep(i,0,n-2) cout<<"0";
            cout<<"1\n";
            continue;
        }
        else{
            int mi=n/2,mj;
            mj=mi;
            if(n%2==0){
                mi--;
            }
            while(mi>=0 && s[mi]==s[mj]){mi--;mj++;}
            if(mi<0 || s[mi]<s[mj]){
                mi=n/2;
                mj=mi;
                if(n%2==0) mi--;
                int carry=1;
                while(mi>=0){
                    int xx=s[mi]-'0';
                    xx+=carry;
                    carry=xx/10;
                    s[mi]=(xx%10)+'0';
                    s[mj]=s[mi];
                    mi--;mj++;
                }
            }
            else{
                while(mi>=0){
                    s[mj]=s[mi];mi--;mj++;
                }
            }
            cout<<s<<endl;  
        }
    }
}
