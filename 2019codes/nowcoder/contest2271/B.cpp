/*
 *  @Author: TieWay59
 *  @Created: 2019/11/22 19:19
 *  @Link: https://ac.nowcoder.com/acm/contest/2271/B
 *  @Tags:
 **/


#include <bits/stdc++.h>

#define  debug(x)  cerr <<#x << " = "<<x<<endl

#define endl '\n'
#define STOPSYNC ios::sync_with_stdio(false);cin.tie(nullptr)
#define MULTIKASE int Kase=0;cin>>Kase;for(int kase=1;kase<=Kase;kase++)
typedef long long ll;
const int MAXN = 2e5 + 59;
const int MOD = 1e9 + 7;
const int INF = 0x3F3F3F3F;
const ll llINF = 0x3F3F3F3F3F3F3F3F;
using namespace std;

int dp[MAXN];

void dabiao() {
    dp[1] = 0;
    for (int i = 2; i <= 100; i++) {
        dp[i] = (dp[i - 1] + 2) % i;
        printf("i=%d  dp=%d\n", i, dp[i] + 1);
    }
}

ll n, m;

void solve(int kaseId = -1) {

    scanf("%lld%lld", &n, &m);
    if (m % 2 == 0) {
        printf("0 0\n");
        return;
    }

    ll ans1 = 0;
    ll ans2 = 0;
    ll bin = 1;
    ll cnt = 1;
    while (bin * 2 <= n) {
        bin *= 2;
        cnt++;
        if (bin * 2 - 1 >= m && bin + m / 2 <= n) {
            ans1++;
            ans2 = bin + m / 2;
        }
    }
    if (m == 1)ans1++;
    if (n == 1)ans2 = 1;
    printf("%lld %lld\n", ans1, ans2);
}

/*void solves() {
    MULTIKASE {
        solve(kase);
    }
}*/
int main() {
    STOPSYNC;
//    solves();

    solve();
    return 0;
}
/*
 *
 1
 1
 3
 1
 3
 5
 7
 1
 3

 */