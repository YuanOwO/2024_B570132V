#include <bits/extc++.h>
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
// #define int long long
#define endl '\n'
#define INF 0x7f7f7f7f7f7f7f7fLL
#define pss pair<string, string>

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

int table[105][105];
int row[105], down[105], up[105];
int n, cnt;

void dfs(int r, int c) {
    // for (int i = c * 2; i > 0; i--)
    //     cout << " ";
    // cout << "(r, c) = (" << r << ", " << c << ")\n";
    if (row[r] || down[r - c + n] || up[r + c]) {
        return;
    }
    if (c == n - 1) {
        // for (int i = c * 2; i > 0; i--)
        //     cout << " ";
        // cout << "++\n";
        cnt++;
        return;
    }
    row[r] = down[r - c + n] = up[r + c] = 1;
    for (int i = 0; i < n; i++) {
        dfs(i, c + 1);
    }
    row[r] = down[r - c + n] = up[r + c] = 0;
}

signed main() {
    IOS;
    while (cin >> n) {
        cnt = 0;
        // cout << "N = " << n << endl;
        for (int i = 0; i < n; i++) {
            dfs(i, 0);
        }
        cout << cnt << endl;
    }
}
