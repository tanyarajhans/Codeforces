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
#define ll long long
using namespace std;

ll n,k,z;
ll dp[100006][6];
ll fun(vector<ll>&v,ll curr,ll k,ll z){
	
	ll n=v.size();
	if(k==0 || curr<0 || curr>=n)
		return 0;
	if(dp[curr][z]!=-1)
		return dp[curr][z];
	ll ans=0;
	if(curr<n)
	ans=max(ans,v[curr]+fun(v,curr+1,k-1,z));
	if(curr>0 and z>0 and k>0)
	ans=max(ans,v[curr]+fun(v,curr-1,k-1,z-1));
	return dp[curr][z]=ans;
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
cin>>t;
while(t--){
    cin>>n>>k>>z;
    vector<ll>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    memset(dp,-1,sizeof(dp));
 ll ans=a[0]+fun(a,1,k,z);
    cout<<ans<<endl;
   
}
return 0;
}