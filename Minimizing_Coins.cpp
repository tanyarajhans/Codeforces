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


int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;
cin>>n;
int t[n][n];
int dp[n][n];
memset(dp,0,sizeof(dp));
memset(t,0,sizeof(t));
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        char ch;
        cin>>ch;
        if(ch=='.')
        t[i][j]=1;
        else
        t[i][j]=0;
    }
}

if(t[n-1][n-1]==1){
    dp[n-1][n-1]=1;
}
for(int i=n-2;i>=0;i--){ //last column
    if(t[i][n-1]==0)
    dp[i][n-1]=0;
    else{
        dp[i][n-1]+=dp[i+1][n-1];
    }
}
for(int i=n-2;i>=0;i--){ //last row
    if(t[n-1][i]==0)
    dp[n-1][i]=0;
    else{
        dp[n-1][i]+=dp[n-1][i+1];
    }
}

for(int i=n-2;i>=0;i--){
    for(int j=n-2;j>=0;j--){
        if(t[i][j]==0)
        dp[i][j]=0;
        else
        dp[i][j]+=(dp[i+1][j]%mod+dp[i][j+1]%mod)%mod;
    }
}
cout<<dp[0][0]<<endl;
return 0;
}