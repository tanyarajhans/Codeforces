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

vector<int> op(int n, int p){
    vector<int> z;
    if(p<n-1)
        return z;
    vector<int> ans;
    int t=0,c=1;
    for(int i=n-1;i>0;i--){
         c++;
         if(t+c+i-1>=p){
             int r=p-t-i+1;
             ans.pb(r);
             for(int k=0;k<=i-2;k++){
                 ans.pb(1);
             }
             t=p;
             break;
         }
         t+=c;
         ans.pb(c);
    }
    if(t<p)
      return z;
    return ans;
}

vector<int> op1(vector<int> &a, vector<int> &k){
    int l=k.size();
    vector<int> b;
    for(int i=0;i<l;i++){
        int o=a.size();
        int t=o-i-2;
        int ss=t+k[i];
        for(int j=t;j<ss;j++)
        b.pb(a[j]);
        reverse(b.begin(), b.end());
        for(int j=t;j<ss;j++)
        a[j]=b[j-t];
        b.clear();
    }
    return a;
    
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int cn = 1;
w(t){

       int n,c;
        cin >> n >> c;

        vector<int> a(n);

        for(int i=0; i<n; i++)
        {
            a[i]=i+1;
        }

        vector<int> k(op(n,c));
        vector<int> l(op1(a,k));
        
        string ans="";
        if(k.size()>0){
            for(int i=0;i<l.size();i++){
                ans+=to_string(l[i])+" ";
            }
        }
        else
        ans="IMPOSSIBLE";

        
      cout << "Case #" << cn << ": " << ans << endl;
       cn++;
    }

return 0;
}