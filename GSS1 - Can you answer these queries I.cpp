//Segment Trees
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define ff first 
#define ss second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define in(x) insert(x)
#define rep(i,a,b)  for (__typeof((b)) i=(a);i<=(b);i++)
#define nrep(i,a,b)  for (__typeof((b)) i=(b);i>=(a);i--)
#define ffor(i,a,b) for(int i=a;i<b;i++)
#define bfor(i,a,b) for(int i=a;i>=b;i--)
#define PI 3.14159265358979323846
#define SP(x) setprecision(x)
#define reflex ios_base::sync_with_stdio(false);cin.tie(NULL)

struct trees{
    ll sum, presum, sufsum, maxsum;
};

trees tree[4*(50006)];int n;
ll arr[50000+6];
void build(int node, int start, int end)
{
    if(start == end){
        tree[node].sum = tree[node].presum = tree[node].sufsum = tree[node].maxsum = arr[start];
    }
    else{
        int mid = (start + end) / 2;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        tree[node].sum=tree[2*node].sum + tree[2*node+1].sum;
        tree[node].presum = max(tree[2*node].presum, tree[2*node+1].presum + tree[2*node].sum);
        tree[node].sufsum = max(tree[2*node+1].sufsum, tree[2*node+1].sum + tree[2*node].sufsum);
        tree[node].maxsum = max(tree[node].presum, max(tree[node].sufsum, max(tree[2*node].maxsum, max(tree[2*node+1].maxsum, tree[2*node].sufsum+tree[2*node+1].presum))));
    }
}

trees query(int node, int start, int end, int l, int r){
     trees ans;
     ans.presum = ans.sufsum = ans.sum = ans.maxsum = INT_MIN;
    if(r < start || end < l){
        return ans;
    }
    if(l <= start && end <= r){
        return tree[node];
    }
    ll mid = (start + end) / 2;
    if(l > mid) return query(2*node+1, mid+1, end, l, r);
    if(r <= mid) return query(2*node, start, mid, l, r); 
    trees p1 = query(2*node, start, mid, l, r);
    trees p2 = query(2*node+1, mid+1, end, l, r);
    ans.sum=p1.sum + p2.sum;
    ans.presum = max(p1.presum, p2.presum + p1.sum);
    ans.sufsum = max(p2.sufsum, p2.sum + p1.sufsum);
    ans.maxsum = max(ans.presum, max(ans.sufsum, max(p1.maxsum, max(p2.maxsum, p1.sufsum + p2.presum))));
    return ans;
}

void solve(){
    int n;
    cin>>n;
    rep(i,1,n){cin>>arr[i];}
    build(1, 1, n);
    int q,a,b;
    cin>>q;
    while(q--){
        cin>>a>>b;
        trees ans=query(1,1,n,a,b);
        cout<<ans.maxsum<<endl;
    }  
}


int main(){
    reflex;
    int t;
    //cin>>t;
    t=1;
    while(t--){
        solve();
    }    
}
