#include<stdio.h>
#include<algorithm>

typedef long long ll;
int T, Ti;
ll x, l, n;

int main() {
    scanf("%d", &T);
    while (Ti++ < T) {
        scanf("%lld%lld%lld", &x, &l, &n);
        ll sum = std::max(0ll, x - l);
        //when x>l,x won't be list in these rounds;
        if (x & 1) {
            ll j = (x - 1) / 2;
            //safe position x=2*j+1 when n=2^k+j,check every n;
            for (ll i = 1; i + j <= n; i <<= 1) {
                if (i + j < l || i + j < x)continue;
                sum++;
            }
        } else if (x <= l) {
            //x is even and can be listed in every round;
            printf("Case %d: 0/1\n", Ti);
            continue;
        }
        ll gcd = std::__gcd(sum, n - l + 1);
        printf("Case %d: %lld/%lld\n", Ti, sum / gcd, (n - l + 1) / gcd);
    }
    return 0;
}
/*
3
1 1 1
2 3 10
4 1 7
*/
