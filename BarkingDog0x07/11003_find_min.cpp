#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int len, quelen, tmp;
    queue<int> iput;
    deque<int> imd;

    cin >> len >> quelen;

    for (int i = 0; i < len; i++) {
        cin >> tmp;
        iput.push(tmp);

        while (imd.empty() == 0 && tmp < imd.back()) {
            imd.pop_back();
        }

        imd.push_back(tmp);

        if (i >= quelen) {
            if (iput.front() == imd.front())
                imd.pop_front();
            iput.pop();
        }

        cout << imd.front() << ' ';
    }
}