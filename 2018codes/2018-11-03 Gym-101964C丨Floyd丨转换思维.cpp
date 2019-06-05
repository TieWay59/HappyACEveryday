#include <stdio.h>
#include <string.h>
#include <algorithm>

const int N = 105;
const int INF = 0x3f3f3f3f;
int n, m, dis[N][N];
int stk[N], top;

int main() {
    //freopen("test.txt","r",stdin);
    scanf("%d %d", &n, &m);
    for (int i = 1, x; i <= n; i++) {
        scanf("%d", &x);
        if (x)stk[top++] = i;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            if (i == j)continue;
            else dis[i][j] = 200;
        }

    for (int a, b, i = 1; i < n; i++) {
        scanf("%d %d", &a, &b);
        dis[a][b] = 1;
        dis[b][a] = 1;
    }
    if (m == 1) {
        printf("0\n");
        return 0;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);

    int ans = INF;
    for (int i = 0; i < top; i++)
        for (int j = i + 1; j < top; j++) {
            int cnt = 0;
            for (int k = 0; k < top; k++) {
                if (dis[stk[i]][stk[k]] <= dis[stk[i]][stk[j]]
                    && dis[stk[k]][stk[j]] <= dis[stk[i]][stk[j]])
                    cnt++;
                if (cnt >= m) {
                    ans = std::min(ans, dis[stk[i]][stk[j]]);
                    break;
                }
            }
        }
    printf("%d\n", ans);
    return 0;
}
/*

*/
