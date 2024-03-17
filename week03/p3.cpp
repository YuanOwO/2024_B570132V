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

const int MXN = 501;

int comb[MXN][MXN];

int calc(string token, int start, int length) {
    int sum = 0;
    --length;
    for (int i = 0; i <= length; i++)
        sum = (sum + (token[start + i] - '0') * comb[length][i]) % 10;
    return sum;
}

int convert(string token, int st) {
    stringstream ss;
    for (auto &&c : token)
        ss << st + c - 'A';
    ss >> token;

    int l = token.length() - 2;
    int a = calc(token, 0, l), b = calc(token, 1, l), c = calc(token, 2, l);
    if (a == 1 && b == 0 && c == 0)
        return 100;
    else
        return (a + b) % 10 * 10 + (b + c) % 10;
}

signed main() {
    IOS;
    for (int i = 0; i < MXN; i++) {
        comb[i][0] = comb[i][i] = 1;
        for (int j = 1; j < i; j++)
            comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % 10;
    }

    string token;
    while (cin >> token) {
        // cout << token << endl;
        bool found = 0;
        for (int i = 1; i < 10000; i++) {
            if (convert(token, i) == 100) {
                cout << i << endl;
                found = 1;
                break;
            }
        }
        if (!found)
            cout << ":(\n";
    }
    return 0;
}
