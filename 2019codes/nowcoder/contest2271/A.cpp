/*
 *  @Author: TieWay59
 *  @Created: 2019/11/22 18:58
 *  @Link: https://ac.nowcoder.com/acm/contest/2271/A
 *  @Tags:
 **/


#include <bits/stdc++.h>

#define  debug(x)  cerr <<#x << " = "<<x<<endl

#define endl '\n'
#define STOPSYNC ios::sync_with_stdio(false);cin.tie(nullptr)
#define MULTIKASE int Kase=0;cin>>Kase;for(int kase=1;kase<=Kase;kase++)
typedef long long ll;
const int MAXN = 800 + 59;
const int MOD = 1e9 + 7;
const int INF = 0x3F3F3F3F;
const ll llINF = 0x3F3F3F3F3F3F3F3F;
using namespace std;

int n, m, k, y;
ll dp[MAXN];
ll a[MAXN];
ll p[MAXN][MAXN];

void solve(int kaseId = -1) {
    scanf("%d%d%d%d", &n, &m, &k, &y);

    for (int i = 1; i <= n; ++i) {
        scanf("%lld", a + i);
    }
    for (int i = 1; i <= k; ++i) {
        dp[i] = INF;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%lld", &p[i][j]);
        }
    }

    // i th item
    for (ll i = 1; i <= n; ++i) {

        // update dp
        for (ll j = k; j >= 1; --j) {

            // buy l times
            for (ll l = min(j, m * 1ll); l >= 1; --l) {
                dp[j] = min(dp[j], dp[j - l] + p[i][l] + (l < y ? a[i] * l : 0));
            }
        }
    }

    printf("%lld\n", dp[k]);
}

/*void solves() {
    MULTIKASE {
        solve(kase);
    }
}*/

int main() {
//    STOPSYNC;
//    solves();
    solve();
    return 0;
}
/*

 */