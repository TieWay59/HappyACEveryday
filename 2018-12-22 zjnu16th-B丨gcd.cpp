//https://blog.csdn.net/qq_41707122/article/details/80197744
#include <stdio.h>
#include<algorithm>

typedef long long ll;
const int MAXN = 100010;
using namespace std;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

ll n, x, a, b;

int main() {
    while (scanf("%lld%lld%lld%lld", &n, &x, &a, &b) != EOF) {
        n -= b;
        ll g = gcd(a, x);
        if (n % g != 0) {
            puts("0");
            continue;
        }
        ll l = lcm(a, x);
        ll ans = n / l;
        n = n % l;
        while (n >= 0) {
            if (n % x == 0) {
                ans++;
                break;
            }
            n -= a;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
