/**
  *    █████╗  ██████╗       ██████╗ ██╗     ███████╗
  *   ██╔══██╗██╔════╝       ██╔══██╗██║     ╚══███╔╝
  *   ███████║██║            ██████╔╝██║       ███╔╝
  *   ██╔══██║██║            ██╔═══╝ ██║      ███╔╝
  *   ██║  ██║╚██████╗▄█╗    ██║     ███████╗███████╗
  *   ╚═╝  ╚═╝ ╚═════╝╚═╝    ╚═╝     ╚══════╝╚══════╝
  *
  *  @Author: TieWay59
  *  @Created: 2020/2/8 14:00
  *  @Link: https://vjudge.net/contest/355794?tdsourcetag=s_pctim_aiomsg#problem/C
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
const int MAXN = 4e3 + 59;
const int MOD = 1e9 + 7;
const int INF = 0x3F3F3F3F;
const ll llINF = 0x3F3F3F3F3F3F3F3F;
using namespace std;

ll fpow(ll a, ll b, ll mod = MOD) {
    ll ret = 1;
    while (b) {
        if (b & 1)ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}

int n;
int pre[MAXN][MAXN];
int has[MAXN][MAXN];
int x[MAXN];
int y[MAXN];
map<int, int> dsc;

void Dsc(int a[]) {
    dsc.clear();
    for (int i = 1; i <= n; ++i) {
        dsc.emplace(a[i], -1);
    }
    int cnt = 0;
    for (auto &di:dsc) {
        di.second = ++cnt;
    }
    for (int j = 1; j <= n; ++j) {
        a[j] = dsc[a[j]];
    }
}

void solve(int kaseId = -1) {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i];
    }
    Dsc(x);
    Dsc(y);

    for (int i = 1; i <= n; ++i) {
        has[x[i]][y[i]] = pre[x[i]][y[i]] = 1;
        debug(x[i], y[i]);
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            pre[i][j] += pre[i][j - 1];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            pre[i][j] += pre[i - 1][j];
        }
    }

    int ri, ci, rj, cj;
    int sum = 0, ans = 0;
    for (int i = 1; i <= n; ++i) {
        tie(ri, ci) = tie(x[i], y[i]);
        for (int j = 1; j <= n; ++j) {
            if (i == j)continue;
            tie(rj, cj) = tie(x[j], y[j]);
            if (ri >= rj || ci >= cj)continue;
            if (!has[ri][cj])continue;
            if (!has[rj][ci])continue;

            sum = pre[rj][cj] - pre[rj][ci - 1] - pre[ri - 1][cj] + pre[ri - 1][ci - 1];
            if (sum != 4)continue;
            ans++;
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
