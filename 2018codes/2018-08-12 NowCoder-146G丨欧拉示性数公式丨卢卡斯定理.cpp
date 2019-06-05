#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mo = 1000000007;
const int N = 262144 + 6;

ll fpow(ll a, ll b) {
    ll ans = 1;
    a %= mo;
    while (b) {
        if (b & 1)ans = (ans * a) % mo;
        a = (a * a) % mo;
        b >>= 1;
    }
    return ans;
}

ll C(ll n, ll m) {
    if (n < m)return 0;

    ll ans = 1;
    for (int i = 1; i <= m; i++)
        ans = ans * ((n - m + i) % mo * fpow(i, mo - 2) % mo) % mo;
    return ans;
}

ll lucas(ll n, ll m) {
    if (m == 0)return 1;
    return (lucas(n / mo, m / mo) * C(n % mo, m % mo)) % mo;
}

ll n, m, p;

int main() {
    scanf("%lld", &n);
    printf("%lld", (lucas(n, 4) + lucas(n - 1, 2)) % mo);
    return 0;
}
