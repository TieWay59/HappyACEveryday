/*
https://nanti.jisuanke.com/t/31001
*/
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<queue>

using namespace std;
typedef long long ll;
const int N = 1500005;
const int M = 3000500;
const ll INF = 0x7f7f7f7f;
int n, m, k, T;
int head[N], ent;
struct Edge {
    int v, nx, w;
} ed[M << 1];

void AddEd(int u, int v, int w) {
    ed[++ent] = {v, head[u], w};
    head[u] = ent;
}

struct Qnode {
    int n;
    ll d;

    friend bool operator<(Qnode a, Qnode b) { return a.d > b.d; }
};

ll dist[N];

void Dijkstra(int u) {
    priority_queue<Qnode> q;
    dist[u] = 0;
    q.push({u, 0});
    while (!q.empty()) {
        Qnode p = q.top();
        q.pop();
        u = p.n;
        for (int i = head[u], v; ~i; i = ed[i].nx) {
            v = ed[i].v;
            if (dist[v] > dist[u] + ed[i].w) {
                dist[v] = dist[u] + ed[i].w;
                q.push({v, dist[v]});
            }
        }
    }
}


int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &n, &m, &k);
        memset(head, -1, sizeof head);
        memset(dist, INF, sizeof dist);

        for (int i = 1, u, v, w; i <= m; i++) {
            scanf("%d%d%d", &u, &v, &w);
            for (int j = 0; j <= k; j++) {
                AddEd(u + j * n, v + j * n, w);
                if (j < k)
                    AddEd(u + j * n, v + j * n + n, 0);
            }
        }
        Dijkstra(1);

        ll ans = INF;
        for (int i = 0; i <= k; i++)
            ans = min(ans, dist[n + n * k]);
        printf("%lld\n", ans);

        ent = 0;
    }
}
