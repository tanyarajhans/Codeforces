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
    int a=0,b=0,c=0;
    string s;
    cin>>s;
    
    for(int i=0;i<s.size();i++){
        if(s[i]=='A')
        a++;
        else if(s[i]=='B')
        b++;
        else c++;
    }if(a+c==b)
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
}
return 0;
}