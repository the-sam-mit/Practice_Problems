// Check all possible solutions
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
string ans;
vector<string> v;
int n;
int check(string pre, string suff){
    string s=pre+suff.substr(n-2);
    multiset<string> su;
    multiset<string> pr;
    multiset<string> vv;
    rep(i,0,n-2){
        pr.in(s.substr(0,n-i-1));
        vv.in(s.substr(0,n-i-1));
        su.in(s.substr(i+1));
        vv.in(s.substr(i+1));
    }
    if(vv==multiset<string>(v.begin(), v.end())){
        rep(i,0,2*n-3){
            if(pr.count(v[i])){
                ans+='P';
                pr.erase(pr.find(v[i]));
            }
            else if(su.count(v[i])){
                ans+='S';
                su.erase(su.find(v[i]));
            }
            else{
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

int main(){
    reflex;
    string s,s1[3];
    cin>>n;
    int k=0;
    rep(i,1,(2*n)-2){
        cin>>s;
        v.pb(s);
        if(s.size()==n-1) s1[k++]=s;
    }
 //   
     if(check(s1[1],s1[0])) cout<<ans<<endl;
     else  if(check(s1[0],s1[1])) cout<<ans<<endl;
}
