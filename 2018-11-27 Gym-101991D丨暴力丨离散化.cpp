#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 1e3 + 5;
const int INF = 0x3f3f3f3f;
int T, n, m, k;
int x[MAXN], y[MAXN], xx[MAXN], yy[MAXN];
bool sum[MAXN][MAXN];

int main() {
    freopen("dull.in", "r", stdin);
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 0; i < k; i++) {
            scanf("%d%d", x + i, y + i);
            xx[i] = x[i];
            yy[i] = y[i];
        }
        sort(xx, xx + k);
        sort(yy, yy + k);
        int nn = unique(xx, xx + k) - xx;
        int mm = unique(yy, yy + k) - yy;
        xx[nn] = n + 1;
        yy[mm] = m + 1;

        for (int i = 0; i < nn; i++)
            for (int j = 0; j < mm; j++)
                sum[i][j] = false;

        for (int i = 0, ix, iy; i < k; i++) {
            ix = lower_bound(xx, xx + nn, x[i]) - xx;
            iy = lower_bound(yy, yy + mm, y[i]) - yy;
            sum[ix][iy] ^= 1;
        }

        for (int i = 0; i < nn; i++)
            for (int j = 1; j < mm; j++)
                sum[i][j] ^= sum[i][j - 1];
        for (int i = 1; i < nn; i++)
            for (int j = 0; j < mm; j++)
                sum[i][j] ^= sum[i - 1][j];

        ll ans = 0;
        for (int i = 0; i < nn; i++)
            for (int j = 0; j < mm; j++)
                if (sum[i][j])
                    ans += (xx[i + 1] - xx[i]) * 1ll * (yy[j + 1] - yy[j]);
        printf("%lld %lld\n", ans, 1ll * n * m - ans);
    }

    return 0;
}
/*
3
3 3 0
3 3 1
2 2
5 5 5
1 5
2 1
3 3
4 2
5 4
*/
