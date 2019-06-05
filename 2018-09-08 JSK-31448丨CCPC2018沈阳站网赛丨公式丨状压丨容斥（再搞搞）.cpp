#include <stdio.h>

typedef long long ll;
const ll mod = 1e9 + 7;
const ll inv6 = 166666668;
const ll inv2 = 500000004;
ll a[25];

ll clac(ll n, ll i) {
    n = (n / i) % mod;
    return (n * (n + 1) % mod * (2 * n + 1) % mod * i % mod * i % mod * inv6 % mod +
            n * (n + 1) % mod * inv2 % mod * i % mod) % mod;
}

int main() {
    ll n, m;
    while (scanf("%lld%lld", &n, &m) != EOF) {
        *a = 0;
        for (int i = 2; i * i <= m; i++)
            if (m % i == 0) {
                a[++*a] = i;
                while (m % i == 0)m /= i;
            }
        if (m != 1)a[++*a] = m;

        ll ans = clac(n, 1);
        ll tmp = 0;
        int sta = 1 << (*a);
        for (int cnt, mul, i = 1; i < sta; i++) {
            cnt = 0, mul = 1;
            for (int j = 0; j < *a; j++)
                if ((1 << j) & i) {
                    cnt++;
                    mul = mul * a[j + 1] % mod;
                }
            if (cnt & 1)
                tmp = (tmp + clac(n, mul)) % mod;
            else
                tmp = (tmp + mod - clac(n, mul)) % mod;
        }
        printf("%lld\n", (ans + mod - tmp) % mod);
    }
    return 0;
}
