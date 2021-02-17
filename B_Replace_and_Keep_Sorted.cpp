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





int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

    int n,q,k;
    cin>>n>>q>>k;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    while(q--){
        int l,r;
        cin>>l>>r;
        int li=a[l-1];
        int ri=a[r-1];
        int maxi=max(ri, k);
        int mini=1;
        int ans=0;
        
        ans+=li-1;
        ans+=maxi-ri;
        ans+=((a[r-1]-a[l-1]-1)-(r-l-1))*2;
        cout<<ans<<endl;
    }
    

return 0;
}