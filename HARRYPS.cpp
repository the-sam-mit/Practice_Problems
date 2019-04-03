//Inportant: Note that Fibo[N+1]= (r=0 to floor(N/2))∑(N-R C R).....Property of Fibonacci Series
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
const ll M=1e6+3;
ll fact[M+2];
long long int power(long long int a,long long int b){
    if(b==0)
        return 1;
    if(b==1)
        return a;
    if(b%2==0){
        long long int x=power(a,b/2);
        return((x*x)%M);
    }
    else{
        long long int x=power(a,b/2);
        x=(x*x)%M;
        return((x*a)%M);
    }
}

long long int NCR(long long n,long long r){
    long long int x=fact[n];
    long long int y=fact[r];
    long long int z=fact[n-r];
    x=(x*power(y,M-2))%M;
    x=(x*power(z,M-2))%M;
    return x;
}


long long int Lucas(long long int a,long long int b){
    if(a==0 || b==0)
        return 1;
    long long int c=a%M;
    long long int d=b%M;
    if(c<d)
        return 0;
    return(Lucas(a/M,b/M)*NCR(c,d));
}
void multiply(ll F[2][2], ll A[2][2]){
    ll x = ((F[0][0]*A[0][0]%M) + (F[0][1]*A[1][0]%M))%M;
    ll y = ((F[0][0]*A[0][1]%M) + (F[0][1]*A[1][1]%M))%M;
    ll z = ((F[1][0]*A[0][0]%M) + (F[1][1]*A[1][0]%M))%M;
    ll w = ((F[1][0]*A[0][1]%M) + (F[1][1]*A[1][1]%M))%M;
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;    
}

void mat_expo(ll F[2][2], ll n){
    if(n==0 || n==1) return;
    ll A[2][2] = {{1,1},{1,0}};
    mat_expo(F, n/2);
    multiply(F,F);
    if(n%2!=0) multiply(F, A);
}

ll fib(ll n){
    ll F[2][2]={{1,1},{1,0}};
    if(n==0) return 0;
    mat_expo(F,n-1);
    return F[0][0];
}

int main(){
    fact[0]=1;
    for(long long int i=1;i<=M;i++)
        fact[i]=(fact[i-1]*i)%M;
    int q;
    cin>>q;
    ll den=power(2,M-2);
    while(q--){
        int n;
        cin>>n;
        ll ans=0;
        if(n%2==1) ans=(power(2,n)*den)%M;
        else ans=((( (power(2,n) + Lucas(n,n/2))%M )*den)+M)%M;
        ans=(ans-fib(n+1)+M)%M;
        cout<<ans<<endl;
    }
}
