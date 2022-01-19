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
 
// int lcm(int a, int b) { return a * b / gcd(a, b); }

// int check_ps(ll n){
//     double sqrt_n = sqrt(n);
//     if(sqrt_n == int32_t(sqrt_n)){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }

// int st[400004], lazy[400004], a[100001];

// void build(int si, int ss, int se){
//     if(ss==se){
//         st[si]=a[ss];
//         return;
//     }
//     int mid=(ss+se)/2;
//     build(2*si, ss, mid);
//     build(2*si+1, mid+1, se);

//     st[si]=st[2*si] + st[2*si+1];
// }
 
// int query(int si, int ss, int se, int qs, int qe){

//     if(lazy[si]!=0){
//        int dx=lazy[si];
//        lazy[si]=0;
//        st[si]+=dx*(se-ss+1);

//        if(ss!=se){
//           lazy[2*si]+=dx;
//           lazy[2*si+1]+=dx;  
//        }
//     }

//     if(qs>se || qe<ss)
//     return 0;

//     if(qs<=ss && se<=qe)
//     return st[si];

//     int mid=(ss+se)/2;
//     int l=query(2*si, ss, mid, qs, qe);
//     int r=query(2*si+1, mid+1, se, qs, qe);

//     return l+r;

// }

// void update(int si , int ss , int se , int qs , int qe , int val)
// {
// if(lazy[si] != 0)
// {
// int dx = lazy[si];
// lazy[si] = 0;
// st[si] += dx * (se - ss + 1);

// if(ss != se)
// lazy[2*si] += dx , lazy[2*si+1] += dx;
// }

// if(ss > qe || se < qs) return;

// if(ss >= qs && se <= qe)
// {
// int dx = (se - ss + 1) * val;
// st[si] += dx;

// if(ss != se)
// lazy[2*si] += val , lazy[2*si+1] += val;
// return;
// }

// int mid = (ss + se) / 2;
// update(2*si , ss , mid , qs , qe , val);
// update(2*si+1 , mid+1 , se , qs , qe , val);

// st[si] = st[2*si] + st[2*si+1];
// }
int n,l;

int d[502],a[502];

int dp[502][502];



int solve1(int i, int k){
    if(i>=n)
    return 0;

    if(dp[i][k]!=-1)
    return dp[i][k];

    int ans=1e9;
    for(int j=0;j<=k;j++){
        if(i+j>=n)
        break;

        int x=(d[i+j+1]-d[i])*a[i];
        ans=min(ans, x+solve1(i+j+1, k-j));
    }
    return dp[i][k]=ans;
}


void solve(){
    int k;
    cin>>n>>l>>k;

    for(int i=0;i<n;i++){
        cin>>d[i];
    }
    d[n]=l;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    // if(k==0){
    //    int ans=0;
    //    for(int i=0;i<n-1;i++){
    //        int d1=d[i+1]-d[i];
    //        ans+=d1*a[i];
    //    }
    //    ans+=(l-d[n-1])*a[n-1];
    //    cout<<ans<<endl;
    //    return;
    // }
    // if(k==n-1){
    //     cout<<l*a[0]<<endl;
    //     return;
    // }
    memset(dp,-1,sizeof(dp));
    //curr sign, no of signs we can remove, dp[i][j] = we can remove min time taken to reach ith sign if we remove j signs
    int ans=solve1(0,k);
    cout<<ans<<endl;

}

int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
{
solve();
}
return 0;
}
