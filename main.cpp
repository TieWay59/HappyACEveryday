/*
*  https://codeforc.es/contest/1220/problem/D?csrf_token=a6aa4329bb73ab3e1847c9e973e7af85
*/
//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <tuple>

#define  _debug(x) cerr<<#x<<" = "<<x<<endl
using namespace std;
typedef long long ll;
typedef long long lll;
const int MAXN = 3e5 + 59;
const int MAXM = 2e5 + 59;
const ll MOD = 998244353;
const ll INF = 2e18 + 59;


int kase;
int n;
ll dp[MAXN][3];
ll a[MAXN];
ll b[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> kase;
    while (kase--) {
        memset(dp, 0, sizeof dp);
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i] >> b[i];
        }

//        dp[0][0] = dp[0][1] = dp[0][2] = INF;
        dp[1][1] = b[1];
        dp[1][2] = b[1] + b[1];

        for (ll i = 2; i <= n; ++i) {
            dp[i][0] = dp[i][1] = dp[i][2] = INF;

            for (ll j1 = 0; j1 < ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++3; ++j1) {
                for (ll j2 = 0; j2 < 3; ++j2) {

                    if (a[i - 1] + j2 != a[i] + j1) {
                        dp[i][j1] = min(dp[i][j1],
                                        dp[i - 1][j2]
                                        + j1 * b[i]);
                    }

                }
            }
        }
        ll ans = INF;
        ans = min(ans, dp[n][0]);
        ans = min(ans, dp[n][1]);
        ans = min(ans, dp[n][2]);
        cout << ans << endl;
    }


    return 0;
}

