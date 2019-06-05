#include<stdio.h>
#include<algorithm>

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
typedef long long ll;

ll fpow(ll a, ll b) {
    ll res = 1;
    for (; b; a = a * a % mod, b >>= 1)
        if (b & 1)res = res * a % mod;
    return res;
}

struct node {
    ll m, x3;

    bool operator<(const node &T) const {
        if (x3 < T.x3 && m < T.m)
            return true;
        if (x3 >= T.x3 && m >= T.m)
            return false;
        if (m < T.m) {
            if (x3 - T.x3 > 10)return false;
            return fpow(3, x3 - T.x3) * m < T.m;
        } else {
            if (T.x3 - x3 > 10)return true;
            return fpow(3, T.x3 - x3) * T.m > m;
        }
    }
} a[maxn], mx;

int n, Kase, cnt;

int main() {
    scanf("%d", &Kase);
    while (Kase--) {
        scanf("%d", &n);
        cnt = 0;
        for (int i = 0, m; i < n; i++) {
            scanf("%d", &m);
            if (i + m > n) {
                a[++cnt] = {m, i / 3};
                if (i % 3 == 2)
                    a[cnt].m <<= 1;
                if (i % 3 == 1)
                    a[cnt].m <<= 2, a[cnt].x3--;
            }
        }
        if (n <= 2) {
            puts("4");
            continue;
        }
        mx = {0ll, 0ll};
        for (int i = 1; i <= cnt; i++)
            mx = std::max(mx, a[i]);
        printf("%lld\n", mx.m * fpow(3ll, mx.x3) % mod);
    }
    return 0;
}

