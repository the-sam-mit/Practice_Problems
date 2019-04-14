// Kadane's Algorithm for finding maximum sum subarray
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
ll a[100005]={0};

int main(){
    reflex;
    testcase(t){
        ll n, k, maxx=LONG_MIN, sum=0, minsum=0;
        cin>>n>>k;
        rep(i,0,n-1){
            cin >> a[i];
            sum += a[i];
            maxx = max(maxx, sum - minsum);
            minsum = min(minsum, sum);
        }
        ll xx = sum;
        if(k >= 2){
            rep(i,0,n-1){
                sum += a[i];
                maxx = max(maxx, sum - minsum);
                minsum = min(minsum, sum);
            }
            if(xx > 0) maxx = maxx + xx*(k-2);   
        }
        cout << maxx <<endl;
    }
    
}
