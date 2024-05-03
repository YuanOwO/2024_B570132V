#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// 請設計一樣板函式，完成找出最小排序數的功能

/**
 * @brief Count Leading Zero
 */
template <typename T>
int clz(T container) {
    int cnt = 0;
    for (auto &&i : container) {
        if (i != 0 && i != '0')
            break;
        cnt++;
    }
    return cnt;
}

template <typename T>
void smallestNumber(T container) {
    sort(container.begin(), container.end());
    while (clz(container) != 0)  // 0 開頭 => 換下一個組合
        next_permutation(container.begin(), container.end());

    // 輸出
    for (auto &&i : container)
        cout << i;
    cout << endl;
}

int main() {
    string str;
    std::cin >> str;
    smallestNumber(str);
    std::vector<int> nums;
    std::transform(str.begin(), str.end(), std::back_inserter(nums), [&](char c) { return c - '0'; });
    smallestNumber(nums);
}
