// Ad-Hoc
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
    int a[n], freq[212345]={0};
    vector<int> v1, v2;
    ffor(i,0,n){
    	cin>>a[i];
    	if(freq[a[i]]==2){cout<<"NO\n";return 0;}
    	if(freq[a[i]]!=0) v2.pb(a[i]);
    	else v1.pb(a[i]);
    	freq[a[i]]++;
    }
    cout<<"YES\n";
    sort(v1.begin(), v1.end());
    cout<<v1.size()<<endl;
    ffor(i,0,(int)v1.size()){cout<<v1[i]<<" ";}
    cout<<endl;
    sort(v2.rbegin(), v2.rend());
    cout<<v2.size()<<endl;
    ffor(i,0,(int)v2.size()){cout<<v2[i]<<" ";}
    cout<<endl;
}
