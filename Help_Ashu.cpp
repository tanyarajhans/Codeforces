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
// (odd, even)
pair<int, int> st[400004];
int a[100001];

void buildTree(int si, int ss, int se){
    if(ss==se){
        if(a[ss]%2==0)
        st[si]=mp(0, 1); 
        else
        st[si]=mp(1, 0);
        return;
    }
    int mid=(ss+se)/2;
    buildTree(2*si, ss, mid);
    buildTree(2*si+1, mid+1, se);

    st[si].f=(st[2*si].f + st[2*si+1].f);
    st[si].s=(st[2*si].s + st[2*si+1].s);
}

// int query(int si, int ss, int se, int qs, int qe){
//     if(qs>se || qe<ss)
//     return INT_MAX;

//     if(qs<=ss && se<=qe)
//     return st[si];

//     int mid=(ss+se)/2;
//     int l=query(2*si, ss, mid, qs, qe);
//     int r=query(2*si+1, mid+1, se, qs, qe);

//     return min(l,r);

// }

void update(int si, int ss, int se, int qi, int val){
if(ss==se){
    if(a[ss]%2==0) //if prev value was even, new value must be odd
        st[si]=mp(1,0);
    else
        st[si]=mp(0,1);
    a[ss]=val;
    return;
}
int mid=(ss+se)/2;
if(qi<=mid)
update(2*si, ss, mid, qi,val);
else
update(2*si+1, mid+1, se, qi, val);

st[si].f=(st[2*si].f + st[2*si+1].f);
st[si].s=(st[2*si].s + st[2*si+1].s);
}

int getEven(int si, int ss, int se, int qs, int qe){
    if(ss>qe || se<qs)
    return 0;
    if(ss>=qs && se<=qe)
    return st[si].s;
    int mid=(ss+se)/2;
    int l=getEven(2*si, ss, mid, qs, qe);
    int r=getEven(2*si+1, mid+1, se, qs, qe);
    return l+r;
}

void solve(){
   int n;
   cin>>n;
   for(int i=1;i<=n;i++)
   cin>>a[i];
   int q;
   cin>>q;
   buildTree(1,1,n);
   while(q--){
       int x,l,r;
       cin>>x>>l>>r;
       if(x==0){
        if((a[l]%2)==(r%2))
        continue;
        else
        update(1,1,n,l,r);
       }
       else if(x==1){
        cout<<getEven(1,1,n,l,r)<<endl;
       }
       else{
        cout<<(r-l+1)-getEven(1,1,n,l,r)<<endl;
       }
   } 
}


int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
{
solve();
}
return 0;
}