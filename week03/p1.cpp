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

    string line;
    while (cin >> line) {
        int i = 1, s = 0;
        for (auto &&n : line)
            if ('0' <= n && n <= '9' && i < 10)
                s += (n - '0') * i++;
        s %= 11;
        if (s == line[line.length() - 1] - '0')
            cout << "OK\n";
        else
            cout << line.substr(0, line.length() - 1) << s << endl;
    }
    return 0;
}
