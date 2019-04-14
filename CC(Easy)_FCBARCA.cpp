// DP - (Math)
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define ff first 
#define ss second
#define pb(x) push_back(x)
#define testcase(t) int t;cin>>t;while(t--)
#define mp(x,y) make_pair(x,y)
#define in(x) insert(x)
#define rep(i,a,b)  for (__typeof((b)) i=(a);i<=(b);i++)
#define nrep(i,a,b)  for (__typeof((b)) i=(b);i>=(a);i--)
#define PI 3.14159265358979323846
#define SP(x) setprecision(x)
#define reflex ios_base::sync_with_stdio(false);cin.tie(NULL)
#define M 1000000007
int main(){
    reflex;
    testcase(t){
        ll n, k;
        cin>>k>>n;
        ll arr[k+3][2]={0};
        arr[0][0]=1;
        int i=1;
        while(i <= k){
            arr[i][0] = (n * arr[i-1][1])%M;
            arr[i][1] = (((arr[i-1][1] * (n-1))%M) + arr[i-1][0])%M;
            i++;
        }
        cout<<arr[k][0]<<endl;
    }
}