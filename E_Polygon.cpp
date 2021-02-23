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

vector<int> adj[100001];
int vis[100001];
int out[100001];
bool res[100001];
int a[100001];
int leaves;

int dfs(int s, int m, int c){
    if(a[s]==1)
    c++;
    else
    c=0;
if(m<c || vis[s]==1){
    return 0;
}
vis[s]=1;
int p=0;
int k=adj[s].size();
if(k==1 && s>1){
    return 1;
}

for(int u=0;u<k;u++){
        int v=adj[s][u];
        p+=dfs(v, m, c);
     
}
return p;
}


int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n,m;
cin>>n>>m;

for(int i=1;i<=n;i++){
cin>>a[i];
}
for(int i=1;i<n;i++){
int x,y;
cin>>x>>y;
adj[x].pb(y);
adj[y].pb(x);
}
for(int i=1;i<=n;i++)
vis[i]=0;

cout<<dfs(1,m,0)<<endl;
return 0;
}