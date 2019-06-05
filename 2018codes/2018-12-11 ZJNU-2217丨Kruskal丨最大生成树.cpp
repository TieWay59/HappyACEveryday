#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>

using namespace std;
const int MAXN = 105;

struct Edge {
    int u, v, w;

    bool operator<(const Edge &T) const {
        return w < T.w;
    }
};

int a[MAXN], maxa;
priority_queue<Edge> que;
int Kase, n;

int pre[MAXN];

int getf(int x) {
    if (pre[x] == x)return x;
    else return pre[x] = getf(pre[x]);
}

bool merf(int x, int y) {
    int rx = getf(x);
    int ry = getf(y);
    if (rx == ry)return false;
    pre[ry] = rx;
    return true;
}

int Kruskal() {
    Edge t;
    int res = 0;
    while (!que.empty()) {
        t = que.top();
        que.pop();
        if (merf(t.u, t.v))
            res += t.w;
    }
    return res;
}

int main() {
    scanf("%d", &Kase);
    while (Kase--) {
        maxa = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", a + i);
            pre[i] = i;
            maxa = max(maxa, a[i]);
        }

        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
                que.push({i, j, a[i] ^ a[j]});
        printf("%d\n", Kruskal() + maxa);
    }
    return 0;
}
/*
    1   3   8   12
1   0   2   9   13
3   2   0   11  16
8   9   11  0   4
12  13  16  4   0
*/
