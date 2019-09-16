/*
*  https://www.jisuanke.com/contest/3007
*
*/
//#include <bits/stdc++.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>

#define  _debug(x) cerr<<#x<<" = "<<x<<endl
using namespace std;
typedef long long ll;
const int MAXN = 2e2 + 59; //todo change the size

const int MAXM = 2e6 + 59;
const ll MOD = 1e9 + 7;
const ll INF = 0x0f0f0f0f;

int kase;
ll k, n;
ll a[MAXN];
ll sum[MAXN];

int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
    scanf("%d", &kase);
    while (kase--) {
        scanf("%lld%lld", &k, &n);

        for (int i = 1; i <= 2 * k; i++) {
            scanf("%lld", a + i);
        }
        for (int i = 1; i <= k; ++i) {
            sum[i] = (sum[i - 1] + a[i]) % MOD;
        }
        ll ans = 0;
        if (k <= n) {
            ans = (sum[k] + a[k + 1] * (n - k) % MOD) % MOD;
        } else {
            ans = sum[n];
        }
        printf("%lld\n", ans);
    }

    return 0;
}
/*
2
1 9000000000000000
2 2
2 8
6 5 5 5

 */