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
ll dp[100005];
vector<ll> v;

ll func(ll c){
ll cc=0;
for(int i=0;i<v.size();i++){
        while(c%v[i]==0){
            c/=v[i];
            cc++;
        }
    }
    cc+=(c!=1);
    return cc;
}


int lcm(int a, int b) { return a * b / gcd(a, b); }



int check_ps(ll n){
    double sqrt_n = sqrt(n);
    if(sqrt_n == int32_t(sqrt_n)){
        return 1;
    }
    else{
        return 0;
    }
}






void solve(){
    ll a,b,k;
    cin>>a>>b>>k;
    if(a==b && k==1){
            cout<<"NO"<<endl;
            return;
    }
    if(a!=b && k==0){
        cout<<"NO"<<endl;
        return;
    }

    map<int, int> mp;
    ll c=gcd(a,b);
    ll c1=a/c;
    ll c3=c;
    ll c2=b/c;
    
        ll mini=0, maxi=0;
        if(c1!=1)
            mini++;
        if(c2!=1)
            mini++;
    maxi+=func(a)+func(b);
    ll t1=0,t2=0;
    t1+=maxi;

        if(mini<=k && k<=maxi)
            cout<<"YES"<<endl;
    else
            cout<<"NO"<<endl;

}


int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
dp[0]=0;
dp[1]=0;
for(ll i=0;i<100005;i++)
    dp[i]=1;
    for(ll i=2;i<100005;i++){
          if(dp[i]==1){
            v.pb(i);
            for(ll j=2*i;j<100005;j+=i)
                dp[j]=0;
        }
}
w(t){
solve();
}
return 0;
}