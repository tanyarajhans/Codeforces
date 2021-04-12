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
ll pf[10000001];


// Tanya Rajhans
ll gcd(ll a, ll b)
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


int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
w(t){
    int a,b,c;
    cin>>a>>b>>c;
    ll xx=pow(10,a-1);
    ll yy=pow(10,b-1);
    // ll x1=pow(10,a+1)-1;
    // ll y1=pow(10,b+1)-1;
    // bool b1=false;
    // ll i,j;
    // for(i=xx;i<=x1;i++){
    //     for(j=yy; j<=y1;j++){
    //         ll p=gcd(i,j);
        //     string s=to_string(p);
        //     if(s.size()==c){
        //         b1=true;
        //         break;
        //     }
        // }
    //     if(b1)
    //     break;
    // // }
    // if(xx>yy){
    //     while(true){
    //         ll p=gcd(xx,yy);
    //         string s=to_string(p);
    //         if(s.size()==c){
    //            cout<<xx<<" "<<yy<<endl;
    //             break;
    //         }

    //         yy++;
    //     }
    // }
    // else{
    //     while(true){
            // ll p=gcd(xx,yy);
            // string s=to_string(p);
            // if(s.size()==c){
            //    cout<<xx<<" "<<yy<<endl;
            //     break;
            // }

    //         xx++;
    //     }
    // }
    //  if(c<a && c<b){
    //      cout<<xx+c<<" "<<yy<<endl;
    //  }
    //  else if(c==a&& c<b){
    //      cout<<xx<<" "<<yy<<endl;
    //  }
    //  else if(c==b && c<a){
    //       cout<<yy<<" "<<xx<<endl;
    //  }
    //  else if(c==a && c==b){
    //      cout<<xx<<" "<<yy<<endl;
    //  }
     ll cc=pow(10,c-1);
     
    //  while(true){
    //        ll p=xx/cc;
    //        ll q=yy/cc;
    //        if(xx%cc)
    //         p++;
    //       if(yy%cc)
    //         q++;
    //        ll b=gcd(p*cc,q*cc);
    //         string s=to_string(b);
    //         if(s.size()==c){
    //            cout<<p*cc<<" "<<q*cc<<endl;
    //             break;
    //         }
    //         xx=p*cc;
    //         yy=q*cc;
    //         cc++;
    //  }
     if(xx<yy)
     cout<<xx<<" "<<yy+cc<<endl;
     else
     cout<<xx+cc<<" "<<yy<<endl;
    
}
return 0;
}