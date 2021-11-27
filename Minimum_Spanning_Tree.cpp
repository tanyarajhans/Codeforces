

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
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
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

struct edge{
    int a;
    int b;
    int w;
};
edge ar[100001];
int p[10001];

bool cmp(edge a, edge b){
return (a.w<b.w);
}
int find(int a){
    if(p[a]==-1)
    return a;

    return p[a]=find(p[a]);
}

void merge(int a, int b){
p[a]=b;
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n,m;
cin>>n>>m;
for(int i=1;i<=n;i++){
    p[i]=-1; //size
}
for(int i=0;i<m;i++){
    cin>>ar[i].a>>ar[i].b>>ar[i].w;
}
int s=0;
sort(ar,ar+m,cmp);

for(int i=0;i<m;i++){
   int a=find(ar[i].a);
   int b=find(ar[i].b);

    if(a!=b)
    {
        s+=ar[i].w;
        merge(a,b);
    }
    
    
}
cout<<s;
return 0;
}
