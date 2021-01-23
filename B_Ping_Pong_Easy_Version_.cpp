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
vector<int> g[105];
bool vis[105];
void dfs(int a, int b, bool f){
    vis[a]=1;
    if(a==b)
    {
        f=true;
        return;
    }
    for(int i : g[a]){
        if(vis[i]==0){
            dfs(i,b,f);
        }
    }
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;
cin>>n;
vector<pii> v;
while(n--){
    int x,a,b;
    cin>>x>>a>>b;
    if(x==1){
        for(int i=0;i<v.size();i++){
            if((v[i].f<a && a<v[i].s) || (v[i].f<b && b<v[i].s))
            g[v.size()].pb(i);
            if((a<v[i].f && v[i].f<b) || (a<v[i].s && v[i].s<b))
            g[i].pb(v.size());
        }
        v.pb(mp(a,b));
    }
    else{
        a=a-1;
        b=b-1;
        for(int i=0;i<105;i++)
            vis[i]=0;
        bool f=false;
        dfs(a,b, f);
        if(f)
        cout<<"YES"<<endl;
        else
        {
            cout<<"NO"<<endl;
        }
        
    }
}
return 0;
}