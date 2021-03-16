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
string st;
cin>>st;
int b,s,c;
cin>>b>>s>>c;
int pb,ps,pc;
cin>>pb>>ps>>pc;
ll r;
cin>>r;
int xb=0,xs=0,xc=0;
for(int i=0;i<st.size();i++){
    if(st[i]=='B')
    xb++;
    else if(st[i]=='S')
    xs++;
    else
    xc++;
}
ll l=0, h=r+1000, ans=0;
while(l<=h){
    ll mid=(l+h)/2;
    ll eb=max(mid*xb-b,(ll)0);
    ll es=max(mid*xs-s,(ll)0);
    ll ec=max(mid*xc-c,(ll)0);

    ll tot=eb*pb+ec*pc+es*ps;

    if(tot==r){
        cout<<mid<<endl;
        return 0;
    }
    else if(tot>r)
    h=mid-1;
    else{
      l=mid+1;
      ans=mid;
    }
    
}
cout<<ans<<endl;

return 0;
}