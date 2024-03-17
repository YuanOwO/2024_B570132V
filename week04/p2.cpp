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

const int MXN = 2e3 + 5;

pii pts[MXN];
int mp[MXN][MXN];
int n, m;

void print() {
    for (int y = 1; y <= m; y++)
        for (int x = 1; x <= n; x++)
            cout << mp[x][y] << " \n"[x == n];
}

void bomb(int x, int y) {
    mp[x][y] = 0;
    for (int dx = -2; dx <= 2; dx++) {
        for (int dy = -2; dy <= 2; dy++) {
            int x2 = x + dx, y2 = y + dy;
            if (0 < x2 && x2 <= n && 0 < y2 && y2 <= m && mp[x2][y2])
                bomb(x2, y2);
        }
    }
}

signed main() {
    IOS;
    int k;
    cin >> n >> m >> k;

    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        mp[x][y] = 1;
        pts[i] = {x, y};
    }

    int cnt = 0;
    for (int i = 0; i < k; i++) {
        auto x = pts[i].first, y = pts[i].second;
        if (mp[x][y]) {
            // cout << x << " " << y << endl;
            // print();
            bomb(x, y);
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
