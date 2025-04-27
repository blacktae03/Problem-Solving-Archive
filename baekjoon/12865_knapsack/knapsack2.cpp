#include <iostream>

using namespace std;

int tool[100001] = {0,};
int K;

void sameWeight(int W, int V, int fW, int fV) {
    if (tool[W] > 0 && W+fW <= K)
        sameWeight(W+fW, tool[W] + fV, fW, fV);
    
    if (V > tool[W])
        tool[W] = V;
}

int main() {
    int N, W, V, fW, fV;

    cin >> N >> K;

    int max = tool[0];

    for (int i = 0; i < N; i++) {
        cin >> W >> V;
        int fW = W;
        int fV = V;
        sameWeight(W, V, fW, fV);
    }

    // for (int i = K; i >= 1; i--) {
    //     for (int j = 1; j < (i+1)/2; j++) {
    //         if(tool[i-j] + tool[j] > tool[i])
    //             tool[i] = tool[i-j] + tool[j];
    //     }
    // }
    for (int i = 1; i <= K; i++) {
        for (int j = 0; j < (i+1)/2 && tool[j] == 0; j++) {
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