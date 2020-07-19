/**
  *    █████╗  ██████╗       ██████╗ ██╗     ███████╗
  *   ██╔══██╗██╔════╝       ██╔══██╗██║     ╚══███╔╝
  *   ███████║██║            ██████╔╝██║       ███╔╝
  *   ██╔══██║██║            ██╔═══╝ ██║      ███╔╝
  *   ██║  ██║╚██████╗▄█╗    ██║     ███████╗███████╗
  *   ╚═╝  ╚═╝ ╚═════╝╚═╝    ╚═╝     ╚══════╝╚══════╝
  *
  *  @Author: TieWay59
  *  @Created: 2020/1/13 15:00
  *  @Link: https://pintia.cn/problem-sets/1216577066538311680/problems/1216577133471023106
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

ll n;
ll a[MAXN];
ll cnt[66];

void add(ll x) {
    int i = 0;
    while (x) {
        i++;
        if (x & 1)cnt[i]++;
        x >>= 1;
    }
}

ll calc(ll x) {
    int i = 0;
    while (x) {
        x >>= 1;
        i++;
    }
    return cnt[i];
}

void solve(int kaseId = -1) {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    ll xsum = 0;
    ll xtmp = 0;
    ll ans = 0;
    bitset<66> ai;
    for (int i = 1; i <= n; ++i) {
        xsum ^= a[i];
        add(a[i]);

        if (xsum == 0) {
            cout << 0 << endl;
        } else {
            cout << calc(xsum) << endl;
        }
    }
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