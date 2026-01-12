#include <iostream>

using namespace std;

int main() {
    int N, K, W, V, fW, fV;

    cin >> N >> K;

    int tool[K+1] = {0,};
    int max = tool[0];

    for (int i = 0; i < N; i++) {
        cin >> W >> V;
        int fW = W;
        int fV = V;

        while(W+fW <= K && tool[W] != 0) {
            // if(V > tool[W]) {
            //     tool[W+fW] = V + tool[W];
            // }
            W += fW;
            V += tool[W];
        }

        if(V > tool[W])
            tool[W] = V;
    }

    for (int i = K; i >= 1; i--) {
        for (int j = 1; j < (i+1)/2; j++) {
            if(tool[i-j] + tool[j] > tool[i])
                tool[i] = tool[i-j] + tool[j];
        }
    }

    for (int i = 0; i < K+1; i++) {
        cout << "v(" << i << ") = " << tool[i] << "\n";
        if(max < tool[i]) max = tool[i];
    }

    cout << max;
}