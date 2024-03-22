#include <iostream>
#include <map>
#include <tuple>
#include <utility>
#define a second
#define b first
#define c pair<e, e>
#define d tuple<e, e, e>
#define e long long
#define f get

using namespace std;

map<c, d> j;

d g(c i, c h) {
    if (j.count(i))
        return j[i];
    d a, b;
    f<0>(a) = 1;
    if (i.b != i.a && i.a)
        a = g({i.b - 1, i.a}, h), b = g({i.b - 1, i.a - 1}, h);
    f<0>(a) += f<0>(b);
    i == h ? (f<1>(a) = f<2>(a) = 1) : (f<1>(a) += f<1>(b), f<2>(a) += f<2>(b));
    f<1>(j[i] = a) = i == h;
    return a;
}

int main() {
    c a, b;
    while (cin >> a.b >> a.a >> b.b >> b.a) {
        j.clear();
        if (a.b < a.a)
            cout << "error\n";
        else
            ([&](d a) { cout << f<0>(a) << ' ' << f<1>(a) << ' ' << f<2>(a) << '\n'; })(g(a, b));
    }
    return 0;
}
