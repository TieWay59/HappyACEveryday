/*
��ϸ�汾
����DP����
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>

typedef long long ll;
const int N = 1e2 + 15;
const int mod = 1e9 + 7;
int n, m, dp[N << 1][N], lt[N << 1], rt[N << 1], ans;

int main() {
    scanf("%d", &n);
    m = n << 1;
    for (int i = 1; i <= n; i++)
        scanf("%d", lt + i), lt[i + n] = lt[i];
    for (int i = 1; i < m; i++)
        rt[i] = lt[i + 1];

    for (int l = 1; l < n; l++)
        for (int i = 1, j = i + l; j <= m; i++, j++)
            for (int k = i; k < j; k++) {
                dp[i][j] = std::max(dp[i][j], dp[i][k] + dp[k + 1][j] + lt[i] * rt[k] * rt[j]);
                ans = std::max(ans, dp[i][j]);
            }
    printf("%d\n", ans);
    return 0;
}
/*
2
1 1
4 2 3 5 10
*/
