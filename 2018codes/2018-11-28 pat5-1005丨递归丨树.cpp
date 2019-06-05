#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 105;
const int INF = 0x3f3f3f3f;
vector<int> g[MAXN];
int T, n, m, k;
int dp[MAXN];

void DFS(int u, int f, int st) {
    dp[st]++;
    for (int v:g[u])
        if (v != f)
            DFS(v, u, st + 1);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1, u, num; i <= m; i++) {
        scanf("%d %d", &u, &num);
        for (int j = 1, v; j <= num; j++) {
            scanf("%d", &v);
            g[u].push_back(v);
        }
    }
    DFS(1, 0, 1);
    int ger = 1, ans = dp[1];
    for (int i = 2; i <= n; i++)
        if (ans < dp[i])
            ger = i, ans = dp[i];
    printf("%d %d\n", ans, ger);
    return 0;
}
/*
3
3 3 0
3 3 1
2 2
5 5 5
1 5
2 1
3 3
4 2
5 4
*/
