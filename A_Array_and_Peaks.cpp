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
    int n,k;
    cin>>n>>k;
    int a[n];
    map<int,int> m;
    

    if((k>(n/2) && n%2!=0) || (k>((n/2)-1) && n%2==0))
    {
        cout<<-1<<endl;
    }
    else if(n<3){
        if(n==1){
            if(k==0)
            cout<<1<<endl;
            else
            cout<<-1<<endl;
        }
        else if(n==2){
            if(k==0)
            cout<<1<<" "<<2<<endl;
            else
            cout<<-1<<endl;
        }
    }
    else{
        for(int i=0;i<n;i++)
    a[i]=i+1;

    int b[n];
    b[0]=1;
 
    bool vis[n];
    for(int i=0;i<n;i++)
    vis[i]=false;

    vis[0]=true;

   int j=1, l=1,c=k;
    while(c>0 && j<n && l<n){
       c--;
       b[j+1]=a[l];
       vis[j+1]=true;
      j+=2;
      l++;
    }
    for(int i=0;i<n && l<n;i++){
        if(!vis[i]){
            b[i]=a[l];
            l++;
        }
    }

        int p=0;
    for(int i=1;i<n-1;i++){
       if(b[i]>b[i-1] && b[i]>b[i+1])
       p++;
    }
     
  if(p==k){
       for(int i=0;i<n;i++)
        cout<<b[i]<<" ";
        cout<<endl;
    }
   else
    cout<<-1<<endl;
   }

}
return 0;
}