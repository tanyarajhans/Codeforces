

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

bool solve(int a[], int n, int s){
    bool t[n+1][s+1];
    t[0][0]=true;
 for(int i=1;i<n+1;i++){
            t[i][0]=false;
        }
        for(int i=1;i<s+1;i++){
            t[0][i]=false;
        }
        
         for(int i=1;i<n+1;i++){
              for(int j=1;j<s+1;j++){
                  if(nums[i-1]>j){
                      t[i][j]=t[i-1][j];
                  }
                  else if(nums[i-1]<=j){
                      t[i][j]=t[i-1][j] || t[i-1][j-nums[i-1]];
                  }
              }
         }
        return t[n][s];
}

int find(int a[], int n, int s){
   int t[n+1][s+1];
    t[0][0]=0;
 for(int i=1;i<n+1;i++){
            t[i][0]=1;
        }
        for(int i=1;i<s+1;i++){
            t[0][i]=0;
        }
        
         for(int i=1;i<n+1;i++){
              for(int j=1;j<s+1;j++){
                  if(nums[i-1]>j){
                      t[i][j]=t[i-1][j];
                  }
                  else if(nums[i-1]<=j){
                      t[i][j]=t[i-1][j] || t[i-1][j-nums[i-1]];
                  }
              }
         }
        return t[n][s];
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int tc;
cin>>tc;
while(tc--){
    int n,k;
    cin>>n>>k;
    int a[n];
    int s=k,sum=0;
    for(int i=0;i<n;i++){
    cin>>a[i];
    sum+=a[i];
    }
    bool ans=solve(a,n,s);
    if(ans==true && sum-k>k){
        cout<<find(a,n,s)<<endl;
    }
    else
    {
        /* code */cout<<"-1"<<endl;
    }
    
}
return 0;
}