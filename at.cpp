#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<math.h>
#include <cstring>
#include<stack>
#include<list>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include <iomanip> 
#include<utility>
#define int int64_t
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vs vector<string>
#define vc vector<char>
#define vb vector<bool>
#define pb push_back
#define vvi vector<vector<int> >
#define pii pair<int,int>
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define vin(x,v) for(auto &x:v)cin>>x;
#define vout(x,v)for(auto x:v)cout<<x<<" ";
#define MEM(a, b) memset(a, (b), sizeof(a))
#define loop(i, j, k) for (int i=j ; i<k ; i+=1)
#define rloop(i, j, k) for (int i=j ; i>=k ; i-=1)
#define rep(i, j) loop(i, 0, j)
#define rrep(i, j) rloop(i, j, 0)
#define MP make_pair
#define endl "\n"
#define INF (int)1e18
#define EPS 1e-18
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
//cout <<setprecision(15)
#define NEED_FOR_SPEED_MOST_WANTED ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;






int N;
int X,Y;
vii v;

int dp[310][310][310];

int calc(int index, int x, int y){
    if(x>=X && y>=Y)return 0;
    if(index>=N)return INF;
    if(dp[index][x][y]!=-1)return dp[index][x][y];
    int q1=calc(index+1,min(x+v[index].first,X),min(Y,y+v[index].second))+1;
    int q2=calc(index+1,x,y);
    return dp[index][x][y]=min(q1,q2);
}



void solve(){
    cin>>N>>X>>Y;
    
    rep(i,N){
        int a,b;cin>>a>>b;
        v.pb(mp(a,b));
    }
    MEM(dp, -1);
    int ans=calc(0,0,0);
    if(ans<INF)cout<<ans;
    else cout<<-1;
}

signed main(){
NEED_FOR_SPEED_MOST_WANTED; 
 //#ifndef ONLINE_JUDGE
    //FOR GETTING INPUT FROM input.txt
    //freopen("input.txt", "r", stdin);
    //FOR GETTING INPUT FROM input.txt	
    //freopen("output.txt", "w", stdout);
//	#endif
  int t=1;
  //cin>>t;
  while(t--){
   solve();
   v.clear();
  cout<<endl;
  }
}