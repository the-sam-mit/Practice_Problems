//DP - Checks all possible paths and then trace back(parent to parent)
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
int dp[100005][7], par[100005][7];
void solve(){
    int n;
    cin>>n;
    int arr[n+2];
    rep(i,1,n){cin>>arr[i];}
    rep(i,1,n){
        rep(j,1,5){ 
            dp[i][j]=-1;
            if(i==1) dp[i][j]=1;
        }
    }
    rep(i,2,n){
        rep(j,1,5){
            if(arr[i]>arr[i-1]){
                nrep(k,1,j-1){
                    if(dp[i-1][k]==1){
                        dp[i][j]=1;
                        par[i][j]=k;
                        break;
                    }
                }
            }
            else if(arr[i]<arr[i-1]){
                rep(k,j+1,5){
                    if(dp[i-1][k]==1){
                        dp[i][j]=1;
                        par[i][j]=k;
                        break;
                    }
                }
            }
            else{
                rep(k,1,5){
                    if(dp[i-1][k]==1 && k!=j){
                        dp[i][j]=1;
                        par[i][j]=k;
                        break;
                    }
                }
            }
        }
    }
    stack<int> st;
    rep(i,1,5){
        if(dp[n][i]!=-1){
            int x=i;i=n;
            while(i!=-1 && x!=0){
                st.push(x);
                x=par[i][x];
                i--;
            }
            break;
        }
    }
    if(st.size()==0) cout<<"-1\n";
    else{
        while(!st.empty()){
            cout<<st.top()<<" ";
            st.pop();
        }
    }
}


int main(){
    reflex;
    int t;
    //cin>>t;
    t=1;
    while(t--){
        solve();
    }    
}
