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


using namespace std;
int R(int mi,int ma,string S,int k)
{
    if(ma-mi<=k)
    return 0;
    int mid = (ma + mi) / 2;
    int M = mid,P;
    while (mid < ma && S[mid] != '*')
    mid++;
    if (mid<ma&&S[mid] == '*')
    {
        P = mid;
        S[mid] = 'x';
    }
    else
    {
    while(M>mi&&S[M]!='*')
    M--;
    if(M>mi&&S[M]=='*')
    {
        P = M;
         S[M] = 'x';
    }
    }
    return(1+R(mi,P,S,k)+R(P,ma,S,k));
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,count = 0,mi=-1,ma=-1;
        cin>>n>>k;
        string s;
        cin>>s;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='*')
            {
                s[i]='x';
                count++;
                mi = i;
                break;
            }
        }
        for(int i = n-1;i>mi;i--)
        {
            if(s[i]=='*')
            {
                count++;
                s[i]='x';
                ma = i;
                break;
            }
        }
        for(int i=0;i<=n-1;i++){
               if(s[i]=='x'){
                   bool f=false;
                   for(int j=i+1;j<=min(i+k,n-1);j++){
                       if(s[j]=='x'){
                           f=true;
                           break;
                       }
                   }
                   if(f==false){
                       for(int j=min(n-1,i+k);j>i;j--){
                       if(s[j]=='*'){
                           s[j]='x';
                            count++;
                           break;
                       }
                      }
                   }
               }
           }
           cout<<count<<endl;
        
        
    }
return 0;
}