#include<stdio.h>

const int N = 4e5 + 10;
struct Edge {
    int from, to, nxt;

} E[N * 2];
int head[N], cntE;

void addE(int a, int b) {
    E[cntE] = {a, b, head[a]};
    head[a] = cntE++;
}

int duandian1, duandian2, duandian3, ans, tmp, maxu, maxv;
bool visit[N];

void dfs0(int u, int fa, int dep) {
    if (dep > maxv) {
        maxu = u;
        maxv = dep;
    }
    for (int ei = head[u]; ei != -1; ei = E[ei].nxt) {
        if (E[ei].to == fa || visit[E[ei].to])continue;
        dfs0(E[ei].to, u, dep + 1);
    }
}

void dfs1(int u, int fa, int tar) {
    if (u == tar)visit[u] = 1;
    for (int ei = head[u]; ei != -1; ei = E[ei].nxt) {
        if (E[ei].to == fa)continue;
        dfs1(E[ei].to, u, tar);
        visit[u] |= visit[E[ei].to];
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)head[i] = -1;
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        addE(u, v);
        addE(v, u);
    }
    dfs0(1, -1, 0);
    duandian1 = maxu;
    //printf("%d\n",maxu);
    maxv = 0;
    dfs0(duandian1, -1, 0);
    //printf("%d\n",maxu);
    duandian2 = maxu;
    ans = maxv;
    dfs1(duandian1, -1, duandian2);
    for (int i = 1; i <= n; i++) {
        if (!visit[i] || i == duandian1 || i == duandian2)continue;
        maxu = i;
        maxv = 0;
        dfs0(i, -1, 0);
        if (tmp <= maxv) {
            tmp = maxv;
            duandian3 = maxu;
        }
    }
    printf("%d\n", ans + tmp);
    printf("%d %d %d\n", duandian1, duandian2, duandian3);
}