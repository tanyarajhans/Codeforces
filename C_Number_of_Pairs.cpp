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


void solve(){
    ll n,l,r;
    cin>>n>>l>>r;
    vector<ll> a(n);
    multiset<int> st;
    st.insert(1e9);
    
    for(int i = 0;i<n;i++)
    cin>>a[i];
    
    ll ans=0;
    vector<ll> b;
    // for (int i = 0; i < n; i++) {
	// 	b.pb(a[i]);
	// }
//    for(int i=0;i<n;i++){
//         vector<ll> t = a;
//         sort(t.begin()+i+1, t.end());
//         ll x = l - a[i];
//         ll y = r - a[i];
//         st.insert(x);
//         ll x1 = lower_bound(t.begin() + i + 1, t.end(), x) - t.begin();
//         ll y1 = lower_bound(t.begin() + i + 1, t.end(), y) - t.begin();
//         if((a[i] + t[y1])==r)
//             ans+= y1-x1+1;
//         else
//             ans+= y1-x1;
//     }
    sort(a.begin(), a.end());
        int g=0, s=n-1, e=n-1;
		while(g<e){
            s=max(g, s);
           // int maxii=max(s,e);
			    while(s>g && a[g]>=l-a[s])
				 s--;
		while(e>s && a[g]>r-a[e])
			e--;
			ans+= e-s;
			g++;
	    }
    
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