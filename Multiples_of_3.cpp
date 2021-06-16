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
#define int               long long
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
    if(sqrt_n == int32_t(sqrt_n)){
        return 1;
    }
    else{
        return 0;
    }
}

struct node{
    int m[3];
};

node st[400004];
int lazy[400004];


void build(int si, int ss, int se){
    if(ss==se){
        // initially every element is zero
        st[si].m[0]=1;
        st[si].m[1]=0;
        st[si].m[2]=0;
        return;
    }
    int mid=(ss+se)/2;
    build(2*si, ss, mid);
    build(2*si+1, mid+1, se);

    st[si].m[0]=st[2*si].m[0]+st[2*si+1].m[0];
    st[si].m[1]=st[2*si].m[1]+st[2*si+1].m[1];
    st[si].m[2]=st[2*si].m[2]+st[2*si+1].m[2];
}

void shift(int si){
    int x=st[si].m[2];
    st[si].m[2]=st[si].m[1];
    st[si].m[1]=st[si].m[0];
    st[si].m[0]=x;
}

int query(int si, int ss, int se, int qs, int qe){

    if(lazy[si] != 0)
    {
    int dx = lazy[si];
    lazy[si] = 0;


    if(ss != se)
    lazy[2*si] += dx , lazy[2*si+1] += dx;

    dx%=3;
    for(int i=0;i<dx;i++)
        shift(si);
    }
    
    if(qs>se || qe<ss)
        return 0;

    if(qs<=ss && se<=qe)
        return st[si].m[0];

    int mid=(ss+se)/2;
    int l=query(2*si, ss, mid, qs, qe);
    int r=query(2*si+1, mid+1, se, qs, qe);

    return l+r;

}



void update(int si , int ss , int se , int qs , int qe, int val)
{
    if(lazy[si] != 0)
    {
        int dx = lazy[si];
        lazy[si] = 0;


        if(ss != se)
           lazy[2*si] += dx , lazy[2*si+1] += dx;

        dx%=3;

        for(int i=0;i<dx;i++)
            shift(si);
    }

    if(ss > qe || se < qs) return;

    if(ss >= qs && se <= qe)
    {
        shift(si);

        if(ss != se)
           lazy[2*si] +=val , lazy[2*si+1] +=val;
        return;
    }

    int mid = (ss + se) / 2;
    update(2*si , ss , mid , qs , qe , val);
    update(2*si+1 , mid+1 , se , qs , qe , val);

    st[si].m[0]=st[2*si].m[0]+st[2*si+1].m[0];
    st[si].m[1]=st[2*si].m[1]+st[2*si+1].m[1];
    st[si].m[2]=st[2*si].m[2]+st[2*si+1].m[2];
}
// for range sum problem at each node of seg tree,we store range sum at each node.


// for this problem at each node of seg tree, we should store 
// number of multiples of 3 in the given range at each node.
// but the prob is how we will know 
// how many multiples are present now after update?
// therefore, we will not only keep no. of elements whose % 3=0
// but will also keep no. of elements whose % 3=1 and 2  


// moreover update in a range, just means a right shift
// for example we have 3 elements 1 2 2 and 
//  count of elements having mod%3=0, 1 and 2 = {1, 2, 2}
// after shifting right, we get 
// count of elements having mod%3=0, 1 and 2 = {2, 1, 2}
// which is correct

// if we have to update range by val, we will perform val right shifts.

void solve(){
    int n,q;
    cin>>n>>q;
    build(1,1,n);
    while(q--){
        int x,l,r;
        cin>>x>>l>>r;
        if(x==0){
            update(1, 1, n, l+1, r+1,1);
        }
        else{
            cout<<query(1,1,n,l+1,r+1)<<endl;
        }
    }
}


int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
{
solve();
}
return 0;
}