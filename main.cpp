#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef pair<int, int> pint;

const int N = 100 + 5, K = 2000 + 5;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
ll g[N][K];
int f[K], a[N], b[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, upp;
    cin >> n >> m >> upp;
    for (int i = 0; i <= upp; i++)
        cin >> f[i];
    for (int i = 1; i <= m; i++)
        cin >> a[i] >> b[i];

    for (int i = 1; i <= n + 1; i++)
        for (int j = 0; j < K; j++)
            g[i][j] = -INF_LL;
    g[1][0] = 0;

    for (int i = 2; i <= n + 1; i++) {
        for (int j = 0; j < K; j++)
            g[i][j + f[j]] = max(g[i][j + f[j]], g[i - 1][j]);
        for (int j = K - 1; j >= 0; j--)
            for (int k = 1; k <= m; k++) {
                if (j - a[k] < 0) continue;
                g[i][j - a[k]] = max(g[i][j - a[k]], g[i][j] + b[k]);
            }
    }

    ll ans = 0;
    for (int j = 0; j < K; j++)
        ans = max(ans, j + g[n + 1][j]);
    cout << ans;

    return 0;
}