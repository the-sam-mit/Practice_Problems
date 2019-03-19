//Codechef Easy
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
    int t,n;
    cin>>t;
    string s;
    while(t--){
        cin>>n>>s;
        
        vector<int> v;
        ffor(i,0,n){
            if(s[0]==s[i]) v.pb(i);
        }
        int k=0;
        int flag=1;
        while(flag==1){
            ffor(i,0,(int)(v.size())){
                if(s[v[i]+k]!=s[k] || v[i]+k>=n){
                    flag=0;break;
                }
            }
            if(flag==1) k++;
        }
        cout<<s.substr(0,k)<<endl;
    }
}  
