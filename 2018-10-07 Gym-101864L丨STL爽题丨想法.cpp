#include<stdio.h>
#include<algorithm>

typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int N = 1e5 + 5;
int T, Ti;
ll n, p;
ll st[N], ed[N];

int main() {
    scanf("%d", &T);
    while (Ti++ < T) {
        scanf("%lld%lld", &n, &p);
        for (int i = 0; i < n; i++)
            scanf("%lld %lld", st + i, ed + i);
        std::sort(st, st + n);
        std::sort(ed, ed + n);
        ll ans = INF;
        for (int i = 0, j = p - 1; j < n; i++, j++) {
            ll tmp = st[j] - ed[i];
            if (tmp <= 0ll) {
                ans = 0ll;
                break;
            }
            ans = std::min(ans, tmp);
        }
        printf("Case %d: %lld\n", Ti, ans);
    }
    return 0;
}
/*
3
1 1 1
2 3 10
4 1 7
*/
