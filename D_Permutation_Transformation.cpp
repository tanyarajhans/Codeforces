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
#define pii              pair<int,int>b              priority_queue<int>
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

ll ans[105];
ll a[105];
void solve(ll l, ll r, ll level){
    ll maxi=0;
    ll ind=0;
    if(l>r)
    return;
    for(int i=l;i<=r;i++){
        if(a[i]>maxi){
            maxi=a[i];
            ind=i;
        }
    }
    ans[ind]=level;
    solve(l, ind-1, level+1);
    solve(ind+1, r, level+1);
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
cin>>t;
while(t--){
    ll n;
    cin>>n;
    for(int i=0;i<n;i++){
       cin>>a[i];
    }
    solve(0,n-1,0);
    for(int i=0;i<n;i++){
       cout<<ans[i]<<" ";
    }
   cout<<endl;
}
return 0;
}