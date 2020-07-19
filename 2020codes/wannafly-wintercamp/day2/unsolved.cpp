/**
  *    █████╗  ██████╗       ██████╗ ██╗     ███████╗
  *   ██╔══██╗██╔════╝       ██╔══██╗██║     ╚══███╔╝
  *   ███████║██║            ██████╔╝██║       ███╔╝
  *   ██╔══██║██║            ██╔═══╝ ██║      ███╔╝
  *   ██║  ██║╚██████╗▄█╗    ██║     ███████╗███████╗
  *   ╚═╝  ╚═╝ ╚═════╝╚═╝    ╚═╝     ╚══════╝╚══════╝
  *
  *  @Author: TieWay59
  *  @Created: 2020/1/13 16:49
  *  @Link: https://pintia.cn/problem-sets/1216577066538311680/problems/1216577133471023108
  *  @Tags: tree
  *
  *******************************************************/

#include <bits/stdc++.h>

#ifdef DEBUG

#   include "libs59/debugers.h"
//  #define debug(x)  cerr <<#x << " = "<<x<<endl;
#else
#   define endl '\n'
#   define debug(...)  59
#endif

#define STOPSYNC ios::sync_with_stdio(false);cin.tie(nullptr)
#define MULTIKASE int Kase=0;cin>>Kase;for(int kase=1;kase<=Kase;kase++)
const int MAXN = 1e5 + 59;
const int MOD = 1e9 + 7;
const int INF = 0x3F3F3F3F;
typedef long long ll;
const ll llINF = 0x3F3F3F3F3F3F3F3F;
using namespace std;
typedef set<int> sint;

vector<int> tree[MAXN];
set<int> a[MAXN];
bool vis[MAXN];
int siz[MAXN];
ll ans[MAXN];
int n;

void dfs(const int &u, const int &f) {
    int MaxId = u;
    vis[u] = true;

    for (const int &v:tree[u]) {
        if (v == f || vis[v])continue;
        dfs(v, u);
        siz[u] += siz[v];
        if (MaxId == u) MaxId = v;
        else if (siz[MaxId] < siz[v])MaxId = v;
    }

    debug(u, siz[u]);
    a[u].swap(a[MaxId]);
    ans[u] = ans[MaxId];

    for (const int &v:tree[u]) {
        if (v == f)continue;

        debug(a[u], ans[u]);

        while (!a[v].empty()) {

            debug(*a[u].rbegin());
            if (*a[u].begin() < *a[v].begin()) {

                set<int>::iterator it = a[u].upper_bound(*a[v].begin());
                ll val = *a[v].begin();

                if (it == a[u].end()) {
                    it--;
                    ans[u] += ((*it) - val) * ((*it) - val);
                } else {
                    ll sub2 = *it;
                    it--;
                    ll sub1 = *it;
                    ans[u] -= (sub2 - sub1) * (sub2 - sub1);
                    ans[u] += (val - sub1) * (val - sub1);
                    ans[u] += (sub2 - val) * (sub2 - val);
                }
            } else {
                ans[u] += (*a[u].begin() - *a[v].begin())
                          * (*a[u].begin() - *a[v].begin());
            }

            a[u].emplace(*a[v].begin());
            a[v].erase(a[v].begin());
            debug(a[u], ans[u]);
        }
    }
}

void solve(int kaseId = -1) {
    cin >> n;

    for (int v, u = 2; u <= n; ++u) {
        cin >> v;
        tree[u].emplace_back(v);
        tree[v].emplace_back(u);
    }

    //debug(n);

    for (int i = 1; i <= n; ++i) {
        a[i].emplace(i);
        siz[i] = 1;
    }

    dfs(1, 0);
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << endl;
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