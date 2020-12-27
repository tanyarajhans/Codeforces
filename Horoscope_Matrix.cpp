

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


int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
cin>>t;

while(t--){
    vector< vector<long long> >s;
vector< vector<long long> >so;
    long long n,m;
    cin>>n>>m;
    long long x[n][m];
    for(int i=0;i<n;i++){
   for(int j=0;j<m;j++){
       cin>>x[i][j];
   }
    }
   for (int j = 0; j <= n + m- 2; j++) {
       vector<long long>s1;
            for (int k = 0; k <= j; k++) { // cols
            
                int l = j - k; //  rows
                int mirror = n - l;
                if (mirror >= 0 && mirror < n && k < m) {
                    s1.push_back(x[mirror][k]);
                }
            }
            s.push_back(s1);
        }

    int q;
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        long long v;
        cin>>v;
        long long val=x[a-1][b-1];
        x[a-1][b-1]=v;
        
  for (int j = 0; j <= n + m- 2; j++) {
       vector<long long>s2;
            for (int k = 0; k <= j; k++) { // cols
                int l = j - k; //  rows
                int mirror = n - l;
                if (mirror >= 0 && mirror < n && k < m) {
                    s2.push_back(x[mirror][k]);
                }
            }
            so.push_back(s2);
        }

        bool f=true;
for(int i=0;i<s.size();i++){
    for(int j=0;j<s[0].size();j++){
        if(s[i][j]!=so[i][j]){
            cout<<"No"<<endl;
            f=false;
            break;
        }
        if(f==false)
        break;
    }
     if(f==false)
        break;
}
if(f==true)
cout<<"Yes"<<endl;
x[a-1][b-1]=val;
so.clear();

        }
    


}
return 0;
}