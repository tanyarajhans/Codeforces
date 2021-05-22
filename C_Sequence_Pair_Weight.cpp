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
ll g1(vector<ll> &a,ll n1){
 ll n = a.size();
 bool isok=true;
 ll t1=0,t2=0;
 vector<ll> pref(n,0);
 for(int i=0;i<n;i++)
  pref[i]=n1+1-a[i];
 for(int i=n-2;i>=0;i--)
  pref[i]=pref[i]+pref[i+1];
 
 bool f=false;
 ll ans= 0;
 for(int i=0;i<n;i++)
  if(i+1<n) 
  ans+=pref[i+1]*(a[i]);
 f=true;
 return ans;
}

ll g(ll d){
    if(d==1)
    return 0;
	if(d==2)
    return 1;
	return pow(2,d-3)*d*(d-1);
}

void solve(){
    ll n;
    cin>>n;
    ll a[n];
    map<ll,vector<ll> > mp;
    for(int i=0;i<n;i++)
    cin>>a[i];
    ll ans=0;
    ll c=1;
     vector<ll> x;
	 	
	// 	mp[a[i]]++;
	// 	ll t =0;
    map<ll,vector<ll> >::iterator ei;  
	for(int i=0;i<n;i++) 
    mp[a[i]].pb(i+1);
    for(ei=mp.begin();ei!=mp.end();ei++)
    ans+=g1(ei->s,n);
   

	cout<<ans<<endl;
}


int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
w(t){
solve();
}
return 0;
}