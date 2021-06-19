// // यो न हृष्यति न द्वेष्टि न शोचति न काङ्‍क्षति। शुभाशुभपरित्यागी भक्तिमान्यः स मे प्रियः॥
// #include<iostream>
// #include<vector>
// #include<map>
// #include<list>
// #include<set>
// #include<algorithm>
// #include<queue>
// #include<stack>
// #include<cstring>
// #include<cmath>
// #include<bitset>
// #include<string>
// #include<unordered_set>
// #include<unordered_map>
// #include<cstdlib>
// #include<iomanip>
// #define f               first
// #define s              second
// #define int               long long
// #define ll               long long
// #define pb               push_back
// #define mp               make_pair
// #define pii              pair<int,int>
// #define vi               vector<int>
// #define mii              unordered_map<int,int>
// #define pqb              priority_queue<int>
// #define pqs              priority_queue< int,vi,greater<int> >
// #define setbits(x)       __builtin_popcountll(x)
// #define zrobits(x)       __builtin_ctzll(x)
// #define mod              1000000007
// #define inf              1e10
// #define ps(x,y)          fixed<<setprecision(y)<<x
// #define mk(arr,n,type)   type *arr=new type[n];
// #define w(x)             int x; cin>>x; while(x--)
// #define me(i,start,end)  for(int i=start;i<end;i++)
// #define he(i,end,start) for(int i=end-1;i>=start;i--)
// #define all(v)         v.begin(),v.end()

// using namespace std;
// ll pf[10000001];


// // Tanya Rajhans
// int gcd(int a, int b)
// {
//     if (b == 0)
//         return a;
//     return gcd(b, a % b); 
     
// }

//    void prime(){
//        memset(pf,0,10000001);
//        pf[0]=pf[1]=1;
//    for(ll i=2;i<10000001;i++){
//         if(pf[i]==0){
//             for(ll j=i*i;j<10000001;j=j+i)
//                   pf[j]=1;
//         }
//     }
// }

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

// int adj[2505][2505];

// void solve(){
//     int n,m;
//     cin>>n>>m;
//     int p=-1e15;
//     for(int i=1;i<=n;i++){
//         for(int j=i+1;j<=n;j++){
//             adj[i][j]=adj[j][i]=p;
//         }
//     }
//     while(m--){
//         int a,b,x;
//         cin>>a>>b>>x;
//         adj[a][b]=min(adj[a][b], x);
//     }
//     for(int k=1;k<=n;k++){
//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=n;j++){
//                 adj[i][j]=max(adj[i][j], adj[i][k] + adj[k][j]);
//             }
//         }
//     }
// }


// int32_t main(){
// ios_base::sync_with_stdio(false);
// cin.tie(NULL);
// {
// solve();
// }
// return 0;
// }
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long int
 
const int INF = 1e17;
const int NINF = INF*(-1);
 
struct triplet{
	int first;
	int second;
	int third;
};
 
int n, m;	
vector<triplet> edges;
vector<int> dist;
 
void bellman_ford()
{
	for(int i = 1; i < n; ++i)
	{
		for(auto e: edges)
		{
			int u = e.first;
			int v = e.second;
			int d = e.third;
			if(dist[u] == INF) continue;
			dist[v] = min(dist[v], d+dist[u]);
			dist[v] = max(dist[v], NINF);
		}
	} // n relaxations
 
	for(int i = 1; i < n; ++i)
	{
		for(auto e: edges)
		{
			int u = e.first;
			int v = e.second;
			int d = e.third;
			if(dist[u] == INF) continue;
			dist[v] = max(dist[v], NINF);
			if(dist[u]+d < dist[v])
			{
				dist[v] = NINF;
			}
		}
	}
}
 
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	dist.resize(n+1);
	edges.resize(m);
	for(int i = 0; i < m; ++i)
	{
		struct triplet inp;
		cin >> inp.first >> inp.second >> inp.third;
		inp.third *= -1; 
		edges[i] = inp;
	}
 
	for(int i = 2; i <= n; ++i)
	{
		dist[i] = INF;
	}
 
	bellman_ford();
	if(dist[n] == NINF)
	{
		cout << -1 << endl;
		return 0;
	} 
	cout << dist[n] * (-1) << endl;
}