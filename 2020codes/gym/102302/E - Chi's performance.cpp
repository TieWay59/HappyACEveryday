/**
  *    █████╗  ██████╗       ██████╗ ██╗     ███████╗
  *   ██╔══██╗██╔════╝       ██╔══██╗██║     ╚══███╔╝
  *   ███████║██║            ██████╔╝██║       ███╔╝
  *   ██╔══██║██║            ██╔═══╝ ██║      ███╔╝
  *   ██║  ██║╚██████╗▄█╗    ██║     ███████╗███████╗
  *   ╚═╝  ╚═╝ ╚═════╝╚═╝    ╚═╝     ╚══════╝╚══════╝
  *
  *  @Author: TieWay59
  *  @Created: 2020/2/8 15:28
  *  @Link: https://vjudge.net/contest/355794?tdsourcetag=s_pctim_aiomsg#problem/E
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
using PII = pair<ll, ll>;

void solve(int kaseId = -1) {
    int n;
    cin >> n;
    vector<PII> a(n);
    vector<vector<ll>> dp(n + 5, vector<ll>(6, 0));
    vector<vector<PII>> st(n + 5, vector<PII>(6));

    for (auto &ai:a) {
        cin >> ai.first >> ai.second;
    }
    sort(a.begin(), a.end());

    int id = 0;
    ll mn1, mn2, mx2, mx1;
    a.emplace_back(llINF, llINF);

    for (int l = 0, r = 0; r < a.size(); ++r) {
        if (a[r].first == a[l].first)continue;

        int len = r - l;

        if (len == 1) {
            int p = a[l].second;
            mn1 = mn2 = mx2 = mx1 = p;
        } else {
            mn1 = a[l + 0].second;
            mn2 = a[l + 1].second;
            mx2 = a[r - 2].second;
            mx1 = a[r - 1].second;
        }
        st[++id] = {
                {mn1, mx1},
                {mx1, mn1},
                {mx1, mx2},
                {mx2, mx1},
                {mn1, mn2},
                {mn2, mn1}
        };
        l = r;
    }

    debug(a);

    for (int i = 2; i <= id; ++i) {
        for (int j = 0; j < 6; ++j) {
            for (int k = 0; k < 6; ++k) {
                if (dp[i][j] < dp[i - 1][k] + abs(st[i - 1][k].second - st[i][j].first)) {
                    dp[i][j] = dp[i - 1][k] + abs(st[i - 1][k].second - st[i][j].first);
                }
            }
        }
    }
    ll ans = -llINF;

    /*for (int i = 1; i <= id; ++i) {
        debug(i);
        debug(st[i]);
        debug(dp[i]);
    }*/
    for (int i = 0; i < 6; ++i) {
        ans = max(ans, dp[id][i]);
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