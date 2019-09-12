/*
 *  https://codeforc.es/problemset/problem/750/E
 *
 */
#include <bits/stdc++.h>
//#include <stdio.h>
//#include <algorithm>

#define  _debug(x) cerr<<#x<<" = "<<x<<endl
using namespace std;
typedef long long ll;
const int MAXN = 1e2 + 59;
const int MAXM = 2e6 + 59;
const ll MOD = 998244353;
const ll INF = 1e6;

int n, s, sizn;
int ps, pu;
int nm[1 << 10 | 1];
int dp[55][1 << 10];
int ans;
int a[MAXN];
int psa[MAXN];
int pua[MAXN];
int sum;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> s;
    sizn = 2 * n * (s + 1);
    for (int i = 1; i <= sizn; ++i) cin >> a[i];

    cin >> ps;
    for (int i = 1; i <= ps; ++i)cin >> psa[i], sum += psa[i];
    sort(psa + 1, psa + 1 + n, greater<int>());

    cin >> pu;
    for (int i = 1; i <= pu; ++i)cin >> pua[i], sum += pua[i];
    sort(pua + 1, pua + 1 + n, greater<int>());

    int states = 1 << (2 * n);

    for (int i = 1; i < states; i++)
        nm[i] = nm[i >> 1] + (i & 1);

    for (int i = 0; i < states; ++i) {
        dp[0][i] = -1e9;
    }

    for (int i = 1, m; i <= sizn; ++i) {
        m = 1 << (a[i] - 1);
        _debug(i);
        for (int s = 0; s < states; ++s) {
            _debug(bitset<2>(s));

            if (m & s) {
                if (a[i] <= n)
                    dp[i][s] = max(dp[i - 1][s ^ m] + pua[nm[s ^ m]],
                                   dp[i - 1][s] + psa[i - nm[s]]);
                else
                    dp[i][s] = min(dp[i - 1][s ^ m] - pua[nm[s ^ m]],
                                   dp[i - 1][s] - psa[i - nm[s]]);

            } else {
                if (a[i] <= n)dp[i][s] = dp[i - 1][s] + psa[i - nm[s]];
                else dp[i][s] = dp[i - 1][s] - psa[i - nm[s]];
            }
        }
        _debug(dp[i][s]);
    }
    ans = dp[n][states - 1];
    cout << ans << endl;

    return 0;
}

/*


 */
