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

int count(string str, char tar) {
    int cnt = 0;
    for (auto &&chr : str)
        if (chr == tar)
            cnt++;
    return cnt;
}

signed main() {
    IOS;
    int t = 1;
    string str;
    while (cin >> str) {
        if (t != 1)
            cout << endl;
        cout << "AB Circle #" << t++ << ":\n";
        for (int i = 0; i < str.length(); i++) {
            for (int j = i + 1; j < str.length(); j++) {
                string a = str.substr(i, j - i);
                string b = str.substr(j) + str.substr(0, i);
                // cout << "(i, j) = (" << i << ", " << j << ")\n";
                // cout << "a = " << a << endl;
                // cout << "b = " << b << endl;
                if (count(a, 'a') == count(b, 'b') || count(a, 'b') == count(b, 'a'))
                    cout << i << "," << j << endl;
            }
        }
    }
}
