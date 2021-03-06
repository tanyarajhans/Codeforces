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

int dfs(string a, string b){
    if(a==b)
    return 0;
    else if(a.size()==0)
    return b.size();
    else if(b.size()==0)
    return a.size();  
    int p=dfs(a.substr(1), b);
    int q=dfs(a.substr(0,a.size()-1), b);
    int r= dfs(a, b.substr(1));
    int s=dfs(a, b.substr(0,b.size()-1));
    return 1+ min(min(p,q),min(r,s));
}


int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
w(t){
    string A,B;
    cin>>A>>B;
int ans=0;
// int t1[m+1][n+1];
// int t2[m+1][n+1];
// for(int i=0;i<m+1;i++)
//    t1[i][0]=i;
// for(int i=0;i<n+1;i++)
//    t1[0][i]=i;
// for(int i=1;i<m+1;i++){
//     for(int j=1;j<n+1;j++){
//         if(s1[i-1]==s2[j-1])
//         t1[i][j]=t1[i-1][j-1];
//         else
//         t1[i][j]=1+min(t1[i-1][j], t1[i][j-1]); //remove, insert, replace
//     }
// }
// cout<<t1[m][n]<<endl;
int m=A.size();
    int n=B.size();
    
    int dp[m+1][n+1];
    int maxLength = 0;
    
    for(int i=0; i<=m; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(i==0 || j==0)
             dp[i][j] = 0;
            else if(A[i-1] == B[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
                maxLength = max(maxLength, dp[i][j]);
            }
            else
             dp[i][j] = 0;
        }
    }

    // int n=text1.size();
    //     int m=text2.size();
    //     int t[n+1][m+1];
    //     memset(t,0,sizeof(t));
    //     for(int i=1;i<n+1;i++){
    //         for(int j=1;j<m+1;j++){
    //             if(text1[i-1]==text2[j-1])
    //                 t[i][j]=1+t[i-1][j-1];
    //             else
    //                 t[i][j]=max(t[i][j-1], t[i-1][j]);
    //         }
    //     }
    
   cout<<m+n-2*maxLength<<endl;

}
return 0;
}