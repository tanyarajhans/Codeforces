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

 bool isValid(string s) {
       stack<char> st;
        int n=s.size();
        if(n%2!=0)
            return false;
        for(int i=0;i<n;i++){
           if(s[i]=='(' ) 
            st.push(s[i]);
            
            if(s[i]==')') {
                if(!st.empty() && st.top()=='('){
                    st.pop();
                }
                else
                    return false;
            }
           
            
        }
        if(st.empty())
            return true;
        else
            return false;
    }

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
cin>>t;
while(t--){
    string s;
    cin>>s;
    int n=s.size();
    if(s[0]==s[n-1])
    cout<<"NO"<<endl;
    else
    {
        char ch0=s[0];
        char ch1=s[n-1];
        char ch2;
        if(ch0=='A' && ch1=='B'){
            ch2='C';
        }
        else if(ch0=='A' && ch1=='C'){
             ch2='B';
        }
        else if(ch0=='B' && ch1=='A')
        ch2='C';
        else if(ch0=='B' && ch1=='C')
        ch2='A';
        else if(ch0=='C' && ch1=='A')
        ch2='B';
        else if(ch0=='C' && ch1=='B')
        ch2='A';
        string b="";
        for(int i=0;i<n;i++){
            if(s[i]==ch0)
            b+='(';
            else if(s[i]==ch1)
            b+=')';
            else 
            b+='X';
        }
        string c=b;
        for(int i=0;i<n;i++)
            if(c[i]=='X')
            c[i]=')';
        if(isValid(c))
        cout<<"YES"<<endl;
        else{
            c=b;
        for(int i=0;i<n;i++)
            if(c[i]=='X')
             c[i]='(';
         if(isValid(c))
        cout<<"YES"<<endl;
        else
        {
            cout<<"NO"<<endl;
        }
        
        }
    }
    
}
return 0;
}