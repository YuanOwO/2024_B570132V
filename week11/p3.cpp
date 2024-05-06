#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 30;

int pos[MAX_N];         // 第 i 個積木在哪一列
stack<int> row[MAX_N];  // 第 i 列有哪些積木，越晚進來的在越上面
stack<int> buf;         // 暫存積木

void move(int x, int to) {
    pos[x] = to;
    row[to].push(x);
}

int main() {
    int n;
    while (cin >> n) {
        if (!n)
            break;
        string cmd1, cmd2;
        int a, b;
        for (int i = 0; i < n; i++) {  // 初始化
            move(i, i);
        }
        while (cin >> cmd1) {
            if (cmd1 == "quit") {
                for (int i = 0; i < n; i++) {  // 輸出
                    while (!row[i].empty()) {
                        buf.push(row[i].top());
                        row[i].pop();
                    }
                    cout << i << ":";
                    while (!buf.empty()) {
                        cout << " " << buf.top();
                        buf.pop();
                    }
                    cout << endl;
                }
                break;
            }

            cin >> a >> cmd2 >> b;
            // cout << cmd1 << " " << a << " " << cmd2 << " " << b << endl;

            if (pos[a] == pos[b])  // 忽略不合法的指令
                continue;

            auto &row_a = row[pos[a]], &row_b = row[pos[b]];
            if (cmd2 == "onto") {  // onto 要 b 之上的積木搬回原位
                while (!row_b.empty() && row_b.top() != b) {
                    move(row_b.top(), row_b.top());
                    row_b.pop();
                }
            }
            while (!row_a.empty() && row_a.top() != a) {  // 取出 a 之上的積木
                buf.push(row_a.top());
                row_a.pop();
            }
            move(a, pos[b]);  // a 移到 b 之上
            row_a.pop();
            if (cmd1 == "move") {  // a 之上的積木搬回原位
                while (!buf.empty()) {
                    move(buf.top(), buf.top());
                    buf.pop();
                }
            } else {  // pile 要 a 之上的積木搬到 b 之上
                while (!buf.empty()) {
                    move(buf.top(), pos[b]);
                    buf.pop();
                }
            }
        }
    }
    return 0;
}
