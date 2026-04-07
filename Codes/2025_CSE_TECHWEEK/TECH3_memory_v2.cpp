#include <bits/stdc++.h>
using namespace std;

int T, Q;
// priority_queue<int, vector<int>, greater<>> minHeap, emptyHeap;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    priority_queue<int, vector<int>, greater<>> minHeap[T], emptyHeap[T];

    while (T--) {
        cin >> Q;

        while (Q--) {
            int com;
            cin >> com;

            if (com == 1) {
                cout << minHeap[T].top() * 2 << '\n';
                emptyHeap[T].push(minHeap[T].top());
                minHeap[T].pop();
            }
            
            else {
                int cnt;
                cin >> cnt;
                // cnt = min(cnt, 200200);
                
                int i = 0;
                while (cnt--) {
                    if (emptyHeap[T].empty()) i++;

                    else {
                        i = emptyHeap[T].top();
                        while (!emptyHeap[T].empty() && i == emptyHeap[T].top()) emptyHeap[T].pop();
                    }

                    minHeap[T].push(i);
                }
                
                cout << i*2 << '\n';
                emptyHeap[T].push(i+1);

            }
        }

        
    }
}