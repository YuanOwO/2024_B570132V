#include <bits/stdc++.h>

using namespace std;

int arr[1008];

int main() {
    int n, q, t = 1;
    while (cin >> n >> q && n && q) {
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        cout << "CASE# " << t++ << ":\n";
        for (int i = 0; i < q; i++)
        {
            int target;
            cin >> target;
            auto idx = find(arr, arr + n, target) - arr;
            if (idx < n && arr[idx] == target)
                cout << target << " found at " << (idx + 1) << endl;
            else
                cout << target << " not found\n";
        }
    }
    return 0;
}
