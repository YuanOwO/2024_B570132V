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

signed main() {
    IOS;
    int sh, sm, eh, em;
    while (cin >> sh >> sm >> eh >> em) {
        int dh = eh - sh, dm = em - sm;
        while (dm < 0) {
            dh--;
            dm += 60;
        }
        while (dm >= 60) {
            dh++;
            dm -= 60;
        }
        if (dm) {
            dh++;
        }
        int price = 0;
        if (dh >= 10) {
            price += 30 * (dh - 10);
            dh = 10;
        }
        if (dh >= 2) {
            price += 40 * (dh - 2);
            dh = 2;
        }
        price += 50 * dh;

        cout << price << endl;
    }
}
