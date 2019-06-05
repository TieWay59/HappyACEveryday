#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1000005;
int phi[N];

void Init() {
    phi[1] = 1;
    for (int i = 2; i < N; i++) {
        if (!phi[i])
            for (int j = i; j < N; j += i) {
                if (!phi[j])phi[j] = j;
                phi[j] = phi[j] / i * (i - 1);
            }
    }
}

int main() {
    Init();
    int n;
    while (scanf("%d", &n) != EOF) {
        printf("%d\n", phi[n]);
    }
    return 0;
}

