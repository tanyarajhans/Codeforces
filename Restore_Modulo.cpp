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
    int n,mx;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++){
  cin>>a[i];
  mx=max(a[i],(ll)mx);
    }
    
    set<int> s;
    if(n==1){
cout<<0<<endl;
continue;
    }
    if(n==2){
        if(a[0]==a[1])
        cout<<0<<endl;
            continue;
    }
    bool f=false;
    for(int i=0;i<n-1;i++){
      if(a[i]==a[i+1]){
          f=true;
          break;
      }
    }
    if(f==true){
        cout<<"-1"<<endl;
        continue;
    }
    int c=-1;
    if(a[1]>=a[0])
    c=a[1]-a[0];
    int maxi=-1;
    if(c!=-1)
    maxi=c+1;
    else{
        cout<<"-1"<<endl;
        continue;
    }
    ll l=2,h=mx*2-1,mid=0;
    while(l<h){
      mid=l+(h-l)/2;
      bool f=false;
      for(int i=2;i<n-1;){
        if((a[i]+c)%mid>a[i+1]){
            l=mid+1;
        }
        else {
          h=mid-1;
        }
      } 
    }
    cout<<mid<<" "<<c<<endl;
}
return 0;
}