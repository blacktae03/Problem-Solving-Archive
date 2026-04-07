#include <bits/stdc++.h>
using namespace std;

int T, Q;
priority_queue<int, vector<int>, greater<>> minHeap;
set<int> emptySet;

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
                // emptySet.push(minHeap.top());
                emptySet.insert(minHeap.top());
                // cout << "EMPTY HEAP PUSHED : " << minHeap.top() << '\n';
                minHeap.pop();
            }
            
            else {
                int cnt;
                cin >> cnt;
                cnt = min(cnt, 200200);
                
                int i = 0;
                while (cnt--) {
                    if (emptySet.empty()) i++;

                    else {
                        i = *emptySet.begin();
                        while (!emptySet.empty() && i == emptySet.top()) emptySet.pop();
                    }
                    // cout << "chickens : " << cnt << ' ' << i << '\n';
                    minHeap.push(i);
                }
                
                cout << i*2 << '\n';
                emptySet.push(i+1);
                // cout << "EMPTY HEAP PUSHED : " << i+1 << '\n';
            }

            // if (emptySet.empty())cout << "EEEE" << emptySet.top() << '\n';
        }
    }
}