#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N=1e5+5;
 
int n, m;
int dist[N], vis[N], parent[N];
vector<pair<int, int> > g[N];
 
int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=2;i<=n;i++)
	{
		dist[i]=1e18;
	}
	for(int i=1;i<=m;i++)
	{
		int u, v, w;
		cin>>u>>v>>w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	set<pair<int, int> > s;
	s.insert({0, 1});
	while(!s.empty())
	{
		auto x = *(s.begin());
		s.erase(x);
		vis[x.second]=1;
		vector<pair<int, int> > v;
		for(auto it:g[x.second])
		{
			v.push_back(it);
 
			if(dist[it.first] > dist[x.second] + it.second)
			{
				s.erase({dist[it.first], it.first});
				dist[it.first]=dist[x.second] + it.second;
				s.insert({dist[it.first], it.first});
				parent[it.first]=x.second;
			}
		}
	}
	if(!vis[n])
	{
		cout<<"-1";
		return 0;
	}
	int v=n;
	vector<int> ans;
	while(parent[v])
	{
		ans.push_back(v);
		v=parent[v];
	}
	ans.push_back(1);
	reverse(ans.begin(), ans.end());
	for(auto it:ans)
		cout<<it<<" ";
	return 0;
} 
