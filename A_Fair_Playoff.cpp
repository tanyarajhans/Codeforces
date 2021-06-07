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
#define int               long long
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
    if(sqrt_n == int32_t(sqrt_n)){
        return 1;
    }
    else{
        return 0;
    }
}


void solve(){
    int s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    vector<int> a;
    a.pb(s1);
    a.pb(s2);
    a.pb(s3);
    a.pb(s4);
    sort(a.begin(), a.end());
    int x=a[2];
    int y=a[3];
    int w1=0,w2=0,w3=0;
    int z=max(s1,s2);
	int z1=max(s3,s4);
	int z2=min(z,z1);
	int z3=max(z,z1);
	if(z3 ==a[3] && z2==a[2])
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
    //if((x==b[1] && y==b[2]) || (x==b[2] && y==b[1]))
   

}


int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
w(t){
solve();
}
return 0;
}