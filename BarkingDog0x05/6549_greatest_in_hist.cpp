#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n, tmp;
    long long area[100001];
    stack<pair<long long, long long>> iput;
    stack<pair<long long, long long>> ims_fwd;
    stack<pair<long long, long long>> ims_rvs;

    while (true) {
        fill(area, area+100001, 0);
        while(!iput.empty())
            iput.pop();

        cin >> n;
        if (n == 0) {
            break;
        }

        for (long long i = 1; i <= n+1; i++) {
            if (i < n+1) {
                cin >> tmp;
                iput.push({tmp, i});
            }
            else {
                tmp = 0;
            }

            while (ims_fwd.empty() == 0 && tmp < ims_fwd.top().first) {
                area[ims_fwd.top().second] = ims_fwd.top().first * (i - ims_fwd.top().second);
                ims_fwd.pop();
            }

            ims_fwd.push({tmp, i});
        }

        for (long long j = n; j >= 0; j--) {
            if (j > 0) {
                tmp = iput.top().first;
                iput.pop();
            }

            else {
                tmp = 0;
            }

            while (ims_rvs.empty() == 0 && tmp <= ims_rvs.top().first) {
                if (tmp < ims_rvs.top().first) {
                    area[ims_rvs.top().second] = area[ims_rvs.top().second] + ims_rvs.top().first * (ims_rvs.top().second - j - 1);
                }

                ims_rvs.pop();
            }

            ims_rvs.push({tmp, j});
        }

        auto max = max_element(area, area+100001);
        cout << *max << '\n';
    }
}