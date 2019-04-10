//Lazy Propogation - Segment Trees
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
ll tree[4*(110000+6)]={0};
ll lazy[4*(110000+6)]={0};
ll arr[100000+6];
void build(int start, int end, int node){
    if(start > end) return;
    if(start == end) tree[node] = arr[start];
    else{
        int mid = (start+end)/2;
        build(start, mid, 2*node);
        build(mid+1, end, 2*node+1);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

ll query(int start, int end, int l, int r, int node){
    if(r < start || l > end || start > end) return 0;
    if(lazy[node]!=0){
        tree[node] += lazy[node]*(end-start+1);
        if(start != end){
            lazy[2*node] += lazy[node];
            lazy[(2*node)+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(l <= start && end <= r) return tree[node];
    int mid = (start + end)/2;
    ll p1 = query(start, mid, l, r, 2*node);
    ll p2 = query(mid+1, end, l, r, 2*node+1);
    return p1 + p2;
}

void update(int start, int end, int qs, int qe, int node, ll val){
    if(lazy[node]!=0){
        tree[node] += lazy[node]*(end-start+1);
        if(start != end){
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(start > end || qe < start || qs > end) return;
    if(start >= qs && end <= qe){
        tree[node] += val*(end-start+1);
        if(start != end){
            lazy[2*node] += val;
            lazy[2*node+1] += val;
        }
        return;
    }
    int mid = (start + end)/2;
    update(start, mid, qs, qe, 2*node, val);
    update(mid+1, end, qs, qe, 2*node+1, val);
    tree[node] = tree[2*node] + tree[2*node+1];
}
void solve(){
    int n;
    cin>>n;
    rep(i,1,440000){lazy[i]=0;tree[i]=0;}
    rep(i,0,n+1)arr[i]=0;
    build(1, 1, n);
    int q,a,b,ch;
    cin>>q;
    while(q--){
        cin>>ch;
        if(ch==0){
            ll val;
            cin>>a>>b>>val;
            update(1, n, a, b, 1, val);
        }
        else{
            cin>>a>>b;
            ll ans=query(1,n,a,b,1);
            cout<<ans<<endl;
        }
    }  
}


int main(){
    reflex;
    int t;
    cin>>t;
    //t=1;
    while(t--){
        solve();
    }    
}
