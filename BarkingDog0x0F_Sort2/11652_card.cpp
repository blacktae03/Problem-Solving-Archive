#include <bits/stdc++.h>
using namespace std;

long long N;
long long arr[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    for (long long i = 0; i < N; i++) cin >> arr[i];
    
    sort(arr, arr+N);
    long long tmp = arr[0];
    long long cnt = 0;
    long long mxcnt = 0;
    long long mxnum = arr[0];
    
    for (long long i = 0; i < N; i++) {
        if (arr[i] == tmp) {
            cnt++;
        }
        
        else {
            if (cnt > mxcnt) {
                mxcnt = cnt;
                mxnum = tmp;
            }
            
            cnt = 1;
            
            tmp = arr[i];
        }
    }
    
    if (cnt > mxcnt) {
        mxcnt = cnt;
        mxnum = tmp;
    }
    
    
    cout << mxnum;
    
    
}