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


#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define getT() \
    int t;     \
    cin >> t;  \
    while (t--)
#define lli long long int
#define MOD 998244353

int minimumChanges (int n, vector<int> V) {
    lli count = 0;
stack<int> st;
   int count =0;
   st.push(V[n-1]);
   for(int i=n-2;i>=0;i--)
   {
       if(!st.empty() && V[i]<=st.top() )
       {
           st.push(V[i]);
       }
       else if(!st.empty() && V[i]>st.top())
       {
           count =0;
           while(!st.empty() && V[i]>st.top() )
           {
               if(st.size()V[i]-st.top())
               st.pop();
               count++;
           }
           for(int j=0;j<count+1;j++)
           st.push(V[i]);
       }
   }
   return count;

        for (lli i = 0; i < n; i++)
        {
            for (lli j = i + 1; j < n; j++)
            {
                int k=j-i;
                if(arr[i] - arr[j]>0){
                     if(k % abs(arr[i] - arr[j])==0)
                    {
                        count++;
                    }
                }
                
                
                
            }
        
        }

        return count;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i = 0; t_i < T; t_i++)
    {
        int N;
        cin >> N;
        vector<int> V(N);
        for(int i_V = 0; i_V < N; i_V++)
        {
        	cin >> V[i_V];
        }

        int out_;
        out_ = minimumChanges(N, V);
        cout << out_;
        cout << "\n";
    }
}