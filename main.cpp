/**
  *    █████╗  ██████╗       ██████╗ ██╗     ███████╗
  *   ██╔══██╗██╔════╝       ██╔══██╗██║     ╚══███╔╝
  *   ███████║██║            ██████╔╝██║       ███╔╝
  *   ██╔══██║██║            ██╔═══╝ ██║      ███╔╝
  *   ██║  ██║╚██████╗▄█╗    ██║     ███████╗███████╗
  *   ╚═╝  ╚═╝ ╚═════╝╚═╝    ╚═╝     ╚══════╝╚══════╝
  *
  *  @Author: TieWay59
  *  @Created: 2020/1/14 16:54
  *  @Link: https://pintia.cn/problem-sets/1216926916261912576/problems/1216927073175027718
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
const int MAXN = 5e5 + 59;
const int MOD = 1e9 + 7;
const int INF = 0x3F3F3F3F;
const ll llINF = 0x3F3F3F3F3F3F3F3F;
using namespace std;

struct Edge {
    int v, w, nx;
} e[MAXN << 1];
int head[MAXN], cntEd;
bool tag[MAXN];
bool hasTags[MAXN];
int
bool vis[MAXN];

inline void addEdge(int u, int v, int w) {
    e[cntEd] = {v, w, head[u]};
    head[u] = cntEd++;
}

// find the sub-tree
// calc sub-tree ans
// tag the outs
void dfs(const int &u,
         int &subTreeSum,
         const int &pathLength) {

    vis[u] = true;

    for (int i = head[u], v, w; ~i; i = e[i].nx) {
        v = e[i].v;
        w = e[i].w;
        if (vis[v])continue;

        dfs(v, subTreeSum, pathLength + w);

        if (hasTags[v]) {
            hasTags[u] = true;
            subTreeSum += w;
        }
    }
}

void solve(int kaseId = -1) {

    int n, k;
    cin >> n >> k;

    // initiate:
    memset(head, -1, sizeof head);
    cntEd = 0;

    // build graph:
    for (int i = 1, u, v, w; i < n; ++i) {
        cin >> u >> v >> w;
        addEdge(u, v, w);
        addEdge(v, u, w);
    }

    int start;
    for (int i = 1, u; i <= k; ++i) {
        cin >> u;
        hasTags[u] = tag[u] = true;
        start = u;
    }

    int sbs = 0;
    dfs(start, sbs);
    debug(sbs);
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