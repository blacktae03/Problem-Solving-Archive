#include <bits/stdc++.h>
using namespace std;

int N;
priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<>> minHeap;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    int tmp; cin >> tmp;
    maxHeap.push(tmp);
    cout << tmp << '\n';
    
    for (int i = 0; i < N-1; i++) {
        cin >> tmp;
        if (tmp > maxHeap.top())

        if (minHeap.empty() || tmp > minHeap.top()) minHeap.push(tmp);
        else maxHeap.push(tmp);
        
        // if (!i) cout << tmp << '\n';
        cout << min(maxHeap.top(), minHeap.top()) << '\n';
    }
}

// 최대힙과 최소힙 두개를 활용
// 1 : 1 | x
// 5 : 1 | 5
// 2 : 2 1 | 5
// 10 : 2 1 | 5 10
// -99 : 2 1 -99 | 5 10
// 7 : 2 1 -99 | 5 7 10
// 5 : 5 2 1 -99 | 5 7 10


// 1