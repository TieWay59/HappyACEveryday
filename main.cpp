#include <bits/stdc++.h>

#define  debug(x)  cerr <<#x << " = "<<x<<endl
const int MAXN = 1e5 + 59;
const int MOD = 1e9 + 7;
using namespace std;
typedef long long ll;

vector<int> e[MAXN];
bool vis[MAXN];
int stk[MAXN << 1], top;
int fa[MAXN];
int sz[MAXN];

set<int> rest;

int getf(int x) {
    if (x == fa[x])return x;
    else {
        sz[fa[x]] += sz[x];
        sz[x] = 0;
        return fa[x] = getf(fa[x]);
    }
}

void unif(int x, int y) {
    int fx = getf(x);
    int fy = getf(y);
    if (fx != fy) {
        fa[fy] = fx;
        sz[fx] += sz[fy];
        sz[fy] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    for (int u, v, i = 0; i < m; i++) {
        cin >> u >> v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }

    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
        sz[i] = 1;
        stk[++top] = i;
        rest.insert(i);

    }
//    int ans = 0;
    sort(stk + 1, stk + top + 1, [](int x, int y) {
        return e[x].size() < e[y].size();
    });

    queue<int> waitToDelete;
    while (top) {
        int u = stk[top--];
        if (vis[u])continue;
        vis[u] = true;
//        if (getf(u) == u) {
//            ans++;
//        }
        for (auto v:rest) {
            if (getf(v) == getf(u))continue;
            if (sz[getf(v)] != 1)continue;

            int cnt = 0;
            for (auto vv:e[v]) {
                if (getf(vv) == getf(u)) {
                    cnt++;
                }
            }

            if (cnt < sz[getf(u)]) {
                unif(u, v);
                waitToDelete.emplace(v);
            }
        }

        while (!waitToDelete.empty()) {
            if (rest.count(waitToDelete.front())) {
                rest.erase(waitToDelete.front());
            }
            stk[++top] = waitToDelete.front();
            waitToDelete.pop();
        }
        if (sz[u] > 0) {
            if (rest.count(u) > 0)
                rest.erase(u);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (sz[i] > 0)ans++;
//        debug(i);
//        debug(sz[i]);
//        cerr << endl;
    }
    cout << ans - 1 << endl;
    return 0;
}
/*
2
2 0
-50000 50000

4 0
-50000 -40000 40000 50000

 */