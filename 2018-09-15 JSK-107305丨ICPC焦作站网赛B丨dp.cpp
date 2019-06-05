#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

ll calc(ll x, char op, ll y) {
    switch (op) {
        case '+':
            return x + y;
        case '-':
            return x - y;
        case '*':
            return x * y;
        case '/':
            return x / y;
    }
}

int T, n, m;
ll k;
ll a[1005], dp[1005][6], pd[1005][6];
char f[15];

int main() {

    scanf("%d", &T);
    while (T--) {
        memset(dp, 0x80, sizeof(dp));
        memset(pd, 0x3f, sizeof(pd));
        scanf("%d %d %lld", &n, &m, &k);
        for (int i = 1; i <= n; i++)
            scanf("%lld", a + i);
        scanf("%s", f + 1);

        for (int i = 0; i <= n; i++)
            pd[i][0] = dp[i][0] = k;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                if (i <= m && j > i)break;
                dp[i][j] = max(dp[i - 1][j], calc(dp[i - 1][j - 1], f[j], a[i]));
                pd[i][j] = min(pd[i - 1][j], calc(pd[i - 1][j - 1], f[j], a[i]));
                dp[i][j] = max(dp[i][j], calc(pd[i - 1][j - 1], f[j], a[i]));
                pd[i][j] = min(pd[i][j], calc(dp[i - 1][j - 1], f[j], a[i]));
            }

        printf("%lld\n", dp[n][m]);
    }
    return 0;
}

/*
5
5 5 6
-1 -1 -1 -1 -1
-----
2 1 5
2 3
/
3 2 1
1 2 3
++
4 4 5
1 2 3 4
+-*/





