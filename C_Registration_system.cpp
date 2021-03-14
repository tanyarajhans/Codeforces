#include<bits/stdc++.h>
#include <map>
using namespace std;

int main(){
map <string, int> m;
int n;
cin>>n;
while(n--){
    string s;
    cin>>s;
    if(m.find(s)==m.end()){
        cout<<"OK";
        m[s]=1;
    }
    else{
    cout<<s<<m[s];
    m[s]++;
    }
    
    cout<<endl;
}
return 0;
}