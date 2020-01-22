/**
  *    █████╗  ██████╗       ██████╗ ██╗     ███████╗
  *   ██╔══██╗██╔════╝       ██╔══██╗██║     ╚══███╔╝
  *   ███████║██║            ██████╔╝██║       ███╔╝
  *   ██╔══██║██║            ██╔═══╝ ██║      ███╔╝
  *   ██║  ██║╚██████╗▄█╗    ██║     ███████╗███████╗
  *   ╚═╝  ╚═╝ ╚═════╝╚═╝    ╚═╝     ╚══════╝╚══════╝
  *
  *  @Author: TieWay59
  *  @Created: 2020/1/23 0:17
  *  @Link: http://m3.codeforces.com/contest/1294/problem/E
  *  @Tags:
  *
  *******************************************************/

#include <bits/stdc++.h>

#ifdef DEBUG

#   include "libs59/debugers.h"
//  #define debug(x)  cerr <<#x << " = "<<x<<endl;
#else
#   define endl '\n'
#   define debug(...)
#endif

#define STOPSYNC ios::sync_with_stdio(false);cin.tie(nullptr)
#define MULTIKASE int Kase=0;cin>>Kase;for(int kase=1;kase<=Kase;kase++)
typedef long long ll;
const int MAXN = 2e5 + 59;
const int MOD = 1e9 + 7;
const int INF = 0x3F3F3F3F;
const ll llINF = 0x3F3F3F3F3F3F3F3F;
using namespace std;

void solve(int kaseId = -1) {
    ll n, m, ans = 0;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));

    vector<int> cnt;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    for (int j = 0; j < m; ++j) {
        cnt = vector<int>(n + 5);
        for (int i = 0, k; i < n; ++i) {
            a[i][j]--;

            if (a[i][j] >= n * m)continue;
            if (a[i][j] % m != j)continue;

            debug(i, j);

            k = a[i][j] / m;
            if (i < k) {
                cnt[n + i - k]++;
            } else {
                cnt[i - k]++;
            }
        }

        debug(cnt);
        ll tmp = INF;
        for (int i = 0; i < n; ++i) {
            tmp = min(tmp, i + n - cnt[i]);
        }

        ans += tmp;
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