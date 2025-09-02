#include <bits/stdc++.h>
using namespace std;

// bool cmp(int & a, int b) {
//     if (abs(a) == abs(b)) return a < b;
//     return abs(a) < abs(b);
// }

struct cmp {
    bool operator() (int a, int b) {
        if (abs(a) == abs(b)) return a > b;
        return abs(a) > abs(b);
	}
};

int N;
priority_queue<int, vector<int>, cmp> pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    
    while(N--) {
        int x; cin >> x;

        if (x) pq.push(x);
        else {
            if (pq.empty()) cout << 0 << '\n';
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
    }

}