#include <bits/stdc++.h>
using namespace std;

int T, R, B;
vector<pair<int, bool>> V;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<int, vector<int>, greater<>> minHeap;

    minHeap.push(1);
    minHeap.push(4);
    minHeap.push(3);
    minHeap.push(2);
    
    cout << minHeap.top();
    minHeap.pop();
    cout << minHeap.top();
}