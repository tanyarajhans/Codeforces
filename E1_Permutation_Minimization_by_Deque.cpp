#include <bits/stdc++.h>

using namespace std;
#define ll long long
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
 




int main(){
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    deque<int> v;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    
    v.push_back(a[0]);
    bool b=false;
    for(int i=1;i<n;i++){
    if(a[i]<v.front()){
            v.push_front(a[i]);
        }
     else{
          v.push_back(a[i]);
     }
            
    }
    for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";
    cout<<endl;
}
return 0;
}