#include <bits/stdc++.h>
using namespace std;

int T, Q;
priority_queue<int, vector<int>, greater<>> minHeap, emptyHeap;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    while (T--) {
        cin >> Q;

        while (Q--) {
            int com;
            cin >> com;

            if (com == 1) {
                cout << minHeap.top() * 2 << '\n';
                emptyHeap.push(minHeap.top());
                // cout << "EMPTY HEAP PUSHED : " << minHeap.top() << '\n';
                minHeap.pop();
            }
            
            else {
                int cnt;
                cin >> cnt;
                // cnt = min(cnt, 200200);
                
                int i = 0;
                while (cnt--) {
                    if (emptyHeap.empty()) i++;

                    else {
                        i = emptyHeap.top();
                        while (!emptyHeap.empty() && i == emptyHeap.top()) emptyHeap.pop();
                    }
                    // cout << "chickens : " << cnt << ' ' << i << '\n';
                    minHeap.push(i);
                }
                
                cout << i*2 << '\n';
                emptyHeap.push(i+1);
                // cout << "EMPTY HEAP PUSHED : " << i+1 << '\n';
            }

            // if (emptyHeap.empty())cout << "EEEE" << emptyHeap.top() << '\n';
        }
    }
}