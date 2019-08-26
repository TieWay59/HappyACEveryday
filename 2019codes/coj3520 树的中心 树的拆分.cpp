/*
 *  https://www.cometoj.com/contest/64/problem/C?problem_id=3520
 *
 */
#include <bits/stdc++.h>
//#include <stdio.h>
//#include <algorithm>

#define  _debug(x) cerr<<#x<<" = "<<x<<endl
using namespace std;
typedef long long ll;
const int MAXN = 1e6 + 59;
const int MAXM = 2e6 + 59;
const ll MOD = 998244353;
const ll INF = 0x3f3f3f3f;

struct Edge {
    int nx, v;
} ed[MAXM];
int head[MAXN], cntEd;

void addEdge(int u, int v) {
    ed[cntEd] = {head[u], v};
    head[u] = cntEd++;
}


void dfs(int u, int d, int dis[]) {
    dis[u] = d;
    for (int i = head[u], v; ~i; i = ed[i].nx) {
        if (dis[ed[i].v] == -1)
            dfs(ed[i].v, d + 1, dis);
    }
}

int disu[MAXN];
int disv[MAXN];

int getCenter(int n) {
    int u = 0, v = 0, d = 0;

    memset(disu, -1, sizeof disu);
    dfs(1, 0, disu);
    for (int i = 1; i <= n; i++)
        if (disu[i] > disu[u])
            u = i;

    memset(disu, -1, sizeof disu);
    dfs(u, 0, disu);
    for (int i = 1; i <= n; i++)
        if (disu[i] > disu[v])
            v = i;

    memset(disv, -1, sizeof disv);
    dfs(v, 0, disv);

    d = disu[v] / 2;
//    _debug(d);
//    _debug(disu[v]);
//    _debug(disv[u]);

    for (int i = 1; i <= n; i++)
        if (disu[i] == d && disv[i] == (disu[v] - d))
            return i;
        else if (disv[i] == d && disu[i] == (disu[v] - d))
            return i;
    return -1;
}

int height[MAXN];

int dfs(int u, int f) {
    for (int i = head[u], v; ~i; i = ed[i].nx)
        if (ed[i].v != f)
            height[u] = max(dfs(ed[i].v, u), height[u]);
    return ++height[u];
}

int n, k, ans;
bool vis[MAXN];
priority_queue<pair<int, int> > que;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    fill(head, head + n + 9, -1);

    memset(head, -1, sizeof head);

    cin >> n >> k;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }

    int start = getCenter(n);
    dfs(start, -1);
//    _debug(start);
    que.emplace(height[start], start);
    while (k--) {
        int u = que.top().second;
//        _debug(u);
//        _debug(height[u]);
        que.pop();

        vis[u] = true;
        for (int i = head[u]; ~i; i = ed[i].nx)
            if (!vis[ed[i].v])
                que.emplace(height[ed[i].v], ed[i].v);
    }

    for (int i = 1; i <= n; i++)
        if (!vis[i])
            ans = max(ans, height[i]);
    cout << ans << endl;
    return 0;
}

/*

4
2 2 1 2


 */
