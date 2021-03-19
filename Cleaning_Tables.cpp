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
    int n,m;
    cin>>n>>m;
    int a[m];
    int occ=0;
    int ans=0;
    vector<vector<int> > v(405);
    for(int i=0;i<m;i++){
     cin>>a[i];
     v[a[i]].push_back(i);

    }
    set<int> s;
    for(int i=0;i<m;i++){
        if(s.size()<n){
            if(s.find(a[i])==s.end()){
                s.insert(a[i]);
                ans++;
            }
        }
        else{
            if(s.find(a[i])==s.end()){
            ans++;
            bool f=false;
            int maxi=-1,maxind=-1;
            set<int>::iterator it;
            for(it=s.begin(); it!=s.end();it++){
                int k=*it;
                if(lower_bound(v[k].begin(), v[k].end(), i)==v[k].end()){
                    f=true;
                    s.erase(k);
                    break;
                }
                else{
                    int p=*lower_bound(v[k].begin(), v[k].end(), i);
                    if(p>maxi){
                        maxi=p;
                        maxind=k;
                    }
                }
            }
            if(f==false){
                s.erase(maxind);
                
            }
            s.insert(a[i]); 
            }
        }
    }
       cout<<ans<<endl;  
    }
    

return 0;
}