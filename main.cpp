

/*
 * https://codeforces.com/contest/1216/problem/F
 *
 */
#include <bits/stdc++.h>

#define  _debug(x) cerr<<#x << " = " << x<<endl
using namespace std;

typedef long long ll;
const int MOD = -1;
const double eps = 1e-3;
const int MAXN = 3e3 + 59;
const ll INF = 0x3f3f3f3f3f3f3f;

int kase;
int n, m, k;

int f[MAXN];

struct node {
    int a, b;
} p[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for (int i = 2; i <= 2 + k; ++i) {
        cin >> f[i];
        f[i] += f[i - 1];
    }
    for (int j = 1; j <= m; ++j) {
        cin >> p[j].a >> p[j].b;
    }
    sort(p + 1, p + 1 + m, [](node x, node y) {
        return x.b * y.a > y.b * x.a;
    });
    int sum = f[n - 2];
    int ans = sum;
    for (int i = 1; i <= m; ++i) {
        if (sum >= p[i].a) {
            ans += sum / p[i].a * p[i].b;
            sum %= p[i].a;
        }
    }
    cout << ans << endl;
    return 0;
}
