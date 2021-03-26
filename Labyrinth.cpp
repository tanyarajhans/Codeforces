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

int dx[4]={1,0,-1,0}; //D, R, U, L
int dy[4]={0,1,0,-1};
int n,m;
int sx,sy,ex,ey;
vector<vector<pair<int,int> > > path;
vector<vector<int> > vis;

bool isValid(int x, int y){
 return x>=0 && y>=0 && x<n && y<m && vis[x][y]==false;
}

void bfs(){
queue<pair<int,int> > q;
q.push(mp(sx,sy));
while(!q.empty()){
    int cx=q.front().f;
    int cy=q.front().s;
    q.pop();
    for(int i=0;i<4;i++){
        int xx=cx+dx[i];
        int yy=cy+dy[i];
        if(isValid(xx,yy)){
            q.push(mp(xx,yy));
            vis[xx][yy]=1;
            path[xx][yy]=mp(dx[i], dy[i]);
        }
    }
  } 
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cin>>n>>m;
path.resize(n);
vis.resize(n);
for(int i=0;i<n;i++){
path[i].resize(m);
vis[i].resize(m);
}


for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        path[i][j]=mp(1,-1);
        char ch;
        cin>>ch;
        if(ch=='#')
        vis[i][j]=true;
        if(ch=='A'){
            sx=i;
            sy=j;
        }
        if(ch=='B'){
            ex=i;
            ey=j;
        }
    }
}
bfs();
if(!vis[ex][ey]){
    cout<<"NO"<<endl;
    return 0;

}
cout<<"YES"<<endl;
vector<pair<int,int> > ans;
pair<int, int> end= mp(ex,ey);

while(end.f!=sx || end.s!=sy){
    ans.pb(path[end.f][end.s]);
    end.f-=ans.back().f;
    end.s-=ans.back().s;
}

reverse(ans.begin(), ans.end());
cout<<ans.size()<<endl;
for(int i=0;i<ans.size();i++){
    if(ans[i].f==1 && ans[i].s==0)
    cout<<"D";

    else if(ans[i].f==0 && ans[i].s==1)
    cout<<"R";

    else if(ans[i].f==-1 && ans[i].s==0)
    cout<<"U";
    else if(ans[i].f==0 && ans[i].s==-1)
    cout<<"L";
}


return 0;
}