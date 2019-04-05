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
    cin>>n;
    int a[n];
    set<int> s;
    ffor(i,0,n) {cin>>a[i];s.insert(a[i]);}
    if(s.size()==1) cout<<"0\n";
    else{
    	auto it=s.rbegin();
    	it++;
    	cout<<*it<<endl;
    }
}
