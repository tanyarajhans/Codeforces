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
int dis[100001];
void dfs(int s){
vis[s]=1;
for(int u=0;u<adj[s].size();u++){
    int v=adj[s][u];
    if(vis[v]==0){
        dfs(v);
    }
}
}

void bfs(int s){
    dis[s]=0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
            int curr=q.front();
            q.pop();
            vis[curr]=1;
            for(int i=0;i<adj[curr].size();i++){
                int v=adj[curr][i];
                if(!vis[v]){
                    vis[v]=1;
                    dis[v]=dis[curr]+1;
                    q.push(v);
                }
            }
    }
}

int solve(int n, int m){
    if(n==m)
    return 0;
return min(solve(n*2,m)+1, solve(n-1,m)+1);
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n,m;
cin>>n>>m;

for(int i=1;i<=2*m;i++){
vis[i]=0;
adj[i].pb(2*i);
adj[i].pb(i-1);
}
bfs(n);
if(m<n)
cout<<n-m<<endl;
else{
    int ans=0;
    while(n<m){
     if(m%2==0){
         m=m/2;
         ans++;
     }
     else{
         m++;
         ans++;
     }
    }
    cout<<n-m+ans<<endl;
}
return 0;
}