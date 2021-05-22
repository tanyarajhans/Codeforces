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


int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
w(t){
ll n;
    cin>>n;
    ll a[n];
    ll b[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    for(int i=0;i<n;i++)
    cin>>b[i];
    // map<ll, vector<ll> > m;
    // for(int i=0;i<n;i++){
    //     m[a[i]].pb(b[i]);
    // }
    // map<ll, vector<ll> >::iterator it;
    // for(it=m.begin();it!=m.end();it++){
    //     sort(it->s.begin(), it->s.end());
    //     reverse(it->s.begin(), it->s.end());
    //     int nn=it->s.size();
    //     vector<ll> v(nn+1);
    //     v[0]=0;
    //     for(int i=1;i<=nn;i++)
    //     v[i]=v[i-1]+it->s[i-1];
    //     m[it->f]=v;
    // }
    // bool f=false;
    // for(int i=1;i<=n;i++){
    //  ll s=0;
    //  map<ll, vector<ll> >::iterator it;
    //  for(it=m.begin();it!=m.end();it++){
    //      int g=it->s.size()-1;
    //      int p=g/i;
    //      s+=it->s[p*i];
    //  }
    //  cout<<s<<" ";
    // }
    ll ans=0;
    vector<ll> c(n);
    for(int i=0;i<n;i++)
    {
        c[i]=a[i]*b[i];
    }
    for(int i=0;i<n;i++)
    ans+=c[i];
    for(int i=1;i<n;i++)
    c[i]+=c[i-1];
    for(int i=0;i<n;i++){
        vector<ll> a1, b1, c1;
        for(int j=i;j<n;j++){
          a1.pb(a[j]);
          b1.pb(b[j]);
        }
        for(int k=0;k<a1.size();k++)
        c1[k]=a1[k]*b1[k];
        for(int j=i;j<n;j++){
            if(j-i>=a1.size())
            continue;
            ll t;
            if(i>0)
            t=c[i-1];
            else
            t=0;
            t+= c1[j - i] + (c[n-1] - c[j]);
			//cout<<t<< " " << c.size() << "\n";
			ans = max(ans, t);
        }
    }

    cout<<ans<<endl;
}
return 0;
}