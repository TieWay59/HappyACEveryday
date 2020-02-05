/**
  *    █████╗  ██████╗       ██████╗ ██╗     ███████╗
  *   ██╔══██╗██╔════╝       ██╔══██╗██║     ╚══███╔╝
  *   ███████║██║            ██████╔╝██║       ███╔╝
  *   ██╔══██║██║            ██╔═══╝ ██║      ███╔╝
  *   ██║  ██║╚██████╗▄█╗    ██║     ███████╗███████╗
  *   ╚═╝  ╚═╝ ╚═════╝╚═╝    ╚═╝     ╚══════╝╚══════╝
  *
  *  @Author: TieWay59
  *  @Created: 2020/2/4 13:36
  *  @Link: https://vjudge.net/contest/355151?tdsourcetag=s_pctim_aiomsg#problem/H
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
const ll INF = 0x3F3F3F3F3F3F3F3F;
const ll llINF = 0x3F3F3F3F3F3F3F3F;
using namespace std;

using cost_t = long long;   //beware of integer overflow
using node_t = int;
using edge_t = pair<node_t, cost_t>;
using pqnd_t = pair<cost_t, node_t>;

vector<vector<edge_t>> adj;
vector<cost_t> tag;

void dijkstra(int s, vector<cost_t> &d) {
    int n = adj.size();
    d.assign(n, INF);   // distance

    d[s] = 0;
    priority_queue<pqnd_t, vector<pqnd_t>, greater<pqnd_t>> q;
    q.emplace(0, s);

    node_t u, v;
    cost_t dis, len;
    while (!q.empty()) {
        dis = q.top().first;
        u = q.top().second;
        q.pop();
        if (dis > d[u]) // i.e. !=
            continue;

        for (auto edge : adj[u]) {
            v = edge.first;
            len = edge.second;
            if (d[u] + len + tag[v] < d[v]) {
                d[v] = d[u] + len + tag[v];
                q.emplace(d[v], v);
            }
        }
    }
}

void solve(int kaseId = -1) {
    ll n, m, k;
    cin >> n >> m >> k;
    adj.assign(n + 1, {});
    tag.assign(n + 1, 0);

    for (ll i = 1, u, v, w; i <= m; ++i) {
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    for (ll i = 1; i <= n; ++i) {
        cin >> tag[i];
    }

    for (ll j = 1, u; j <= k; ++j) {
        cin >> u;
        adj[0].emplace_back(u, 0);
        adj[u].emplace_back(0, 0);
    }

    vector<cost_t> dist;
    dijkstra(0, dist);
    for (ll i = 1; i <= n; ++i) {
        cout << dist[i] << endl;
    }
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