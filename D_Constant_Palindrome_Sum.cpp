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
#define int             long long
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



signed main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
cin>>t;
while(t--){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
    cin>>a[i];
    }
    vector<pair<int,int> > v;
    for(int i=0;i<n/2;i++){
    v.pb(mp(min(a[i],a[n-i-1]), max(a[i], a[n-i-1])));
    }
    int pre[100005];
    for(int i=0;i<(2*k)+10;i++){
        pre[i]=0;
    }
    unordered_map<int,int> m;
    for(int i=0;i<v.size();i++){
    int l=v[i].f+1;
    int r=v[i].s+k;
    m[v[i].f+v[i].s]++;
    pre[l]++;
    pre[r+1]--;
    }
    int s=0;
    for(int i=0;i<2*k+10;i++){
        s+=pre[i];
        pre[i]=s;
    }
    int mini=n;
    for(int i=2;i<=2*k;i++){
        int c1=pre[i]-m[i];
        int c2=m[i];
        int c3=(n/2)-c2-c1;
        mini=min(mini,c1+(c3*2));
    }
    cout<<mini<<endl;
}
}