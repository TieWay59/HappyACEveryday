/**
  *    █████╗  ██████╗       ██████╗ ██╗     ███████╗
  *   ██╔══██╗██╔════╝       ██╔══██╗██║     ╚══███╔╝
  *   ███████║██║            ██████╔╝██║       ███╔╝
  *   ██╔══██║██║            ██╔═══╝ ██║      ███╔╝
  *   ██║  ██║╚██████╗▄█╗    ██║     ███████╗███████╗
  *   ╚═╝  ╚═╝ ╚═════╝╚═╝    ╚═╝     ╚══════╝╚══════╝
  *
  *  @Author: TieWay59
  *  @Created: 2020/1/17 15:24
  *  @Link: https://pintia.cn/problem-sets/1217973933671833600/problems/1217974362208067589
  *  @Tags:
  *
  *******************************************************/

#include <bits/stdc++.h>

#ifdef DEBUG

#   include "libs59/debugers.h"
//  #define debug(x)  cerr <<#x << " = "<<x<<endl;
#else
#   define endl '\n'
#   define debug(x)  59
#endif

#define STOPSYNC ios::sync_with_stdio(false);cin.tie(nullptr)
#define MULTIKASE int Kase=0;cin>>Kase;for(int kase=1;kase<=Kase;kase++)
typedef long long ll;
const int MAXN = 5000 + 59;
const int MOD = 1e9 + 7;
const int INF = 0x3F3F3F3F;
const ll llINF = 0x3F3F3F3F3F3F3F3F;
using namespace std;


ll n;
ll cnt[MAXN][2];
ll A, B, C, P, D;

void solve(int kaseId = -1) {
    // 0 ~ black
    // 1 ~ white

    cin >> n;
    cin >> A >> B >> C >> P >> D;

    for (ll i = 1; i <= n; ++i) {
        for (ll j = i + 1; j <= n; ++j) {
            if ((A * (i + j) % P * (i + j) % P +
                 B * (i - j) % P * (i - j) % P + C) % P > D) {
                cnt[i][0]++;
                cnt[j][0]++;
            } else {
                cnt[i][1]++;
                cnt[j][1]++;
            }
        }
    }

    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += cnt[i][0] * cnt[i][1];
    }

    ans = n * (n - 1) * (n - 2) / 6ll - ans / 2ll;
    cout << ans << endl;
}

void solves() {
    MULTIKASE {
        solve(kase);
    }
}

int main() {
    STOPSYNC;
    solve();
    return 0;
}
/*

 */