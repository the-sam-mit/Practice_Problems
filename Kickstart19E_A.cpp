#include<iostream>
#include<vector>
using namespace std;
long long xx=0;
vector <int> v[100000+2];
int vis[100000+2]={0};
void dfs(int x){
    vis[x]=1;
    xx++;
    for(int i=0;i<v[x].size();i++){
        if(vis[v[x][i]]==0){
            vis[v[x][i]]=1;
            dfs(v[x][i]);
        }
    }
}
 
const int SIZE = 100005;


int main(){
	int t;
    cin>>t;
    for(int zc =1;zc<=t;zc++){
    	int n,m,a,b;
	    cin>>n>>m;
	    for(int i=0;i<=100000;i++){
	    	v[i].clear();
	    	vis[i] = 0;	
	    } 
	    for(int i=0;i<m;i++){
	        cin>>a>>b;
	        v[a].push_back(b);
	        v[b].push_back(a);
	    }
	    long long cnt =0;
	    long long ans =0;
	    for(int i=1;i<=n;i++){
	    	if(vis[i]==0){
	    		xx=0;
	    		dfs(i);
	    		// cout<<"xx="<<xx<<endl;
	    		cnt++;
	    		ans += (xx-1);
	    	}
	    }
	    ans += ((cnt-1)*2ll);
	    // for(int i=1;i<=n;i++){
	    // 	if(vis[i]==1){
	    // 		ans+=1;
	    // 	}
	    // }
	    // cout<<ans<<endl;
	    // long long tot = max(0ll,ans-1) + ((n-ans)*2);
	    // if(m==0) tot = (2*(n-1));
    	cout<<"Case #"<<zc<<": "<<ans<<endl;
    }
    return 0;
}
