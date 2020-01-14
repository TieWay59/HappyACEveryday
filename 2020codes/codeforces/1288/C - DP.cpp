/**
  *    █████╗  ██████╗       ██████╗ ██╗     ███████╗
  *   ██╔══██╗██╔════╝       ██╔══██╗██║     ╚══███╔╝
  *   ███████║██║            ██████╔╝██║       ███╔╝
  *   ██╔══██║██║            ██╔═══╝ ██║      ███╔╝
  *   ██║  ██║╚██████╗▄█╗    ██║     ███████╗███████╗
  *   ╚═╝  ╚═╝ ╚═════╝╚═╝    ╚═╝     ╚══════╝╚══════╝
  *
  *  @Author: TieWay59
  *  @Created: 2020/1/14 22:58
  *  @Link: http://m2.codeforces.com/contest/1288/problem/C
  *  @Tags:
  *
  *******************************************************/

#include <bits/stdc++.h>

#ifdef DEBUG

#   include "libs59/debugers.h"
//  #define debug(x)  cerr <<#x << " = "<<x<<endl;
#else
#   define endl '\n'
#   define debug(x)  59
#endif

#define STOPSYNC ios::sync_with_stdio(false);cin.tie(nullptr)
#define MULTIKASE int Kase=0;cin>>Kase;for(int kase=1;kase<=Kase;kase++)
typedef long long ll;
const int MAXN = 2e3 + 59;
const int MOD = 1e9 + 7;
const int INF = 0x3F3F3F3F;
const ll llINF = 0x3F3F3F3F3F3F3F3F;
using namespace std;

ll dp[MAXN][MAXN];

void solve(int kaseId = -1) {
    int n, m;
    cin >> n >> m;

    dp[0][1] = 1;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= j; ++k) {
                dp[i][j] = (dp[i][j] + dp[i - 1][k] % MOD) % MOD;
            }
        }
    }

    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n - i + 1; ++j) {
            ans = (ans + dp[m][i] * dp[m][j] % MOD) % MOD;
        }
    }
    cout << ans << endl;
}

void solves() {
    MULTIKASE {
        solve(kase);
    }
}

int main() {
    STOPSYNC;
    solve();
    return 0;
}
/*

 */

