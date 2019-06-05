//https://www.nowcoder.com/acm/contest/147/E

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll inv100 = 570000004;
const int N = 1020;
int n, m;
ll p[N], a[N], b[N];
ll s[N][N], f[N];//s�ǵڶ���stirling��
int main() {
    scanf("%d%d", &n, &m);

    s[0][0] = 1;
    for (int i = 0; i <= m; i++)
        for (int j = 1; j <= i; j++)
            s[i][j] = (s[i - 1][j - 1] + j * s[i - 1][j]) % mod;

    f[0] = 1;
    for (int i = 1; i <= m; i++)
        f[i] = f[i - 1] * i % mod;

    for (int i = 1; i <= n; i++) {
        scanf("%lld", &p[i]);
        p[i] = p[i] * inv100 % mod;

        for (int j = m; j > 0; j--) {
            a[j] = (a[j] + a[j - 1]) * p[i] % mod;
            b[j] = (b[j] + a[j]) % mod;
        }
        a[0] = p[i];
        b[0] = (b[0] + a[0]) % mod;
    }
    ll ans = 0;
    for (int i = 1; i <= m; i++)
        ans = (ans + b[i - 1] * f[i] % mod * s[m][i]) % mod;

    printf("%lld\n", ans);
    return 0;
}
