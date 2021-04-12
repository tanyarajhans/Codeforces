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


int main() 
{
    
  ios_base::sync_with_stdio(false) ; 
  cin.tie(NULL);
    cout.tie(NULL);
    w(t)
    {
        ll n,m,k;
        cin>>n>>m>>k;
        int b1=0,f1=0;
        ll a[n+5][m+5];
        ll b[n+5][m+5];
        ll c[n+5][m+5];
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        ll i,j,p,q; 
    for(int i=1;i<=n;i++)
    {
       for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
 
    for(int j=1;j<=m;j++)
    {
        for(int i=1;i<=n;i++)
        {
            b[i][j] = a[i][j] + b[i-1][j] ; 
        }
    }
 
 
    for(int i=1;i<=n;i++)
    {
        ll sv=0,st=0;
        bool check=false;
        for(int j=1;j<=m;j++)
        {
            check=true;
            ll wans = c[i-1][j-1] + b[i-1][j] + a[i][j] + sv;
            check=!check;
            ll ktt=0;
            c[i][j] = wans ;
            ktt+=2;
            st+=c[i][j];
            sv += a[i][j] ; 
        }
        check=!check;
        st+=sv;
    }
    ll fans = 0 ; 
    
    for(int i=1;i<=n;i++)
    {
        ll re=0,rv=0;
        for(int j=1;j<=m;j++)
        { 
            bool isvalid=true;
            ll dd = abs(j-m); 
            dd++;
            isvalid=false;
            ll p=-1;
            ll ee = abs(i-n);
            ee++;
            isvalid=!isvalid;
            ll gg=abs(dd);
            p=-4;
            ll done = min(dd,ee); 
            ll kk=done*gg;
            p+=9;
            ll ans = -1;
            ll low = 1;
            p+=-6;
            p+=6;
            isvalid=!isvalid;
            ll high = done; 
            ll g = 0; 
            isvalid=!isvalid;
            while(low<=high && g==0)
            {
                
                ll mid = (low+high)/2 ;
                ll i1=i;
                ll j1=j;
                i1--;
                j1--;
                ll mid1=mid;
                ll i2=i+mid-1; 
                ll j2=j+mid-1;
                mid1+=2;
                ll v3 = c[i2][j2];
                ll v1 = c[i2][j1];
                mid1-=2;
                ll v2 = c[i1][j2];
                ll v4 = c[i1][j1];
                mid1+=2;
                ll st1 = v3 - v1 -v2 + v4 ;
                mid1-=2;
                long double uu = mid*mid ;
                long double vv = st1 ; 
                long double r = st1/uu ; 
                
                if(r>=k)
                {
                    high = mid ; 
                    
                if(mid!=1)
                {
                i1=i;
                j1=j;
                i2=i+mid-2 ; 
                j2=j+mid-2;
                i1--;
                j1--;
                v3 = c[i2][j2];
                v1 = c[i2][j1];
                v2 = c[i1][j2];
                v4 = c[i1][j1];
                st1 = v3 - v1 -v2 + v4 ;
                uu = (mid-1)*(mid-1) ; 
                vv= st1 ; 
                long double cc= st1/uu ;  
                long double cv= cc; 
                       if(cc<k)
                      {
                        g=1;
                        cv--;
                        ans = mid ;
                        ll de=0;
                        de+=cv;
                       }  
                    }
                    else
                    {
                        long double cv=0; 
                        g=1 ; 
                        cv++;
                        ans = mid;
                        cv--;
                    }
                }
                else
                    low = mid + 1 ;
            }
            int to=-1;
            if(ans!=-1)
            {
                fans+= abs(ans-done);
                to+=8;
                fans++;
            }
  
        }
        re++;
        rv--;
    } 
        cout<<fans<<endl;
        
    }

    
}