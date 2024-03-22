#include <cstdio>
#include <iomanip>
#include <ios>
#include <iostream>
#include <sstream>
#include <array>
#include <bitset>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>
#include <cfloat>
#include <climits>
#include <cstdint>
#include <numeric>
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iterator>
#include <utility>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long

using namespace std;

const int MXN = 2e6 + 5;

unsigned long long dp[MXN];

signed main() {
    IOS;
    int n;
    while (cin >> n) {
        cout << "[";
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            for (int j = i - 1; j > 0; j--)
                dp[j] = dp[j - 1] + dp[j];
            // if (i <= 100)
            // else {
            //     dp[0] = 0;
            // }
            cout << "[";
            for (int j = 0; j <= i; j++) {
                cout << dp[j] << ",]"[j==i];
            }
            cout << ",]"[i==n-1];
        }
        cout << endl;
    }
    return 0;
}
