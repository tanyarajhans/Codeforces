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
    ll n;
    cin>>n;
    ll a1,a2,a3,b1,b2,b3;
    cin>>a1>>a2>>a3; //rock,sc,pap
    cin>>b1>>b2>>b3;
    ll c1=b1,c2=b2,c3=b3;
    ll ans1=0, ans2=0;
    if(a1>0){
        ll k;
        k=min(a1,b2);
        ans2+=k;
    }
    if(a2>0){
        ll k;
        k=min(a2,b3);
        ans2+=k;
    }
    
    if(a3>0){
        ll k;
        k=min(a3,b1);
        ans2+=k;
    }
    if(a1-n+b2 >0)
    ans1+=a1-n+b2;
    if(a2-n+b3>0)
    ans1+=a2-n+b3;
    if(a3-n+b1 >0)
    ans1+=a3-n+b1;

    
    cout<<ans1<<" "<<ans2<<endl;
return 0;
}