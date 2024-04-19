#pragma GCC diagnostic ignored "-Wattributes"
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC target("sse", "sse2", "sse3")
#pragma GCC target("sse4", "sse4.1", "sse4.2", "ssse3")
#pragma GCC target("abm", "avx", "mmx", "popcnt")
#pragma GCC target("f16c")
// C
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
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
#  include <cfenv>
#  include <cinttypes>
#  include <cstdint>
#  include <cuchar>
#  if __cplusplus < 201703L
#    include <ccomplex>
#    include <cstdalign>
#    include <cstdbool>
#    include <ctgmath>
#  endif
#endif
#if __cplusplus < 202002L
#  include <ciso646>
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
#  include <array>
#  include <atomic>
#  include <chrono>
#  include <condition_variable>
#  include <forward_list>
#  include <future>
#  include <initializer_list>
#  include <mutex>
#  include <random>
#  include <ratio>
#  include <regex>
#  include <scoped_allocator>
#  include <system_error>
#  include <thread>
#  include <tuple>
#  include <type_traits>
#  include <typeindex>
#  include <unordered_map>
#  include <unordered_set>
#  if _cplusplus < 201703L
#    include <codecvt>
#  endif
#endif
#if __cplusplus >= 201402L
#  include <shared_mutex>
#endif
#if __cplusplus >= 201703L
#  include <any>
#  include <charconv>
#  include <execution>
#  include <filesystem>
#  include <memory_resource>
#  include <optional>
#  include <string_view>
#  include <variant>
#endif
#if __cplusplus >= 202002L
#  include <barrier>
#  include <bit>
#  include <compare>
#  include <concepts>
#  include <coroutine>
#  include <format>
#  include <latch>
#  include <numbers>
#  include <ranges>
#  include <semaphore>
#  include <source_location>
#  include <span>
#  include <stop_token>
#  include <syncstream>
#  include <version>
#endif
#if __cplusplus >= 202302L
#  include <expected>
#  include <flat_map>
#  include <flat_set>
#  include <generator>
#  include <mdspan>
#  include <print>
#  include <spanstream>
#  include <stacktrace>
#  include <stdfloat>
#endif
#if __cplusplus >= 202600L
#  include <debugging>
#  include <linalg>
#  include <rcu>
#  include <text_encoding>
#endif
#define int long long
#define pii pair<int, int>
#define endl '\n'
#define lowbit(x) (x & -x)
#define cl(x) (x << 1)
#define cr(x) (x << 1 | 1)
#define NO_TAG 0
#define INF 0x7f7f7f7f7f7f7f7fLL
using namespace std;
const int MXN = 2e6 + 5;
const int MOD = 1e9 + 7;
mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
int randint(int a, int b) {
    return uniform_int_distribution<int>(a, b)(mt);
}
//                  !#########       #
//                !########!          ##!
//             !########!               ###
//          !##########                  ####
//        ######### #####                ######
//         !###!      !####!              ######
//           !           #####            ######!
//                         !####!         #######
//                            #####       #######
//                              !####!   #######!
//                                 ####!########
//              ##                   ##########
//            ,######!          !#############
//          ,#### ########################!####!
//        ,####'     ##################!'    #####
//      ,####'            #######              !####!
//     ####'                                      #####
//     ~##                                          ##~
//                    同志保佑 永無BUG

void solve();
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}

//                                   @
//                (__)    (__) ____/ Hong~Long~Long~Long~
//             /| (oo) _  (oo)/----/_____
//   _o\______/_|\_\/_/_|__\/|____|//////== *- *  * -
//  /__________  \   AC |  AC | NO BUG /== -*
// [_____/^^\_____\_____|_____/^^\_____]     *- * -
//       \__/                 \__/      Chong~Chong~Chong~

int table[] = {1, 10, 19, 28, 37, 46, 55, 64, 39, 73, 82, 2, 11, 20, 48, 29, 38, 47, 56, 65, 74, 83, 21, 3, 12, 30};

void solve() {
    string id;
    while (cin >> id) {
        int s = table[id[0] - 'A'];
        for (int i = 1; i < id.length(); i++)
            s += (id[i] - '0') * max(9 - i, 1LL);
        if (s % 10)
            cout << "invalid\n";
        else
            cout << "valid\n";
    }
}