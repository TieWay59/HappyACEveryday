/**
  *    █████╗  ██████╗       ██████╗ ██╗     ███████╗
  *   ██╔══██╗██╔════╝       ██╔══██╗██║     ╚══███╔╝
  *   ███████║██║            ██████╔╝██║       ███╔╝
  *   ██╔══██║██║            ██╔═══╝ ██║      ███╔╝
  *   ██║  ██║╚██████╗▄█╗    ██║     ███████╗███████╗
  *   ╚═╝  ╚═╝ ╚═════╝╚═╝    ╚═╝     ╚══════╝╚══════╝
  *
  *  @Author: TieWay59
  *  @Created: 2020/1/12 15:27
  *  @Link: https://pintia.cn/problem-sets/1216205439967371264/problems/1216206397862526976
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
const int MAXN = 2e5 + 59;
const int MOD = 1e9 + 7;
const int INF = 0x3F3F3F3F;
const ll llINF = 0x3F3F3F3F3F3F3F3F;
using namespace std;

ll n, m, k;
ll a[MAXN];
ll b[MAXN];
ll minv;
ll cnt;
ll bi;
ll ai;

bool chek(ll x) {
    minv = llINF;
    cnt = 0;

    return cnt >= k;
}

void solve(int kaseId = -1) {

    cin >> n >> m >> k;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= m; ++i) {
        cin >> b[i];
    }

    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);

    vector<ll> ss;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            ss.emplace_back(a[i] * b[j]);
        }
    }
    sort(ss.begin(), ss.end(), greater<>());
    debug(ss);

    // find the start of non-neg number.
    // if bi == m+1 means all numbers are neg.
    ai = 1;
    for (int i = 1; i <= n; ++i) {
        if (a[i] < 0)bi = i + 1;
        if (a[i] >= 0)break;
    }

    bi = 1;
    for (int i = 1; i <= m; ++i) {
        if (b[i] < 0)bi = i + 1;
        if (b[i] >= 0)break;
    }


    ll l = -2e12, r = 2e12, mid, ans;

    while (l <= r) {
        mid = (l + r) / 2ll;

        if (chek(mid)) {
            ans = minv;
            if (cnt == k) {
                debug(mid);
            }
            l = mid + 1;
        } else {
            r = mid - 1;
        }
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


5 5 7
-2 -1 0 1 2
-2 -1 0 1 2


3 2 2
1 2 3
-5 -4

3 2 5
1000000
1000000
999999
1000000
1000000


4 4 11
-3 2 3 4
-5 4 5 6

 */