/**
  *    █████╗  ██████╗       ██████╗ ██╗     ███████╗
  *   ██╔══██╗██╔════╝       ██╔══██╗██║     ╚══███╔╝
  *   ███████║██║            ██████╔╝██║       ███╔╝
  *   ██╔══██║██║            ██╔═══╝ ██║      ███╔╝
  *   ██║  ██║╚██████╗▄█╗    ██║     ███████╗███████╗
  *   ╚═╝  ╚═╝ ╚═════╝╚═╝    ╚═╝     ╚══════╝╚══════╝
  *
  *  @Author: TieWay59
  *  @Created: 2020/1/17 13:15
  *  @Link: https://pintia.cn/problem-sets/1217973933671833600/problems/1217974362208067597
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

ll n;
ll a[MAXN];
ll dp[MAXN][MAXN];
ll sm[MAXN][MAXN];

void solve(int kaseId = -1) {

    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sm[i][i] = a[i];
    }

    for (int i = 2; i <= n; ++i) {
        for (int l = 1, r = l + i - 1; r <= n; ++l, ++r) {
            sm[l][r] = sm[l][r - 1] + a[r];
            dp[l][r] = max(dp[l][r - 1] + sm[l][r - 1] * a[r],
                           dp[l + 1][r] + sm[l + 1][r] * a[l]);

        }
    }
    cout << dp[1][n] << endl;
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