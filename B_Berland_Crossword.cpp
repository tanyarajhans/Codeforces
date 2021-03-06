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
int vis[105][105];

bool isValid(int n, int u, int r, int d, int l, vector<vector<int> > &board, int rr, int cc){
int i, j; 
  int lll=0,uu=0,dd=0,rrr=0;
    /* Check this row on left side */
    for (i = 0; i < cc; i++) 
        if (board[0][i]) 
            uu++;
    if(uu>u)
    return false;
    
    for (i = 0; i < cc; i++) 
        if (board[n-1][i]) 
            dd++;
    if(dd>d)
    return false;

    for (i = 0; i < rr; i++) 
        if (board[i][0]) 
            lll++;
    if(lll>l)
    return false;
    for (i = 0; i < rr; i++) 
        if (board[i][n-1]) 
            rrr++;
    if(rrr>r)
    return false;
    
    return true; 
}

bool solve(int n, int u, int r, int d, int l, vector<vector<int> > &board, int rr, int cc) 
{ 
    
    if(isValid(n, u,r,d,l, board, rr, cc)){
        board[rr][cc]=1;
        if(solve(n,u-1, r,d, l, board, rr,cc+1) || solve(n,u,r,d,l-1,board,rr+1,cc))
        return true;
        board[rr][cc]=0;

    }
    return true;
} 

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
cin>>t;
while(t--){
    int n,u,r,d,l;
        cin>>n>>u>>r>>d>>l;
        int u1=u;
        int r1=r;
        int l1=l;
        int d1=d;
        if(u==n)
        {
            l1--;
            r1--;
        }
        if (d == n)
        {
            l1--;
            r1--;
        }
        if (l == n)
        {
            d1--;
            u1--;
        }
        if (r == n)
        {
            d1--;
            u1--;
        }
 
 
        if(u==n-1)
        {
            if(l1>r1)
            {
                l1--;
            }
            else
            {
                r1--;
            }
        }
        if (d == n - 1)
        {
            if (l1 > r1)
            {
                l1--;
            }
            else
            {
                r1--;
            }
        }
        if (l == n - 1)
        {
            if (u1 > d1)
            {
                u1--;
            }
            else
            {
                d1--;
            }
        }
        if (r == n - 1)
        {
            if (u1 > d1)
            {
                u1--;
            }
            else
            {
                d1--;
            }
        }
 
        //cout<<u1<<" "<<r1<<" "<<d1<<" "<<l1<<"\n";
        if(l1<0 || u1<0 || d1<0 || r1<0)
        {
            cout<<"NO\n";
        }
        else
        {
            cout<<"YES\n";
        }
    
}
return 0;
}