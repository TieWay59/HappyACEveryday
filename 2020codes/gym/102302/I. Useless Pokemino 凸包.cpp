/**
  *    █████╗  ██████╗       ██████╗ ██╗     ███████╗
  *   ██╔══██╗██╔════╝       ██╔══██╗██║     ╚══███╔╝
  *   ███████║██║            ██████╔╝██║       ███╔╝
  *   ██╔══██║██║            ██╔═══╝ ██║      ███╔╝
  *   ██║  ██║╚██████╗▄█╗    ██║     ███████╗███████╗
  *   ╚═╝  ╚═╝ ╚═════╝╚═╝    ╚═╝     ╚══════╝╚══════╝
  *
  *  @Author: TieWay59
  *  @Created: 2020/2/8 20:00
  *  @Link: https://vjudge.net/contest/355794?tdsourcetag=s_pctim_aiomsg#problem/I
  *  @Tags: 
  *
  *******************************************************/

#include <bits/stdc++.h>

#ifdef DEBUG

#   include "libs59/debugers.h"
//  #define debug(x)  cerr <<#x << " = "<<x<<endl;
#else
#   define endl '\n'
#   define debug(...)
#endif

#define STOPSYNC ios::sync_with_stdio(false);cin.tie(nullptr)
#define MULTIKASE int Kase=0;cin>>Kase;for(int kase=1;kase<=Kase;kase++)
#define x first
#define y second
typedef long long ll;
const int MAXN = 2e5 + 59;
const int MOD = 1e9 + 7;
const int INF = 0x3F3F3F3F;
const ll llINF = 0x3F3F3F3F3F3F3F3F;
using namespace std;

using pii = pair<int, int>;
using pset = set<pii>;
using pset_it = set<pii>::iterator;

void solve(int kaseId = -1) {
    auto cmp = [](pii a, pii b) -> bool {
        a.y *= -1;
        b.y *= -1;
        return a.x < b.x && a.y < b.y;
    };
    /* Note:
     * check if point z is above line a-b;
     * (x - ax) / (bx - ax) = (y - ay) / (by - ay)
     */
    auto check = [](pii a, pii b, pii z) -> bool {
        debug(a, b, z);
        if (a.x == b.x) return true;
        a.y *= -1;
        b.y *= -1;
        z.y *= -1;
        ll zx_ax = z.x - a.x;
        ll bx_ax = b.x - a.x;
        ll zy_ay = z.y - a.y;
        ll by_ay = b.y - a.y;
        return zx_ax * by_ay <= zy_ay * bx_ax;
    };

    int n;
    pset s;
    cin >> n;
    for (int i = 1, x, y; i <= n; ++i) {
        cin >> x >> y;
        pii cur(x, -y);
        debug(cur);
        pset_it nxt;
        pset_it it1, it2;

        while ((it1 = s.upper_bound(cur)) != s.end()) {
            it2 = it1, it2++;
            if (it2 == s.end())break;
            if (check(cur, *it2, *it1))break;
            s.erase(it1);
        }
        debug(s);

        while ((it1 = s.upper_bound(cur)) != s.begin()) {
            it2 = --it1;
            if (cmp(*it1, cur)) {
                s.erase(it1);
                continue;
            }
            if (it1 == s.begin())break;
            it2--;
            if (check(*it2, cur, *it1))break;
            s.erase(it1);
        }
        debug(s);

        nxt = s.upper_bound(cur);
        if (nxt != s.end() && nxt != s.begin()) {
            it1 = it2 = nxt, it1--;
            if (check(*it1, *it2, cur))
                s.emplace(cur);
        } else if (nxt == s.end() || !cmp(cur, *nxt)) {
            s.emplace(cur);
        }
        debug(s);
        cout << i - s.size() << endl;
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