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

void solve(){
int n;
  cin>>n;
  int a[n];
  ll s=0;
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
    s+=a[i];
  }
  if(s%2==1){
    cout<<0<<endl;
    return;
   }
    ll dp[s/2 + 1][n + 1]; 
    memset(dp, 0, sizeof(dp));
    me(i, 0, n+1)
        dp[0][i] = 1;
    me(i, 1, s/2 + 1)
    {
        me(j, 1, n + 1)
        {
            dp[i][j] = dp[i][j - 1];
            if (i >= a[j - 1])
                dp[i][j] = max(dp[i][j], dp[i - a[j - 1]][j - 1]);
        }
    }
    if (dp[s/2][n] == 0)
    {
        cout<<0<<endl;
        return;
    }
    me(j, 0, 13)
    {
        me(i, 0, n)
        {
            if (a[i] % 2 != 0)
            {
                cout<<1<<endl;
                cout<<i + 1<<endl;
                return;
            }
            else
            {
                a[i] /= 2;
            }
        }
    }
 
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
ll t=1;
while(t--){

  solve();
  
}
return 0;
}