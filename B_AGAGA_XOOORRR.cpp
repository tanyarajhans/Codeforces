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
// int a[32];
// string s;
// string bin(ll n)
// {
//     if (n > 1)
//         bin(n >> 1);
 
//     s+=(n & 1);
//     return s;
// }
ll a[2003];
ll xorr(int x, int y){
    ll p=0;
for(int i=x;i<y;i++){
        p^=a[i];
        
    }
    return p;
}
 
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
w(t){
        int n;
		cin >> n;
		int arr[n];
		int xor_sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			xor_sum ^= arr[i];
			
		}
		
		if (xor_sum == 0) {
			cout << "YES";
		} else {
			int index1 = 0;
			int index2 = n - 1;
			int p = 0;
			int q = 0;
			while (index1 < n) {
				p ^= arr[index1];
				if (p == xor_sum)
					break;
				index1++;
			}
			while (index2 >= 0) {
				q ^= arr[index2];
				if (q == xor_sum)
					break;
				index2--;
			}
			if (index1 < index2 - 1) {
				cout << "YES";
			} else {
				cout << "NO";
			}
		}
    cout<<endl;
}
return 0;
}