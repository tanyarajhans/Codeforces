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
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    bool f=false;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int p=a[i][j];
            if(p>0){
                int c=0;
                if(i>0){
                 //   a[i-1][j]++;
                    c++;
                }
                if(i<n-1){
                 //   a[i+1][j]++;
                    c++;
                }
                if(j<m-1){
                  // a[i][j+1]++;
                    c++;
                }
                if(j>0 ){
                 //   a[i+1][j]++;
                    c++;
                }
                if(c<p){
                    f=true;
                    break;
                }
              }
            
        }
    }
    if(f)
    cout<<"NO"<<endl;
    else{
        
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i>0 && j>0 && i<n-1 && j<m-1)
                cout<<4<<" ";
                else if(i==0 && j==0)
                cout<<2<<" ";
                else if(i==n-1 && j==0)
                cout<<2<<" ";
                else if(i==0 && j==m-1)
                cout<<2<<" ";
                else if(i==n-1 && j==m-1)
                cout<<2<<" ";
                else if(i==0 || j==0 || i==n-1 || j==m-1)
                cout<<3<<" ";
            }
            cout<<endl;
        }
    }
}
return 0;
}