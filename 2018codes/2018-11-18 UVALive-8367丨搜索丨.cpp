#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>

const int N = 20;
int n, m, ans_;
bool vis[N];
int x[N], y[N], vx[N], vy[N], cnt;

inline bool isPara(int _i, int _j) {
    return vx[_i] * vy[_j] == vy[_i] * vx[_j];
}

inline int ctPara() {
    int res = 0;
    for (int i = 1; i < cnt; i++)
        if (isPara(i, cnt))
            res++;
    return res;
}

inline void addVec(int _i, int _j) {
    vis[_i] = vis[_j] = true;
    cnt++;
    vx[cnt] = x[_j] - x[_i];
    vy[cnt] = y[_j] - y[_i];
}

inline void subVec(int _i, int _j) {
    vis[_i] = vis[_j] = false;
    cnt--;
}

void dfs(int p, int num, int mx) {
    if (ans_ >= num + (m - cnt + 1) * (m - cnt) / 2 + mx * (m - cnt))return;
    while (p < n && vis[p])p++;
    if (p == n)return;

    for (int j = n, now; j > p; j--) {
        if (!vis[j]) {
            addVec(p, j);
            now = ctPara();
            if (cnt == m)ans_ = std::max(ans_, now + num);
            else dfs(p + 1, now + num, std::max(mx, now));
            subVec(p, j);
        }
    }
}

int main() {
    while (scanf("%d", &n) != EOF) {
        ans_ = 0;
        m = n >> 1;
        for (int i = 1; i <= n; i++)
            scanf("%d %d", x + i, y + i);
        for (int i = 2; i <= n; i++) {
            addVec(1, i);
            if (0 != m)dfs(2, 0, 0);
            subVec(1, i);
        }
        printf("%d\n", ans_);
    }
    return 0;
}
/*
*/
