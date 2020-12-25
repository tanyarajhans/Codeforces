

#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cuchar>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <codecvt>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

#if __cplusplus >= 201402L
#include <shared_mutex>
#endif

#if __cplusplus >= 201703L
#include <any>
#include <charconv>
// #include <execution>
#include <filesystem>
#include <optional>
#include <memory_resource>
#include <string_view>
#include <variant>
#endif

#if __cplusplus > 201703L
#include <bit>
#include <compare>
#include <concepts>
#if __cpp_impl_coroutine
# include <coroutine>
#endif
#include <latch>
#include <numbers>
#include <ranges>
#include <span>
#include <stop_token>
#include <semaphore>
#include <syncstream>
#include <version>
#endif
using namespace std;


// Tanya Rajhans
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b); 
     
}
   long long pf[10000001];
   void prime(){
       memset(pf,0,10000001);
       pf[0]=pf[1]=1;
   for(long long i=2;i<10000001;i++){
        if(pf[i]==0){
            for(long long j=i*i;j<10000001;j=j+i)
                  pf[j]=1;
        }
    }
}

int check_ps(long long n){
    double sqrt_n = sqrt(n);
    if(sqrt_n == int(sqrt_n)){
        return 1;
    }
    else{
        return 0;
    }
}
vector<int> adj[100001];
vector<int> primes;
int vis[100001];
int dist[100001];

bool isprime(int n){
    for(int i=2; i*i<=n;i++){
        if(n%i==0)
        return false;
    }
    return true;
}
bool isValid(int a, int b){
    int c=0;
    while(a>0 || b>0){
        if((a%10) != (b%10))
        c++;
        a=a/10;
        b=b/10;
    }
    if(c==1)
    return true;
    else
    {
        return false;
    }
    
}
void buildGraph(){
    for(int i=1000;i<=9999;i++){
        if(isprime(i)){
            primes.push_back(i);
        }
    }

    for(int i=0;i<primes.size();i++){
        for(int j=i+1;j<primes.size();j++){
            int a=primes[i];
            int b=primes[j];

            if(isValid(a,b)){
                adj[a].push_back(b);
                adj[b].push_back(a);
            }
        }
    }
}
void bfs(int x){
queue<int> q;
q.push(x);
vis[x]=1;
dist[x]=0;
while(!q.empty()){
    int curr=q.front();
    q.pop();
    for(int u=0;u<adj[curr].size();u++){
         int child=adj[curr][u];
        if(!vis[child]){
            
            vis[child]=1;
            dist[child]=dist[curr]+1;
            q.push(child);
        }
    }
}
}


int main(){
int t;
cin>>t;
buildGraph();
while(t--){
int a,b;
cin>>a>>b;

for(int i=1000; i<=9999;i++){
    dist[i]=-1;
   
    vis[i]=0;
}

bfs(a);
if(dist[b]==-1)
cout<<"Impossible"<<endl;
else
{
    /* code */
    cout<<dist[b]<<endl;
}


}
return 0;
}