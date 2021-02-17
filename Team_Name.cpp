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


int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    vector<string>v;
    for(int i=0;i<n;i++){
        string x;
        cin>>x;
        v.push_back(x);
    }
    ll ans=0;
    set<string> s(v.begin(),v.end());
    unordered_map<pair<string,string>, bool> m;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
              char a=v[i][0];
              char b=v[j][0];
              string s1=b+v[i].substr(1);
              string s2=a+v[j].substr(1);
              if(s.count(s1)==0 && s.count(s1)==0){
                  if(m[{s1,s2}]==false){
                     ans+=2;
                     m[{s1,s2}]=true;
                  }
              }
              
        }
    }
    cout<<ans<<endl;
   
}
return 0;
}