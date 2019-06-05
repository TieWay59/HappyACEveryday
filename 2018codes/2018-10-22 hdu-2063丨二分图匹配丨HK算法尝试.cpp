#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>

const int MAXN = 3000;
const int INF = 0x3f3f3f3f;
std::vector<int> G[MAXN];
int uN;
int Mx[MAXN], My[MAXN];
int dx[MAXN], dy[MAXN];
int dis;
bool used[MAXN];

bool SearchP() {
    std::queue<int> Q;
    dis = INF;
    memset(dx, -1, sizeof dx);
    memset(dy, -1, sizeof dy);
    for (int i = 0; i < uN; i++)
        if (Mx[i] == -1) {
            Q.push(i);
            dx[i] = 0;
        }
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        if (dx[u] > dis)break;
        int sz = G[u].size();
        for (int v:G[u]) {
            if (dy[v] == -1) {
                dy[v] = dx[u] + 1;
                if (My[v] == -1)dis = dy[v];
                else {
                    dx[My[v]] = dy[v] + 1;
                    Q.push(My[v]);
                }
            }
        }
    }
    return dis != INF;
}

bool DFS(int u) {
    int sz = G[u].size();
    for (int v:G[u]) {
        if (!used[v] && dy[v] == dx[u] + 1) {
            used[v] = true;
            if (My[v] != -1 && dy[v] == dis)
                continue;
            if (My[v] == -1 || DFS(My[v])) {
                My[v] = u;
                Mx[u] = v;
                return true;
            }
        }
    }
    return false;
}

int MaxMatch() {
    int res = 0;
    memset(Mx, -1, sizeof Mx);
    memset(My, -1, sizeof My);
    while (SearchP()) {
        memset(used, false, sizeof used);
        for (int i = 0; i < uN; i++)
            if (Mx[i] == -1 && DFS(i))
                res++;
    }
    return res;
}

int main() {
    int k, m, n;
    while (scanf("%d", &k) != EOF && k) {
        scanf("%d%d", &n, &m);
        uN = n;
        for (int i = 1, x, y; i <= k; i++) {
            scanf("%d%d", &x, &y);
            G[x - 1].push_back(y - 1);
        }
        printf("%d\n", MaxMatch());
        memset(used, false, sizeof used);
        for (int i = 0; i < n; i++)
            G[i].clear();
    }
    return 0;
}
/*
6 3 3 1 1 1 2 1 3 2 1 2 3 3 1
2 3 2
1 2
2 1
*/
