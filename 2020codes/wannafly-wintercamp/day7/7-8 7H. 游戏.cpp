/**
  *    █████╗  ██████╗       ██████╗ ██╗     ███████╗
  *   ██╔══██╗██╔════╝       ██╔══██╗██║     ╚══███╔╝
  *   ███████║██║            ██████╔╝██║       ███╔╝
  *   ██╔══██║██║            ██╔═══╝ ██║      ███╔╝
  *   ██║  ██║╚██████╗▄█╗    ██║     ███████╗███████╗
  *   ╚═╝  ╚═╝ ╚═════╝╚═╝    ╚═╝     ╚══════╝╚══════╝
  *
  *  @Author: TieWay59
  *  @Created: 2020/1/18 13:43
  *  @Link: https://pintia.cn/problem-sets/1218331719966515200/problems/1218332009230884874
  *  @Tags:
  *
  *******************************************************/

#include <bits/stdc++.h>

#ifdef DEBUG

#   include "libs59/debugers.h"
//  #define debug(x)  cerr <<#x << " = "<<x<<endl;
#else
#   define endl '\n'
#   define debug(...)  59
#endif

#define STOPSYNC ios::sync_with_stdio(false);cin.tie(nullptr)
#define MULTIKASE int Kase=0;cin>>Kase;for(int kase=1;kase<=Kase;kase++)
typedef long long ll;
const int MAXN = 2e5 + 59;
const int MOD = 1e9 + 7;
const int INF = 0x3F3F3F3F;
const ll llINF = 0x3F3F3F3F3F3F3F3F;
using namespace std;

ll a1, a2;
ll b1, b2;
ll n;

void solve(int kaseId = -1) {
    cin >> a1 >> a2;
    cin >> n;
    ll ans = llINF;
    for (int i = 1; i <= n; ++i) {

        cin >> b1 >> b2;
        ll bb1 = 0, bb2 = 0;
        ll aa1 = a1, aa2 = a2;
        ll cnt = 0;

        while (bb1 < b1 || bb2 < b2) {
            ll t1 = aa1 > 0 ? ((b1 - bb1) / aa1) : INF;
            ll t2 = aa2 > 0 ? ((b2 - bb2) / aa2) : INF;

            if (t1 > t2) {
                aa1++;
            } else if (t1 < t2) {
                aa2++;
            } else {
                if (b1 - bb1 >= b2 - bb2) {
                    aa1++;
                } else {
                    aa2++;
                }
            }

            bb1 += aa1;
            bb2 += aa2;
            debug(bb1, bb2);
            cnt++;
            if (cnt > ans)break;
        }
        ans = min(ans, cnt);
    }
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