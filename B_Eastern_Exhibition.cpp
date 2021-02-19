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
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    vector<pair<int, int> > v;
    
    set<int> sx;
    set<int> sy;
    int maxx=0;
    int maxy=0;
    int miny=INT_MAX;
    int minx=INT_MAX;

    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        v.push_back(mp(x, y));
        maxx=max(maxx,x);
        sx.insert(x);
        sy.insert(y);
        maxy=max(maxy,y);
        minx=min(minx,x);
        miny=min(maxy,y);
    }
    int mini=INT_MAX;
    unordered_map<int, int> m;
    set<int>::iterator itr1; 
    set<int>::iterator itr2; 
    for(itr1 = sx.begin(); itr1 != sx.end(); itr1++){
        for(itr2 = sy.begin(); itr2 != sy.end(); itr2++){
            int xi=*itr1;
            int yi=*itr2;
            ll sum=0;
            for(int k=0;k<n;k++){
                 sum+=abs(v[k].f-xi) + abs(v[k].s-yi);
            }
            if(sum<mini){
               mini=sum;
               
            }
            m[sum]++;
        }
    }
    
    if(s1.size()!=s2.size())
    cout<<abs(s1.size()-s2.size());
    else{
         unordered_map<int, bool> b;
    }
    
 
   cout<<m[mini]<<endl;
    
}

return 0;
}