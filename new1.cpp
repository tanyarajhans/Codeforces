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

bool ispal(string str)
{
    int l = 0;
    int h = str.length() - 1;
    while (h > l)
        if (str[l++] != str[h--])
            return 0;
    return 1;
}
void solve()
{
  ll n,zer=0,i;
  string s;
  cin>>n;
  cin>>s;
  for(i=0;i<s.length();i++)
    if(s[i]=='0')
    if(s[i]=='0')
      zer ++;
  ll chance=0,alice=0,bob=0;
// while(zer > 0)
  {
    if(chance%2 == 0)
    {
 
      if(!ispal(s))
      {
        reverse(s.begin(),s.end());
        chance++;
        //continue;
      }  
      if(s.length()%2 != 0 && s[n/2] == '0')
      {
        s[n/2] = '1';
        zer --;
      }
      else
      {
        ll fg = 0;
        for(i=0;i<n;i++)
        {
          if(s[i] == '0' && s[n-i-1] == '1')
          {
            s[i] = '1';
            zer--;
            fg = 1;
            break;
          }
        }
        if(fg == 0)
        {
          for(i=0;i<n;i++)
          {
            if(s[i] == '0')
            {
              s[i] = '1';
              zer--;
              break;
            }
          }
        }
      }
 
      alice++;
      chance++;
    }
    else
    chance++;
  }
  if(alice > chance)
	cout<<"ALICE";
	else
	cout<<"BOB";
  cout<<endl;
} 
int main()
{
  w(t){
    solve();
  }
}