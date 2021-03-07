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
const int N = (1e5);
string yes="Yes",no="No";
int mirror[10] = {0,1,5,-1,-1,2,-1,-1,8,-1};
 
int inv(int t){
    int ct = t;
    int ans = 0;
    while(t > 0){
        if(mirror[t%10] == -1)return N;
        ans = ans*10 + mirror[t%10];
        t = t/10;
    }
    if(ct <= 9)ans = ans*10;
    return ans;
}
string nice(int x){
    string ans = to_string(x);
    if(ans.length() == 1)ans = '0' + ans;
    return ans;
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
cin>>t;
while(t--){
    int h,m;cin>>h>>m;
        string time;cin>>time;
        int hours = (time[0]-'0')*10 + (time[1]-'0');
        int minu = (time[3]-'0')*10 + (time[4]-'0');
 
        while(1){
            if(minu == m){
                minu = 0;
                hours++;
            }
            if(hours==h){
                hours = 0;
            }
            if(inv(hours) < m && inv(minu) < h){
                cout << nice(hours) << ":" << nice(minu) << endl;
                break;
            }
            minu++;
        }


  
}
return 0;
}