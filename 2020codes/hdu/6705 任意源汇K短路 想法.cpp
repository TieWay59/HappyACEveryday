/**
  *    █████╗  ██████╗       ██████╗ ██╗     ███████╗
  *   ██╔══██╗██╔════╝       ██╔══██╗██║     ╚══███╔╝
  *   ███████║██║            ██████╔╝██║       ███╔╝
  *   ██╔══██║██║            ██╔═══╝ ██║      ███╔╝
  *   ██║  ██║╚██████╗▄█╗    ██║     ███████╗███████╗
  *   ╚═╝  ╚═╝ ╚═════╝╚═╝    ╚═╝     ╚══════╝╚══════╝
  *
  *  @Author: TieWay59
  *  @Created: 2020/4/2 22:14
  *  @Link: http://acm.hdu.edu.cn/showproblem.php?pid=6705
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
#   define max(x,y) ((x)>(y)?(x):(y))
#   define min(x,y) ((x)>(y)?(y):(x))
#   define assert(x)
#endif

#define STOPSYNC ios::sync_with_stdio(false);cin.tie(nullptr)
#define MULTIKASE int Kase=0;cin>>Kase;for(int kase=1;kase<=Kase;kase++)
typedef long long ll;
const int MAXN = 2e5 + 59;
const int MOD = 1e9 + 7;
const int INF = 0x3F3F3F3F;
const ll llINF = 0x3F3F3F3F3F3F3F3F;
using namespace std;
using pii = pair<int, int>;
using vint = vector<int>;

void solve(int kaseId = -1) {
    struct pqnd {
        ll dis;
        int u, i;

        bool operator<(const pqnd &rht) const {
            return dis > rht.dis;
        }
    };


    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<pair<ll, int>>> a(n);

    for (int i = 1, u, v, w; i <= m; ++i) {
        cin >> u >> v >> w;
        u--, v--;
        a[u].emplace_back(w, v);
    }

    for (auto &ai:a) {
        sort(ai.begin(), ai.end());
    }

    priority_queue<pqnd> que;
    vector<ll> ans;

    for (int u = 0; u < n; ++u) {
        if (a[u].size() > 0) {
            que.push({a[u][0].first, u, 0});
        }
    }

    auto update = [&]() {
        ll dis = que.top().dis;
        int u = que.top().u;
        int i = que.top().i;
        int v = a[u][i].second;
        que.pop();

        ans.emplace_back(dis);

        if (i + 1 < a[u].size()) {
            que.push({dis - a[u][i].first + a[u][i + 1].first,
                      u, i + 1});
        }
        if (a[v].size() > 0) {
            que.push({dis + a[v][0].first,
                      v, 0});
        }
    };

    ll k;
    for (int j = 1; j <= q; ++j) {
        cin >> k;
        k--;
        while (k >= ans.size() && !que.empty()) {
            update();
        }
        assert(k < ans.size());
        cout << ans[k] << endl;
    }
}

void solves() {
    MULTIKASE {
        solve(kase);
    }
}

int main() {
#ifdef DEBUG
    freopen("input.txt", "r+", stdin);
#endif
    STOPSYNC;
    solves();
    return 0;
}
/*

 */