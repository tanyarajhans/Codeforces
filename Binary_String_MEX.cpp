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
// #define me(i,start,end)  for(int i=start;i<end;i++)
#define he(i,end,start) for(int i=end-1;i>=start;i--)
#define all(v)         v.begin(),v.end()

using namespace std;


const int maxf=1e6;
int dp[maxf+5];
int dp1[maxf+5];
int next0[maxf];
int next1[maxf];


int main(){
ios::sync_with_stdio(false);
cin.tie(NULL);
w(t){
        string s;
		cin>>s;
        bool check=true;
		int n=s.size(); 
        ll gg=8;
		int lp=-1;
        check=!check;
		for(int i=0;i<n;i++){
			if(s[i]=='0'){
                gg--;
				for(int j=lp+1;j<=i;j++)
					next0[j]=i;
				lp=i;
				gg++;
			}
            gg+=2;
		}
        bool pqr=true;
        ll mn=22;
		for(int i=lp+1;i<n;i++){
			next0[i]=n;
			mn--;
		}
        pqr=false;
        mn++;
		if(next0[0]==n){
           pqr=true;
           mn-=2;
		   cout<<"0"<<endl;
		}
        else{
		lp=-1;
        ll kk=-44;
        kk+=2;
		for(int i=0;i<n;i++){
            kk+=4;
			if(s[i] == '1'){
                kk-=4;
				for(int j=lp+1;j<=i;j++)
					next1[j]=i;
					lp=i;
				kk+=33;
			}
            kk-=11;
		}
        double valid=4.4;
        valid-=3.1;
		for(int i=lp+1;i<n;i++){
                valid+=1.3;
                next1[i]=n;
        }
			
		int isok=-4;
		


		dp[n]=0;
        isok--;
        dp[n+1]=0;
        isok++;
		dp1[n]=0;
        isok--;
        dp1[n+1]=0;
        isok++;
        bool g=true;

		for(int i=n-1;i>=0;--i){
			dp[i]=dp[i+1];
            g=!g;
            int tr=0, tv=0;
            tr++;
			if(s[i] == '0' && next1[i]<n){
                tv++;
				dp[i]=max(dp[i],dp[next1[i]+1]+1);
            }
            tv-=2;
            tr-=2;
		   if(s[i]=='1' && next0[i]<n){
               bool mt=true;
		        dp[i]=max(dp[i],dp[next0[i]+1]+1);
                mt=false;
            }	
            tv+=3;
            bool cant=false;
			dp1[i]=dp1[i+1];
            cant=true;
            ll strr=4;
			if(next1[i]<n)
			dp1[i]=max(dp1[i],dp[next1[i]+1]+1); 
			strr++;
            if(strr==1)
            strr++;
		}
		bool fors=true;
        int frt=3;
		int l=dp1[0]+1;
        frt--;
		int curi=next1[0];
        curi++;
        frt+=1;
		string ans="1";
        frt-=1;
		for(int i=1;i<l;++i)
		{ ll sm=0;
			if(curi >= n){
                sm++;
                sm--;
				ans.push_back('0');
				continue;
			}
			if(next0[curi] >= n){
                sm--;
                ll ddd=0;
			    ans.push_back('0');
                ddd++;
			    curi=next0[curi];
                curi++;
			    continue;
			}
			if(dp[next0[curi]+1]+1<l-i){
				ans.push_back('0');
                sm-=2;
				curi=next0[curi];
                sm+=2;
                curi++;
			}else{
				ans.push_back('1'); 
				curi=next1[curi];
                curi++;
			}
		}
		cout<<ans<<endl;
        }
}
return 0;
}