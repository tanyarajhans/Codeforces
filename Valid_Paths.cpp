// यो न हृष्यति न द्वेष्टि न शोचति न काङ्‍क्षति। शुभाशुभपरित्यागी भक्तिमान्यः स मे प्रियः॥
#include<iostream>
#include<vector>
#include<map>
#include<list>
#include<set>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>
#include<cmath>
#include<bitset>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<cstdlib>
#include<iomanip>
#define f               first
#define s              second
#define ll               long long
#define pb               push_back
#define mp               make_pair
#define pii              pair<int,int>
#define vi               vector<int>
#define mii              unordered_map<int,int>
#define pqb              priority_queue<int>
#define pqs              priority_queue< int,vi,greater<int> >
#define setbits(x)       __builtin_popcountll(x)
#define zrobits(x)       __builtin_ctzll(x)
#define mod              1000000007
#define inf              1e10
#define ps(x,y)          fixed<<setprecision(y)<<x
#define mk(arr,n,type)   type *arr=new type[n];
#define w(x)             int x; cin>>x; while(x--)
#define me(i,start,end)  for(int i=start;i<end;i++)
#define he(i,end,start) for(int i=end-1;i>=start;i--)
#define all(v)         v.begin(),v.end()

using namespace std;
ll pf[10000001];


// Tanya Rajhans
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b); 
     
}

   void prime(){
       memset(pf,0,10000001);
       pf[0]=pf[1]=1;
   for(ll i=2;i<10000001;i++){
        if(pf[i]==0){
            for(ll j=i*i;j<10000001;j=j+i)
                  pf[j]=1;
        }
    }
}

int lcm(int a, int b) { return a * b / gcd(a, b); }

int check_ps(ll n){
    double sqrt_n = sqrt(n);
    if(sqrt_n == int(sqrt_n)){
        return 1;
    }
    else{
        return 0;
    }
}

ll ans, ans1=0;
vector<ll> d;
vector<vector<ll> > adj;
vector<ll> t;

void dfs(ll node, ll p){
    d[node]=1;
    ll g=1;
    t[node]=1;
    bool f=true;
    ll s=0,v=0,c=0;
    for(int i=0;i<adj[node].size();i++){
        ll x=adj[node][i];
        ll k=0;
        if(x!=p){
            dfs(x, node);
            d[node]=(d[node]+(2*d[x])%mod)%mod;
            t[node]=(t[node]+t[x])%mod;
            c++;
            t[node]=(t[node]+d[x])%mod;
            s+=d[x];
        }
    }
    ll k1=0,k2=0;
    for(int i=0;i<adj[node].size();i++){
        ll x=adj[node][i];
        if(x!=p){
            f=false;
            t[node]+=(d[x]*((s-d[x]+mod)%mod))%mod;
            t[node]%=mod;
        }
    }
    if(f==false)
    k1++;
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
w(tt){
    ll n;
    cin>>n;
    t.clear();
    d.clear();
    adj.clear();
    bool isok=true;
   // for(int i=0;i<n;i++)
   // adj[i].clear();
    d.resize(n+1);
    t.resize(n+1);
    adj.resize(n+1);
    for(int i=0;i<n-1;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    map<int, int> mp;
    dfs(1,1);
    cout<<t[1]%mod<<endl;

}
return 0;
} 