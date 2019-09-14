/*
*  https://nanti.jisuanke.com/t/41402
*
*/
//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <tuple>

#define  _debug(x) cerr<<#x<<" = "<<x<<endl
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 59;
const int MAXM = 2e5 + 59;
const ll MOD = 998244353;
const ll INF = 0x0f0f0f0f;

int fa[MAXN];
int sz[MAXN];

int findf(int x) {
    if (x == fa[x])return x;
    else {
        sz[fa[x]] += sz[x];
        sz[x] = 0;
        return fa[x] = findf(fa[x]);
    }
}

void mergf(int x, int y) {
    int fx = findf(x);
    int fy = findf(y);
    if (fx == fy)return;
    if (sz[fx] <= sz[fy]) {
        sz[fx] += sz[fy];
        sz[fy] = 0;
        fa[fy] = fx;
    } else {
        sz[fy] += sz[fx];
        sz[fx] = 0;
        fa[fx] = fy;
    }
}


int Kase;
int n, m, k;
pair<int, int> e[MAXM];
int a[MAXN];
bool tag[MAXN];
bool vis[MAXN];
vector<int> g[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> Kase;
    while (Kase--) {
        cin >> n >> m >> k;
        for (int i = 1; i <= n; ++i) {
            fa[i] = i;
            sz[i] = 1;
            tag[i] = false;
            vis[i] = false;
            g[i].clear();
        }
        for (int i = 1; i <= m; ++i) {
            cin >> e[i].first >> e[i].second;
        }
        for (int i = 1; i <= k; ++i) {
            cin >> a[i];
            tag[a[i]] = true;
            sz[a[i]] = 0;
        }
        for (int i = 1; i <= m; ++i) {
            if (tag[e[i].first] == 0 && tag[e[i].second] == 0) {
                mergf(e[i].first, e[i].second);
            }
        }
        for (int u, v, i = 1; i <= m; ++i) {
            tie(u, v) = e[i];

            v = findf(v);
            u = findf(u);

            if (tag[u] || tag[v]) {
                g[u].emplace_back(v);
                g[v].emplace_back(u);
            }
        }

        int start = findf(1);
        double ans = sz[start];
        double tmp = 0;

        for (auto u:g[start]) {
            if (vis[u])continue;
            else vis[u] = true;

            double sum = 0;
            for (auto v:g[u])if (v != start)sum += sz[v];
            sum /= 1.0 * g[u].size();

            if (sum > tmp) tmp = sum;
        }
        ans += tmp;
        printf("%.6f\n", ans);
    }

    return 0;
}