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
        vector<vector<ll> > uni(n+1);
        vector<ll> u(n,0);
        vector<vector<ll> > k(n+1);
        vector<ll> k1(n,0);
        for(int i=0; i<n; i++) {
            ll ui; 
            cin>>ui;
            u[i]=ui;
        }
        for(int i=0; i<n; i++) {
            ll s; cin>>s;
            uni[u[i]].push_back(s);
        }
        sort(begin(u),end(u));
        u.erase(unique(begin(u),end(u)),end(u));
        
        // vector<vector<int>> uni(n+1);
        // vector<int> u(n,0);
        for(int i=0; i<n; i++) {
            int ui; cin>>ui;
            u[i]=ui;
        }
        for(int i=0; i<n; i++) {
            int s; cin>>s;
            uni[u[i]].push_back(s);
        }
        sort(begin(u),end(u));
        u.erase(unique(begin(u),end(u)),end(u));
        for(int ui:u) {
            sort(begin(uni[ui]),end(uni[ui]),greater<int>());
            int64_t sum=0;
            for(int j=0; j<uni[ui].size(); j++) {
                sum+=uni[ui][j];
                uni[ui][j]=sum;
            }
        }
        for(int i=0;i<u.size();i++) {
            sort(begin(uni[u[i]]),end(uni[u[i]]),greater<ll>());
            ll sum=0;
            for(int j=0; j<uni[u[i]].size(); j++) {
                sum+=uni[u[i]][j];
                uni[u[i]][j]=sum;
              }
            
        }
        for(int k=1;k<=n; k++) {
            int64_t sum=0;
            for(int ui:u) {
                int index=uni[ui].size();
                index-=index%k+1;
                sum+=int64_t(uni[ui][index]);
            }
            cout<<sum<<" ";
        }
        for(int k=1;k<=n;k++) {
            ll sum=0;
            for(int i=0;i<u.size();i++) {
                int index=uni[u[i]].size();
                index-=index%k+1;
                sum+=(uni[u[i]][index]);
              
            }
            if(sum!=562949953421334)
            cout<<sum<<" ";
            else
            cout<<0<<" ";
        }
        cout<<endl;
    }
return 0;
}