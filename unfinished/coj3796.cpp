

/*
 * https://www.cometoj.com/contest/67/problem/B?problem_id=3796
 *
 */
#include <bits/stdc++.h>

#define  _debug(x) cerr<<#x << " = " << x<<endl
using namespace std;

typedef long long ll;
const int MOD = -1;
const double eps = 1e-3;
const int INF = 0x3f3f3f3f;
const int MAXN = 4e4 + 59;
//const ll INF = 0x3f3f3f3f3f3f3f;

int kase;
int n, m, k;

ll ans;
ll f[MAXN];
ll a[MAXN], b[MAXN];
ll dp[105][MAXN];
ll bg[MAXN];
ll lf[MAXN];
int flag;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    cin >> n >> m >> k;

    for (int i = 0; i <= k; ++i) {
        cin >> f[i];
    }


    for (int i = 1; i <= m; ++i) {
        cin >> a[i] >> b[i];
        //b[i] += a[i];
    }

    for (int x = 0; x < MAXN; ++x)
        bg[x] = 0, lf[x] = x;

    for (int j = 1; j <= m; ++j) {
        for (int x = a[j]; x < MAXN; ++x) {
            if (bg[x] < bg[x - a[j]] + b[j]) {
                bg[x] = bg[x - a[j]] + b[j];
                lf[x] = lf[x - a[j]];
            }
        }
    }

    for (int i = 0; i <= n + 5; ++i)
        for (int x = 0; x < MAXN; ++x)
            dp[i][x] = -INF;

    dp[0][0] = 0;

    for (int i = 0; i <= n; ++i) {
        for (int x = 0; x < MAXN; ++x) {
            if (dp[i][x] < 0)continue;

            dp[i + 1][lf[x] + f[lf[x]]] =
                    max(dp[i + 1][lf[x] + f[lf[x]]],
                        dp[i][x] + bg[x]);
        }
    }

    for (int l = 0; l < MAXN; ++l) {
        ans = max(ans, dp[n][l] + l);
    }
    cout << ans << endl;
    return 0;
}
