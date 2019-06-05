#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;
typedef long long ll;
const int MAXN = 1e4 + 5;


int rmq[MAXN << 1];

struct ST {
    int _log[MAXN << 1];
    int dp[MAXN << 1][20];

    void Init(int n) {
        _log[0] = -1;
        for (int i = 1; i <= n; i++) {
            _log[i] = ((i & (i - 1)) == 0) ? _log[i - 1] + 1 : _log[i - 1];
            dp[i][0] = i;
        }
        for (int j = 1; j <= _log[n]; j++)
            for (int i = 1; i + (1 << j) - 1 <= n; i++)
                dp[i][j] = rmq[dp[i][j - 1]] < rmq[dp[i + (1 << (j - 1))][j - 1]] ?
                           dp[i][j - 1] : dp[i + (1 << (j - 1))][j - 1];
    }

    int query(int a, int b) {
        if (a > b)swap(a, b);
        int k = _log[b - a + 1];
        return rmq[dp[a][k]] <= rmq[dp[b - (1 << k) + 1][k]] ?
               dp[a][k] : dp[b - (1 << k) + 1][k];
    }
};

struct Edge {
    int to, nx;
};
Edge edge[MAXN << 1];
int tot, head[MAXN];

int F[MAXN << 1], cnt;
int P[MAXN];

ST st;

void Init() {
    tot = 0;
    memset(head, -1, sizeof(head));
}

void AddEdge(int u, int v) {
    edge[tot] = {v, head[u]};
    head[u] = tot++;
}

void dfs(int u, int pre, int dep) {
    F[++cnt] = u;
    rmq[cnt] = dep;
    P[u] = cnt;
    for (int i = head[u]; ~i; i = edge[i].nx) {
        int v = edge[i].to;
        if (v == pre)continue;
        dfs(v, u, dep + 1);
        F[++cnt] = u;
        rmq[cnt] = dep;
    }
}

void LCA_init(int root, int node_num) {
    cnt = 0;
    dfs(root, root, 0);
    st.Init(2 * node_num - 1);
}

int query_LAC(int u, int v) {
    return F[st.query(P[u], P[v])];
}

bool flag[MAXN];

int main() {
    int T, N, u, v;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        Init();
        memset(flag, false, sizeof(flag));
        for (int i = 1; i < N; i++) {
            scanf("%d%d", &u, &v);
            AddEdge(u, v);
            AddEdge(v, u);
            flag[v] = true;
        }
        int root = 1;
        for (int i = 1; i <= N; i++) {
            if (!flag[i]) {
                root = i;
                break;
            }
        }
        LCA_init(root, N);
        scanf("%d%d", &u, &v);
        printf("%d\n", query_LAC(u, v));
    }
    return 0;
}
