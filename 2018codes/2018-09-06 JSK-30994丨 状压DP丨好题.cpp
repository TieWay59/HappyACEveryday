#include<stdio.h>
#include<algorithm>
#include<string.h>

using namespace std;
typedef long long ll;
const int N = 21;
ll dp[1 << N], ans;
int a[N], b[N], pre[N];

int Count1(int x) {
    int res = 0;
    for (int i = 0; i < N; i++)
        if (x & (1 << i))res++;
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0, s; i < n; i++) {
        scanf("%d%d%d", a + i, b + i, &s);
        for (int j = 1, p; j <= s; j++) {
            scanf("%d", &p);
            pre[i] += 1 << (p - 1);
        }
    }
    memset(dp, 0x80, sizeof dp);
    dp[0] = 0;
    int FState = (1 << n) - 1;

    for (int i = 1; i <= FState; i++)
        for (int j = 0, u, v; j < n; j++) {
            if (!(i & (1 << j)))
                continue;
            u = i - (1 << j);
            if ((u & pre[j]) != pre[j])
                continue;

            ll w = dp[u] + a[j] * Count1(i) + b[j];
            ans = max(dp[i] = max(dp[i], w), ans);
        }
    printf("%lld\n", ans);
    return 0;
}
/*
5
5 6 0
4 5 1 1
3 4 1 2
2 3 1 3
1 2 1 4
*/
