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
    char a[3][3];
    int m=0,n=0;
    ll e=0;
    ll x=0,o=0;
    for(int i=0;i<3;i++){
       for(int j=0;j<3;j++){
           cin>>a[i][j];
           if(a[i][j]=='X')
           x++;
           else if(a[i][j]=='O')
           o++;
           else if(a[i][j]=='_')
           e++;
       }
    }
    ll g=false;
    if(a[0][0]=='X' && a[1][0]=='X' && a[2][0]=='X')
       m=1;
    if(a[0][1]=='X' && a[1][1]=='X' && a[2][1]=='X')
       m=1;
    if(a[1][0]=='X' && a[1][1]=='X' && a[1][2]=='X')
       m=1;
    if(a[2][0]=='X' && a[2][1]=='X' && a[2][2]=='X')
       m=1;
    if(a[0][2]=='X' && a[1][1]=='X' && a[2][0]=='X')
       m=1;
    if(a[0][0]=='X' && a[0][1]=='X' && a[0][2]=='X')
       m=1;
    if(a[0][2]=='X' && a[1][2]=='X' && a[2][2]=='X')
       m=1;
    if(a[0][0]=='X' && a[1][1]=='X' && a[2][2]=='X')
       m=1;
    
    ll f=false;
    ll k=1;
    if(a[0][0]=='O' && a[1][0]=='O' && a[2][0]=='O')
       n=1;
    if(a[0][1]=='O' && a[1][1]=='O' && a[2][1]=='O')
       n=1;
    if(a[1][0]=='O' && a[1][1]=='O' && a[1][2]=='O')
       n=1;
    if(a[2][0]=='O' && a[2][1]=='O' && a[2][2]=='O')
       n=1;
    if(a[0][2]=='O' && a[1][1]=='O' && a[2][0]=='O')
       n=1;
    if(a[0][0]=='O' && a[0][1]=='O' && a[0][2]=='O')
       n=1;
    if(a[0][2]=='O' && a[1][2]=='O' && a[2][2]=='O')
       n=1;
    if(a[0][0]=='O' && a[1][1]=='O' && a[2][2]=='O')
       n=1;
    
    if((m==1 && n==1) || (x-o<0) || (x-o>1))
    cout<<3<<endl;
    else if(x==0 && o==0 && e==9)
    cout<<2<<endl;
    else if(x>o && m==1 && n==0)
    cout<<1<<endl;
    else if(x==o && m==0 && n==1)
    cout<<1<<endl;
    else if(e==0 && m==0 && n==0)
    cout<<1<<endl;
    else if(e>0 && m==0 && n==0)
    cout<<2<<endl;
    else
    cout<<3<<endl;
    
}
return 0;
}