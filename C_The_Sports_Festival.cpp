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

static bool comp(pair<ll, ll> &a, pair<ll, ll> &b){
    if(a.f!=b.f)
    return a.f>b.f;
    return a.s<b.s;
}

static bool comp2(pair<ll, ll> &a, pair<ll, ll> &b){
    if(a.s!=b.s)
    return a.s<b.s;
    return a.f<b.f;
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;
cin>>n;
ll a[n];
map<ll,ll> m;
for(int i=0;i<n;i++){
cin>>a[i];
m[a[i]]++;
}
vector<ll> ans;
vector<pair<ll, ll> > pq;
vector<ll> v;
map<ll,ll>:: iterator it;
for(it=m.begin();it!=m.end();it++){
    pq.pb(mp(it->s, it->f));
    if(it->s==1){
        v.pb(it->f);
    }
}
// while(!pq.empty()){
//     ll k=pq.top().s;
//     ll tt=pq.top().f;
//     while(tt--)
//     ans.pb(k);
//     pq.pop();
// // }
sort(pq.begin(), pq.end(), comp);
ll s=0;
// for(int i=0;i<n;i++)
// cout<<ans[i];
// if(m.size()<n){
    ll maxii=0;
    for(int i=0;i<pq.size();i++){
    ll k=pq[i].s;
    ll tt=pq[i].f;
    if(tt>1){
       while(tt--)
       ans.pb(k);
       if(maxii<k)
       maxii=k;
    }
    
    }
    

if(maxii==0){
    sort(a,a+n);
    ll s=0;
    for(int i=0;i<n;i++){
    ll maxi=0, mini=1e10;
    for(int j=0;j<=i;j++){
        if(a[j]>maxi)
        maxi=a[j];
        if(a[j]<mini)
        mini=a[j];
    
   }
   s+=maxi-mini;   
}
cout<<s<<endl;
}
else{

map<ll, ll> m1;
for(int i=0;i<v.size();i++){
    m1[v[i]]=abs(maxii-v[i]);
}

vector<pair<ll, ll> > pq1;
map<ll,ll>:: iterator it;
for(it=m1.begin();it!=m1.end();it++){
    pq1.pb(mp(it->s, it->f));
}

sort(pq1.begin(), pq1.end(), comp2);

for(int i=0;i<pq1.size();i++){
    ll d=pq1[i].s;
    ans.pb(d);
   // cout<<d;
}
for(int i=0;i<n;i++){
    ll maxi=0, mini=1e10;
    for(int j=0;j<=i;j++){
        if(ans[j]>maxi)
        maxi=ans[j];
        if(ans[j]<mini)
        mini=ans[j];
    
   }
   s+=maxi-mini;   
}

cout<<s<<endl;
}

// }
// else{
// reverse(ans.begin(), ans.end());
// for(int i=0;i<n;i++){
//     ll maxi=0, mini=1e10;
//     for(int j=0;j<=i;j++){
//         if(ans[j]>maxi)
//         maxi=ans[j];
//         if(ans[j]<mini)
//         mini=ans[j];
    
//    }
//    s+=maxi-mini;   
// }
// cout<<s<<endl;
// }

return 0;
}