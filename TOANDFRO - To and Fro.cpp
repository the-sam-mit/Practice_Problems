// SPOJ - Ad-Hoc
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
    reflex;
    int n;
    string s;
    while(cin>>n){
        if(n==0) break;
        cin>>s;
        int x=s.size()/n,k=0;
        if(s.size()%n!=0) x++;
        char ch[x+1][n+1];
        ffor(i,0,x){
            ffor(j,0,n){
                if(i%2==0) ch[i][j]=s[k++];
                else ch[i][n-1-j]=s[k++];
                
            } 
        }
        ffor(i,0,n){
            ffor(j,0,x){
                if(ch[j][i]!=' ')
                cout<<ch[j][i];
            }
        }
        cout<<endl;
    }

}
