#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007

ll k;
int b[5];
vector<ll> a;

vector<vector<ll> > mul(vector<vector<ll> > A, vector<vector<ll> > B){
    vector<vector<ll> > C(k+1, vector<ll>(k+1));
    for(int i = 1;i<=k;i++){
        for(int j = 1;j<=k;j++){
            for(int x = 1;x<=k;x++)
                C[i][j] = (C[i][j] + ((A[i][x]*B[x][j])%M) + M) % M;

            }
        }
        return C;
    }

vector<vector<ll> > pow(vector<vector<ll> > A, ll p){
    if(p == 1)
        return A;
    if(p & 1)
        return mul(A,pow(A,p-1));
    vector<vector<ll> > X = pow(A,p/2);
        return mul(X,X);
}

ll func(ll n){

    if(n == 0)
        return 0;
    if(n <= 2)
        return b[n];

    vector<ll> F1(k+1);
    F1[1]=3;F1[2]=1;
    
    vector<vector<ll> > T(k+1,vector<ll>(k+1));
    T[1][1]=3;T[1][2]=-1;
    T[2][1]=1;T[2][2]=0;
    T = pow(T,n-2);

    ll res = 0;
    for(int i = 1;i<=k;i++){
        res = (res + ((T[1][i]*F1[i])%M) +M) % M;
    }
    return res % M;
}

int main(){
    ll t,n,a;
    cin>>t;
    while(t--){
        b[1]=1;b[2]=3;
        k=2;
        cin>>n;
        if(n==1){
            cout<<"0\n";
            continue;
        }
        if(n==2){
            cout<<"1\n";
            continue;
        }
        if(n>=3) printf("%lld\n",(func(n)-n+M+M)%M);
    }
    return 0;
}