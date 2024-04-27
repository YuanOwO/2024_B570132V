#include <bits/stdc++.h>

using namespace std;

template <typename T>
T sum(T &acc, T &cur) {
    return acc += cur;
}

template <typename T>
T abs_sum(T &acc, T &cur) {
    return acc += abs(cur);
}

template <typename T>
T product(T &acc, T &cur) {
    return acc *= cur;
}

template <typename T, typename fn_type>
T compute(fn_type fn, T arr[], int S, T v) {
    for (int i = 0; i < S; i++)
        fn(v, arr[i]);
    return v;
}

int main() {
    // 請勿更動main()函式裡的程式碼
    // Please do not modify the code inside the main() function.
    int foo[10];
    int S;
    cin >> S;
    for (int i = 0; i < S; i++)
        cin >> foo[i];
    int v;
    v = 0;
    cout << compute(sum<int>, foo, S, v) << endl;
    v = 0;
    cout << compute(abs_sum<int>, foo, S, v) << endl;
    v = 1;
    cout << compute(product<int>, foo, S, v) << endl;
    return 0;
}
