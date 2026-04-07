#include <bits/stdc++.h>
using namespace std;

int N;
string arr[51];

bool cmp(const string & a, const string & b) {
    if (a.length() != b.length()) return a.length() < b.length();
    else {
        int asum = 0, bsum = 0;
        
        for (char c : a) {
            if (c >= '0' && c <= '9') asum += c-'0';
        }
        for (char c : b) {
            if (c >= '0' && c <= '9') bsum += c-'0';
        }
        
        if (asum != bsum) return asum < bsum;
        else return a < b;
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    for (int i = 0; i < N; i++) cin >> arr[i];
    
    sort(arr, arr+N, cmp);
    
    for (auto s : arr) cout << s << '\n';
}