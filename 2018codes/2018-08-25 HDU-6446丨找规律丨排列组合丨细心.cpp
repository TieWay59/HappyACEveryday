/*http://acm.hdu.edu.cn/showproblem.php?pid=6446
??????е??????????????Щ????x

*/
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int mod = 1e9 + 7;
const int N = 1e5 + 5;
typedef long long ll;
ll sum[N], ans;
int head[N], cnted, n;
bool vis[N];
struct Edge {
    int nx, v;
    ll w;
} ed[N + N];

void AddEd(int u, int v, int w) {
    ed[++cnted] = {head[u], v, (ll) w};
    head[u] = cnted;
}

void dfs(int u) {
    vis[u] = true;
    sum[u] = 1ll;
    for (int v, i = head[u]; ~i; i = ed[i].nx) {
        v = ed[i].v;
        if (vis[v])continue;
        dfs(v);
        sum[u] = (sum[u] + sum[v]) % mod;
        ans += 1ll * sum[v] * (n - sum[v]) % mod * ed[i].w % mod;
    }
}

int main() {
    while (scanf("%d", &n) != EOF) {
        memset(head, -1, sizeof head);
        memset(vis, false, sizeof vis);
        ans = 0;
        cnted = 0;
        for (int i = 1, u, v, w; i < n; i++) {
            scanf("%d%d%d", &u, &v, &w);
            AddEd(u, v, w);
            AddEd(v, u, w);
        }
        dfs(1);
        for (ll i = 1; i < n; i++)
            ans = ans * i % mod;
        ans = ans * 2ll % mod;
        printf("%lld\n", ans);
    }
    return 0;
}
/*
*/
