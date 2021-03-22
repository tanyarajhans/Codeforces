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
// int r,c,lv,lh;
// int t[1005][1005];
// bool isValid(int x,int y){
//     return x>=0 && x<r && y>=0 && y<c && t[x][y]==1;
// }
// void dfsx(int x, int y){
// if(isValid(x,y+1))
// {
//     dfsx(x,y+1);
//     lh++;
// }
// }
// void dfsx1(int x, int y){
// if(isValid(x,y-1))
// {
//     dfsx1(x,y-1);
//     lh++;
// }
// }
// void dfsy(int x, int y){
// if(isValid(x+1,y))
// {
//     dfsy(x+1,y);
//     lv++;
// }
// }
// void dfsy1(int x, int y){
// if(isValid(x-1,y))
// {
//     dfsy1(x-1,y);
//     lv++;
// }
// }
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
// int p=1;
// w(tc){
//     cin>>r>>c;
//     for(int i=0;i<r;i++){
//       for(int j=0;j<c;j++){
//           cin>>t[i][j];
//       }
//     }
//     int ans=0;
//     for(int i=0;i<r;i++){
//       for(int j=0;j<c;j++){
//           lv=0,lh=0;
//           if(t[i][j]==1){
//               lh++;
//               dfsx(i, j);
//               lv++;
//               dfsy(i,j);
//               if(lv==2*lh && lv>=2 && lh>=2)
//                 ans++;
//               lv=0,lh=0;
//               lh++;
//               dfsx1(i, j);
//               lv++;
//               dfsy1(i,j);
//               if(lv==2*lh && lv>=2 && lh>=2)
//                 ans++;
//           }
          
//       }
//     }

//     cout<<"Case #"<<p<<": "<<ans<<endl;
//     p++;
// }
 int t;
    cin>>t;
    for(int q=1;q<=t;q++)
    {
        int r,c;
        cin>>r>>c;
        int a[r][c];
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                cin>>a[i][j];
            }
        }
        int up[r][c];
        int left[r][c];
        int right[r][c];
        int down[r][c];
        memset(up,0,sizeof(up));
        memset(down,0,sizeof(up));
        memset(right,0,sizeof(up));
        memset(down,0,sizeof(up));
        for(int i=0;i<r;i++)
        {
            left[i][0]=a[i][0];
            right[i][c-1]=a[i][c-1];
        }
        for(int i=0;i<c;i++)
        {
            up[0][i]=a[0][i];
            down[r-1][i]=a[r-1][i];
        }
        for(int i=1;i<r;i++)
        {
            for(int j=1;j<c;j++)
            {
                if(a[i][j]==1)
                {
                    up[i][j]+=up[i-1][j]+1;
                    left[i][j]+=left[i][j-1]+1;
                }

            }
        }
        for(int i=r-2;i>=0;i--)
        {
            for(int j=c-2;j>=0;j--)
            {
                if(a[i][j]==1)
                {
                    down[i][j]+=down[i+1][j]+1;
                    right[i][j]+=right[i][j+1]+1;
                }
            }
        }
        
        int ans=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                cout<<left[i][j]<<' '<<right[i][j]<<' '<<up[i][j]<<' '<<down[i][j]<<endl;
                if(a[i][j]==1){
                    if(left[i][j]>1) ans+=min(left[i][j],up[i][j]/2)+min(left[i][j],down[i][j]/2);
                    if(up[i][j]>1)   ans+=min(left[i][j]/2,up[i][j])+min(right[i][j]/2,up[i][j]);
                    if(right[i][j]>1)   ans+=min(right[i][j],up[i][j]/2)+min(right[i][j],down[i][j]/2);
                    if(down[i][j]>1)   ans+=min(left[i][j]/2,down[i][j])+min(right[i][j]/2,down[i][j]);
                }
            }
        }
        cout<<"Case #"<<q<<": "<<ans<<endl;
    }

return 0;
}