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
    vector<ll> p;
    vector<ll> q;
    ll z=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>0)
        p.pb(a[i]);
        else if(a[i]<0)
        q.pb(a[i]);
        else
        z++;
    }
    sort(p.begin(), p.end());
    sort(q.begin(), q.end());
    ll v1=-1e18;
    if(p.size()>=5)
    {
        int k=p.size();
        if(p[k-1]*p[k-2]*p[k-3]*p[k-4]*p[k-5]> v1)
        v1=p[k-1]*p[k-2]*p[k-3]*p[k-4]*p[k-5];
        
    }
    if(p.size()>=4 && q.size()>=1){
        int k=p.size();
        int l=q.size();
        if(p[k-1]*p[k-2]*p[k-3]*p[k-4]*q[0] > v1)
         v1=p[k-1]*p[k-2]*p[k-3]*p[k-4]*q[0];
    }
    if(p.size()>=3 && q.size()>=2){
        int k=p.size();
        int l=q.size();
        if(p[k-1]*p[k-2]*p[k-3]*q[0]*q[1] > v1)
         v1=p[k-1]*p[k-2]*p[k-3]*q[0]*q[1];
    }
    if(p.size()>=2 && q.size()>=3){
        int k=p.size();
        int l=q.size();
        if(p[k-1]*p[k-2]*q[0]*q[1]*q[2] > v1)
         v1=p[k-1]*p[k-2]*q[0]*q[1]*q[2];
    }
    if(p.size()>=1 && q.size()>=4){
        int k=p.size();
        int l=q.size();
        if(p[k-1]*q[0]*q[3]*q[1]*q[2] > v1)
         v1=p[k-1]*q[0]*q[3]*q[1]*q[2];
    }
    if(q.size()>=5){
        int k=p.size();
        int l=q.size();
        if(q[l-5]*q[l-4]*q[l-3]*q[l-1]*q[l-2] > v1)
         v1=q[l-5]*q[l-4]*q[l-3]*q[l-1]*q[l-2];
    }

    if(v1>0)
    cout<<v1<<endl;
    else if(z>0)
    cout<<0<<endl;
    else
    cout<<v1<<endl;
}
return 0;
}