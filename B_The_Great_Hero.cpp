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
w(t){
    ll a,b,n;
    cin>>a>>b>>n;
    vector<pair<ll,ll> > m(n);
    for(int i=0;i<n;i++)
    cin>>m[i].f;
    for(int i=0;i<n;i++)
    cin>>m[i].s;
    sort(m.begin(), m.end());
    ll ans=0;
    bool f=false;
    for(int i=0;i<n;i++){
        if(b<=0){
            f=true;
            break;
            
        }
        ll t=0,ss=0;
        t=m[i].s/a;
        if(m[i].s%a)
        t++;
        ss=b/m[i].f;
        if(b%m[i].f)
        ss++;
        ll l=min(ss,t);
        b-=l*m[i].f;
        m[i].s-=l*a;
        
    }
    if(f==true){
      cout<<"NO"<<endl;
            continue;
    }
    if(m[n-1].s>0)
     cout<<"NO"<<endl;
     else
     cout<<"YES"<<endl;
}
return 0;
}