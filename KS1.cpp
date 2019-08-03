	#include<bits/stdc++.h>
	using namespace std;
	#define ll long long
	#define pll pair<ll,ll> 
	#define mp make_pair
	#define ff first
	#define ss second
	int main(){
		ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
		int t;
		cin>>t;
		while(t--){
			int n;
			cin>>n;
			ll a[n+2], xorr[n+2]={0};
			for(int i=1;i<=n;i++){
				cin>>a[i];
				xorr[i]=0;
			}
			xorr[0]=0;
			// cout<<endl;
			for(int i=1;i<=n;i++){
				xorr[i]=xorr[i-1]^a[i];
				// cout<<xorr[i]<<" ";
			}
			// cout<<endl;
			unordered_map<int,ll> cnt, ans, upd, ms;
			cnt[0]=1;
			for(int i=1;i<=n;i++){
				int num = xorr[i];
				if(num == 0 && cnt[num]==1){
					ll up1 = ((i-1-ms[num])) + upd[num] + max(cnt[num]-1,0ll);
					cnt[num]++;
					ms[num] = i;
					upd[num] = up1;
					ans[num] += upd[num];
				}
				else if(num == 0){
					ll up2 = (cnt[num]*(i-1-ms[num])) + upd[num] + max(cnt[num]-1,0ll);
					cnt[num]++;
					ms[num] = i;
					upd[num] = up2;
					ans[num] += upd[num];
				}
				else if(cnt[num]!=0){
					//cnt = i-1
					ll up2 = (cnt[num]*(i-1-ms[num])) + upd[num] + max(cnt[num]-1,0ll);
					cnt[num]++;
					ms[num] = i;
					upd[num] = up2;
					ans[num] += upd[num];
				}
				else{
					cnt[num]++;
					ms[num] = i;
					upd[num] = 0;
					ans[num] = 0;
				}
			}
			ll Ans=0;
			for(auto  it:ans){
				Ans += it.ss;
			}
			cout<<Ans<<endl;
		}
	}
