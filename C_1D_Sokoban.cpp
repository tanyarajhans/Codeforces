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

ll solve(vi &a, vi &b)
{
    int n = a.size(), m = b.size(), ans = 0;
    int preb[m];
    me(i, 0, m)
    preb[i]=0;
    map<ll, ll> mpp;
    me(i, 0, n)
        mpp[a[i]]++;
    me(i, 0, m)
    {
        if (mpp.find(b[i]) != mpp.end())
            preb[i]++;
        if (i != 0)
            preb[i] += preb[i - 1];
    }
    me(i, 0, m)
    {
        int ind1 = upper_bound(a.begin(), a.end(), b[i]) - a.begin();
        int left_b = b[i] - ind1 + 1;
        int ind3 = lower_bound(b.begin(), b.end(), left_b) - b.begin();
        ind3--;
        ans = max(ans, min(i - ind3, ind1) + preb[m - 1] - preb[i]);
    }
    if (m > 0)
        ans = max(ans, preb[m - 1]);
    return ans;
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);int t;
cin>>t;
while(t--){
    int n,m;
    cin>>n>>m;
    int a[n];
    int b[m];
    vector<int> posa;
    vector<int> nega;
    vector<int> posb;
    vector<int> negb;
    for(int i=0;i<n;i++){
    cin>>a[i];
    if(a[i]>0)
    posa.pb(a[i]);
    else
    nega.pb(-a[i]);
    }
    
    for(int i=0;i<m;i++){
    cin>>b[i];
    if(b[i]>0)
    posb.pb(b[i]);
    else
    negb.pb(-b[i]);
    }
    sort(nega.begin(), nega.end());
    sort(negb.begin(), negb.end());
    cout<<solve(posa,posb)+solve(nega,negb)<<endl;
}
return 0;
}