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
    int t;
    cin>>t;
    while(t--){
    	string s;
    	cin>>s;
    	sort(s.begin(), s.end());
    	set<char> st;
    	ffor(i,0,(int)s.size()){
    		st.insert(s[i]);
    	}
    	if((s[(int)s.size()-1] - s[0] + 1 )== (int)s.size() && st.size()==(int)s.size())
    	cout<<"Yes\n";
    	else cout<<"No\n";
    }		
}

