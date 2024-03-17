#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("inline")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse", "sse2", "sse3")
#pragma GCC target("sse4", "sse4.1", "sse4.2", "ssse3")
#pragma GCC target("abm", "avx", "mmx", "popcnt")
#pragma GCC target("f16c")
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define endl '\n'
#define pii pair<int, int>
#define INF 0x7f7f7f7f7f7f7f7fLL

using namespace std;

signed main() {
    IOS;
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        double p;
        cin >> n >> p >> i;
        double ans = pow(1 - p, i - 1) * p;
        ans *= 1 / (1 - pow(1 - p, n));
        cout << fixed << setprecision(4) << ans << endl;
    }
    return 0;
}
