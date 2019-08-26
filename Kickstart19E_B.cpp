//Solved partially. Requires reviewing.

#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll minPrime[1000003];
void sieve(){
	for (int i = 2; i * i <= 1000001; ++i) {
        if (minPrime[i] == 0) {
            for (int j = i * i; j <= 1000001; j += i) {
                if (minPrime[j] == 0) {
                    minPrime[j] = i;
                }
            }
        }
    }
    for (int i = 2; i <= 1000001; ++i) {
        if (minPrime[i] == 0) {
            minPrime[i] = i;
        }
    }
}


int main(){
	int t;
    cin>>t;
    sieve();
    for(int zc =1;zc<=t;zc++){
    	long long l,r;
    	cin>>l>>r;
    	ll ans=0,sum=0;
    	for(ll i=l;i<=r;i++){
    		ll num = i;
    		map<ll,ll> ms;
    		ans = 0;
    		ll tot = 0;
    		while(num>1){
    			if(minPrime[num]!=2) ms[minPrime[num]]++;
    			else tot++;
    			num = num/minPrime[num];
    			// cout<<num<<endl;
    		}
    		ans = 1;
    		for(auto it: ms){
    			ans = ans * (it.second+1);
    		}
    		if(tot>0){
    			tot = ans*(tot+1);
    		}
    		else tot=ans;
    		// cout<<tot<<" "<<ans<<endl;
    		if(abs((tot-ans)-ans)<=2) sum++;
    	}
    	cout<<"Case #"<<zc<<": "<<sum<<endl;
    }
    return 0;
}
