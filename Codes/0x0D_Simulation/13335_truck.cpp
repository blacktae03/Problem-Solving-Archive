#include <bits/stdc++.h>
using namespace std;

int n, w, L, tmp, sum, t;
queue<int> truck;
deque<int> bridge;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> w >> L;
    
    for (int i = 0; i < w; i++) bridge.push_back(0);
    for (int i = 0; i < n; i++) { cin >> tmp; truck.push(tmp); }

    while(true) {
        if (truck.empty() && !sum) break;

        if (!truck.empty()) tmp = truck.front();
        else tmp = 0;

        sum -= bridge.front();
        bridge.pop_front();
        
        if (tmp && sum + tmp <= L) {
            truck.pop();
            bridge.push_back(tmp);
            sum += tmp;
        }

        else {
            bridge.push_back(0);
        }
        t++;
    }

    cout << t;
}