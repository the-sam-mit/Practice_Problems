#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		long double k[n+1], c[n+1];
		for(int i=1;i<=n;i++) cin>>k[i];
		for(int i=1;i<=n;i++) cin>>c[i];
		long double den = 0.0;
		for(int i=1;i<=n;i++){
			den += (k[i]*c[i]);
		}
		if(den<0.0){
			cout<<"-1\n";
			continue;
		}
		else{
			long double num = 0.0;
			for(int i=1;i<=n;i++){
				num += (1.0/k[i]);
			}
			long double x[n+1];
			for(int i=1;i<=n;i++){
				x[i] = ((den/num) * (1/(k[i]*k[i]))) - c[i];
			}
			long double ans = num * den;
			ans = sqrt(ans);
			cout<<fixed<<setprecision(12)<<ans<<" ";
			for(int i=1;i<=n;i++){
				cout<<fixed<<setprecision(12)<<x[i]<<" ";
			}
			cout<<endl;
		}
	}
}
