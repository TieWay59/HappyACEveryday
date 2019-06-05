/*HDU-6434
http://acm.hdu.edu.cn/showproblem.php?pid=6434

*/
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 20000005;
int phi[N];
ll ans[N];

void Init() {
    phi[1] = 1;
    ans[1] = phi[1] / 2;
    for (int i = 2; i < N; i++) {
        if (!phi[i])
            for (int j = i; j < N; j += i) {
                if (!phi[j])phi[j] = j;
                phi[j] = phi[j] / i * (i - 1);
            }
        if (i & 1) ans[i] = ans[i - 1] + phi[i] / 2;
        else ans[i] = ans[i - 1] + phi[i];
    }
}

int main() {
    Init();

    printf("%d %d ", phi[1], phi[2]);

    int T, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        printf("%lld\n", ans[n]);
    }

    return 0;
}

