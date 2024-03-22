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

int dp[MXN];

signed main() {
    IOS;
    int n;
    while (cin >> n && n) {
        deque<int> deq, deq_bak;
        int x;
        for (int i = 1; i <= n; i++) {
            cin >> x;
            deq_bak.push_back(x);
        }
        int win = 0;

        for (int cas = (1 << n - 1) - 1; cas >= 0; cas--) {
            deq = deq_bak;
            int sc[] = {0, 0};
            for (int i = 0; i < n; i++) {
                if (i & 1) {
                    if (deq.front() > deq.back()){
                        // cout<<"0";
                        x = deq.front();
                        deq.pop_front();
                    } else {
                        // cout<<"1";
                        x = deq.back();
                        deq.pop_back();
                    }
                } else {
                    if ((cas >> (i >> 1)) & 1){
                        // cout<<"0";
                        x = deq.front();
                        deq.pop_front();
                    } else {
                        // cout<<"1";
                        x = deq.back();
                        deq.pop_back();
                    }
                }
                sc[i & 1] += x;
            }
            if (sc[0] >= sc[1]) {
                win = 1;
                break;
            }
        }
        cout << (win ? "WIN\n" : "LOSE\n");
    }
    return 0;
}
