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
// int a[32];
// string s;
// string bin(ll n)
// {
//     if (n > 1)
//         bin(n >> 1);
 
//     s+=(n & 1);
//     return s;
// }
ll a[2003];
ll xorr(int x, int y){
    ll p=0;
for(int i=x;i<y;i++){
        p^=a[i];
        
    }
    return p;
}
 
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
w(t){
    ll n;
    cin>>n;
    
    set<int> s;
    bool f=false;
    // for(int i=0;i<n;i++)
    // a[i]=0;
    map<int, int> m;
    for(int i=0;i<n;i++){
    cin>>a[i];
    s.insert(a[i]);
    m[a[i]]++;
    if(a[i]==0)
    f=true;
    }
    ll p=0,ss=0,tt=0,g=0;
    for(int i=0;i<n;i++){
        p^=a[i];
        
    }
    

    // map<int, int>:: iterator it;
    // for(it=m.begin();it!=m.end();it++){
    //     if(it->s>2)
    //     g=true;
    // }
    // ll bits[32];
    // for(int i=0;i<32;i++)
    // bits[i]=0;

    // for(int j=0;j<n;j++){
    //     ll v=a[j];
    //    for(int i=31;i>=0;i--){
        
    //         if((v & (1 << (i))))
    //         bits[i]++;
    //     }
        

    // }
    // bool k=false;
    // for(int i=31;i>=0;i--){
    //     if(bits[i]%2==1)
    //     k=true;
    // }
     bool is = false;
         for(int i=0;i<n-1;i++) {
          long x1 = 0;
          for(int j=0;j<=i;j++) x1 = x1 ^ a[j];
          long x2 = 0, cnt = 0;
          for(int j=i+1;j<n;j++) {
           x2 = x2 ^ a[j];
           if(x2 == x1) {
            x2 = 0;
            cnt++;
           }
          }
          if(x2 == 0 && cnt>0) {
           is = true;
          }
         }
         if(is) 
          cout<<"YES";
          else
          cout<<"NO";
    
    cout<<endl;
 
}
return 0;
}