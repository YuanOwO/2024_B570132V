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

using namespace std;

signed main() {
    IOS;
    vector<string> garbage;
    string cmd, x, n;
    while (cin >> cmd) {
        if (cmd == "ADD") {
            cin >> x;
            garbage.push_back(x);
        } else if (cmd == "INSERT") {
            cin >> x >> n;
            auto it = find(garbage.begin(), garbage.end(), n);
            garbage.insert(it, x);
        } else if (cmd == "REMOVE") {
            cin >> x;
            auto it = find(garbage.begin(), garbage.end(), x);
            garbage.erase(it);
        } else {  // SHOW
            for (auto word : garbage) {
                cout << word << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
