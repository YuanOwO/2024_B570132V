#include <bits/stdc++.h>

using namespace std;

struct Time {
    int hr, min;
};

bool operator<(Time &lhs, Time &rhs) {
    return lhs.hr * 60 + lhs.min < rhs.hr * 60 + rhs.min;
}

Time arr[2000005];

int main() {
    int n = 0;
    char tmp;
    while (cin >> arr[n].hr >> tmp >> arr[n].min)
        n++;
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
        cout << setfill('0') << setw(2) << arr[i].hr << ':' << setw(2) << arr[i].min << " \n"[i == n - 1];
    return 0;
}
