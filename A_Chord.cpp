

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
  


int main(){
string s1,s2,s3;
cin>>s1>>s2>>s3;
string s[]={s1,s2,s3};
vector<string> a(24);
a.push_back("C");
a.push_back("C#");
a.push_back("D");
a.push_back("D#");
a.push_back("E");
a.push_back("F");
a.push_back("F#");
a.push_back("G");
a.push_back("G#");
a.push_back("A");
a.push_back("B");
a.push_back("H");
a.push_back("C");
a.push_back("C#");
a.push_back("D");
a.push_back("D#");
a.push_back("E");
a.push_back("F");
a.push_back("F#");
a.push_back("G");
a.push_back("G#");
a.push_back("A");
a.push_back("B");
a.push_back("H");

sort(s,s+3);
do{
int x,y,z;
for(int i=0;i<a.size();i++)
if(a[i]==s[0]){
    x=i;
    break;
}
for(int i=x+1;i<a.size();i++)
if(a[i]==s[1]){
    y=i;
    break;
}
for(int i=y+1;i<a.size();i++)
if(a[i]==s[2]){
    z=i;
    break;
}
if(y-x==4 && z-y==3)
{
cout<<"major";
    return 0;
}
else if(y-x==3 && z-y==4){
cout<<"minor";
return 0;
}
}
while(next_permutation(s,s+3));


  cout<<"strange";


    return 0;
}
