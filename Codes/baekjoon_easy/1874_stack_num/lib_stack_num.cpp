#include <iostream>
#include <stack>
using namespace std;

string buf = "";

int main() {
    int N, tmp;
    stack<int> stk;
    int ntop = 0;
    stk.push(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> tmp;

        while(buf != "NO" && stk.top() < tmp) {
            stk.push(++ntop);
            buf += "+\n";
        }

        if (stk.top() > tmp) buf = "NO";
        if (buf != "NO") {
            stk.pop();
            buf += "-\n";
        }
    }

    cout << buf;

    return 0;
}