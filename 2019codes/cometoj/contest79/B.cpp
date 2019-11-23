/**
  *    █████╗  ██████╗       ██████╗ ██╗     ███████╗
  *   ██╔══██╗██╔════╝       ██╔══██╗██║     ╚══███╔╝
  *   ███████║██║            ██████╔╝██║       ███╔╝
  *   ██╔══██║██║            ██╔═══╝ ██║      ███╔╝
  *   ██║  ██║╚██████╗▄█╗    ██║     ███████╗███████╗
  *   ╚═╝  ╚═╝ ╚═════╝╚═╝    ╚═╝     ╚══════╝╚══════╝
  *
  *  @Author: TieWay59
  *  @Created: 2019/11/23 19:13
  *  @Link: https://www.cometoj.com/contest/79/problem/B?problem_id=4199
  *  @Tags:
  *
  *******************************************************/


#include <bits/stdc++.h>

#ifdef DEBUG
//#define debug(x)  cerr <<#x << " = "<<x<<endl;
#include "libs59/debugers.h"

#else
#define endl '\n'
#define debug(x)  59
#endif

#define STOPSYNC ios::sync_with_stdio(false);cin.tie(nullptr)
#define MULTIKASE int Kase=0;cin>>Kase;for(int kase=1;kase<=Kase;kase++)
typedef long long ll;
const int MAXN = 2e3 + 59;
const int MOD = 1e9 + 7;
const int INF = 0x3F3F3F3F;
const ll llINF = 0x3F3F3F3F3F3F3F3F;
using namespace std;

int n;

struct node {
    ll x, y;

    ll sqdis_to(const node &rht) {
        return (x - rht.x) * (x - rht.x) + (y - rht.y) * (y - rht.y);
    }
} a[MAXN];

ll sqdis[MAXN][MAXN];

void solve(int kaseId = -1) {
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i].x >> a[i].y;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            sqdis[j][i] = sqdis[i][j] = a[i].sqdis_to(a[j]);
        }
    }

    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        map<ll, ll> mp;
        for (int j = 1; j <= n; ++j) {
            if (j == i)continue;
            ll tmp = mp[sqdis[i][j]]++;
            ans += tmp * (tmp - 1) / 2;
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