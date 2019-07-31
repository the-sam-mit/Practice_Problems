#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

#define For(i,s,e) for(int i=(s);i<=(e);i++)
#define mp(a,b) make_pair((a),(b))
#define M 1000000007
#define INF 1000000000
#define MaxN 100005
int visited[MaxN];
vector<pair<int,ll> > graph[MaxN];
ll sum1[MaxN] , sum2[MaxN],N,sub[MaxN];
void dfs1( int root )
{
    visited[root] = 1;
    sub[root] = 0;
    for(auto it = graph[root].begin();it!=graph[root].end();it++){
        if( visited[(*it).first] )  continue;
        else{
                dfs1((*it).first);
                sub[root] += sub[(*it).first];
                sub[root]%=M;
                sum1[root] += ((sum1[(*it).first] + (ll)(*it).second*sub[(*it).first])%M);
                sum1[root]%=M;
        }
    }
    sub[root]++;
}
void dfs2(int root)
{
    if (root == 1){
        sum2[root] = sum1[root];
    }
    visited[root] = 1;
    for(auto it = graph[root].begin();it!=graph[root].end();it++){
        if( visited[(*it).first] )  continue;
        else{
            sum2[(*it).first] = (sum1[(*it).first] + ((sum2[root] - sum1[(*it).first] - (*it).second*sub[(*it).first] + M + M)%M) + ((((*it).second)%M)*(((ll)N-sub[(*it).first]+M)%M)%M)+M)%M;
            dfs2((*it).first);
        }
    }
}
int sumN;
void solve()
{
    int x,y;ll z;
    scanf("%lld",&N);
    assert(N<=100000 && N>=2);
    sumN += N;
    for(int i=1;i<=N;i++)   graph[i].clear(),sum1[i] = sum2[i] = 0;
    for(int i=1;i<N;i++){
        scanf("%d%d%lld",&x,&y,&z);
        assert(x<=N && y<=N);
        assert(1<=z && z<=INF);
        graph[x].push_back(make_pair(y,z));
        graph[y].push_back(make_pair(x,z));
    }
    for(int i=1;i<=N;i++)   visited[i] = 0;
    dfs1(1);
    for(int i=1;i<=N;i++)   visited[i] = 0;
    dfs2(1);
    for(int i=1;i<=N;i++)   printf("%lld\n",(sum2[i]*2)%M);
}
int main()
{
    sumN = 0;
    solve();
    
}
//Reference: https://www.hackerrank.com/contests/101hack22/challenges/sum-of-all-distances/
