#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>

const int MAXN = 10005;
const int INF = 0x3f3f3f3f;

struct qnode {
    int v, c;

    qnode(int _v = 0, int _c = 0) : v(_v), c(_c) {}

    bool operator<(const qnode &r) const {
        return c > r.c;
    }
};

std::vector <qnode> E[MAXN];
bool vis[MAXN];
int dist[MAXN];

void Dijkstra(int st) {
    memset(vis, false, sizeof vis);
    memset(dist, INF, sizeof dist);
    std::priority_queue <qnode> que;
    while (!que.empty())que.pop();
    dist[st] = 0;
    que.push(qnode(st, 0));
    qnode tmp;
    while (!que.empty()) {
        tmp = que.top();
        que.pop();
        int u = tmp.v;
        if (vis[u])continue;
        vis[u] = true;
        for (qnode e:E[u]) {
            if (!vis[e.v] && dist[e.v] > dist[u] + e.c) {
                dist[e.v] = dist[u] + e.c;
                que.push(qnode(e.v, dist[e.v]));
            }
        }
    }
}

void AddEdge(int u, int v, int w) {
    E[u].push_back(qnode(v, w));
    E[v].push_back(qnode(u, w));
}

int main() {
    int t, s, d;
    while (scanf("%d%d%d", &t, &s, &d) != EOF) {
        for (int u, v, w, i = 1; i <= t; i++) {
            scanf("%d%d%d", &u, &v, &w);
            AddEdge(u, v, w);
        }
        for (int v, i = 1; i <= s; i++) {
            scanf("%d", &v);
            AddEdge(0, v, 0);
        }
        Dijkstra(0);
        int ans = INF;
        for (int i = 1, x; i <= d; i++)
            scanf("%d", &x), ans = std::min(ans, dist[x]);
        printf("%d\n", ans);
        for (int i = 0; i <= 1000; i++)
            E[i].clear();
    }
    return 0;
}
/*

*/
