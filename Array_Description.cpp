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

int solve(int n, int m, vector<int> &t){
   int dp[n+2][m+2];
   memset(dp,0,sizeof(dp));
   int ans=0;
   for(int i=1;i<=n;i++){
       for(int x=1;x<=m;x++){
           if(i==1){
              if(t[i]==0 || t[i]==x)
               dp[i][x]=1;
               else
               dp[i][x]=0;
           }
           else{
               if(t[i]==0 || t[i]==x)
                 dp[i][x]=((dp[i-1][x-1]+dp[i-1][x])%mod+dp[i-1][x+1])%mod;
                 else
                 dp[i][x]=0;
           }
       }
   }
   for(int x=1;x<=m;x++){
       ans=(ans+dp[n][x])%mod;
   }
   return ans;
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n,m;
cin>>n>>m;
vector<int> t(n+1);
t[0]=0;
for(int i=1;i<n+1;i++)
cin>>t[i];
cout<<solve(n,m,t);
return 0;
}