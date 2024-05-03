// 參考程式碼
#include <iomanip>
#include <iostream>
#include <list>
#include <vector>
using namespace std;
/*write code here
template <typename T> //可自由設計樣板 Abs, inner_product
...
…*/
template <class T>
struct Abs {
    T operator()(T value) {
        return value >= 0 ? value : -value;
    }
};

template <class InputIt1, class InputIt2, class T, class FN>
T inner_product(InputIt1 first1, InputIt1 last1, InputIt2 first2, T ans, FN func) {
    for (; first1 != last1; ++first1, ++first2) {
        ans += func(*first1) * func(*first2);
    }
    return ans;
}

int main() {  // 請勿更動main()函式的程式碼

    vector<int> a;
    list<int> b;
    int input, sum = 0;

    cin >> input;  // 將元素輸入至容器vector,list中
    for (int i = 0; i < input; i++) {
        int element;
        cin >> element;
        a.push_back(element);
    }
    for (int i = 0; i < input; i++) {
        int element;
        cin >> element;
        b.push_back(element);
    }
    // 輸出兩個容器元素的絕對值乘積和
    cout << inner_product(a.begin(), a.end(), b.begin(), sum, Abs<int>()) << endl;
    // cout << "The absolute inner product of a and b = " << inner_product(a.begin(), a.end(), b.begin(), sum,
    // Abs<int>())
    //      << endl;
    // Abs<int>()可看成Abs結構/類別中的運算子()覆載
    return 0;
}
