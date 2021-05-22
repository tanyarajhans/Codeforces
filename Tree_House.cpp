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
#define int               long long
#define ll               long long
#define pb               emplace_back
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
#define he(i,end,start)  for(int i=end-1;i>=start;i--)
#define all(v)           v.begin(),v.end()

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

vector<int> adj[300005];
vector<pii> d;
vector<int> a,b,c;

void dfs(int node, int p=-1){
   for(auto u: adj[node]){
       if(u==p)
       continue;
       dfs(u, node);
   }
   bool is=true;
   d.clear();
   int l=1;
   for(auto u: adj[node]){
       bool g=true;
       if(u!=p)
       d.pb(a[u], u);
   }
   is=false;
   sort(d.rbegin(), d.rend());
   ll t1=2;
   int k=1;
   map<int, int> mp;
   for(auto [_b,y]:d){
       b[y]=k++;
   }
   t1++;
   for(auto u: adj[node]){
       mp[u]++;
       if(u!=p)
       a[node]+=(b[u]*a[u]);
   }

}

int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
w(t){
    int n,x;
    cin>>n>>x;
    a.assign(n,1);
    ll it=0;
    b.assign(n,0);
    it++;
    vector<int> xx;
    for(int i=0;i<n;i++)
    vector<int>().swap(adj[i]);
    ll dt=0;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    ll tt=0,gg=0,ff=0;
    dfs(0);
    bool fk=false;
    cout<<(a[0]%mod)*(x%mod)<<endl;
  }
}

