#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int cnt=0;
		for(int i=0;i<s.size();i++) if(s[i]=='1') cnt++;
		if(cnt%2==0) cout<<"LOSE\n";
		else cout<<"WIN\n";
	}
}
