/**
  *    █████╗  ██████╗       ██████╗ ██╗     ███████╗
  *   ██╔══██╗██╔════╝       ██╔══██╗██║     ╚══███╔╝
  *   ███████║██║            ██████╔╝██║       ███╔╝
  *   ██╔══██║██║            ██╔═══╝ ██║      ███╔╝
  *   ██║  ██║╚██████╗▄█╗    ██║     ███████╗███████╗
  *   ╚═╝  ╚═╝ ╚═════╝╚═╝    ╚═╝     ╚══════╝╚══════╝
  *
  *  @Author: TieWay59
  *  @Created: 2020/3/28 5:44
  *  @Link: http://acm.hdu.edu.cn/showproblem.php?pid=1667
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
#   define max(x,y) ((x)>(y)?(x):(y))
#   define min(x,y) ((x)>(y)?(y):(x))
#endif

#define STOPSYNC ios::sync_with_stdio(false);cin.tie(nullptr)
#define MULTIKASE int Kase=0;cin>>Kase;for(int kase=1;kase<=Kase;kase++)
typedef long long ll;
const int MAXN = 2e5 + 59;
const int MOD = 1e9 + 7;
const int INF = 0x3F3F3F3F;
const ll llINF = 0x3F3F3F3F3F3F3F3F;
using namespace std;
using pii = pair<int, int>;
using vint = vector<int>;
using trace_t = string;

const vector<vint> dir = {
        {1,  3,  7,  12, 16, 21, 23},
        {2,  4,  9,  13, 18, 22, 24},
        {11, 10, 9,  8,  7,  6,  5},
        {20, 19, 18, 17, 16, 15, 14},
        {24, 22, 18, 13, 9,  4,  2},
        {23, 21, 16, 12, 7,  3,  1},
        {14, 15, 16, 17, 18, 19, 20},
        {5,  6,  7,  8,  9,  10, 11}
};

const vector<ll> target = {
        22569635840ll,
        45139271680ll,
        67708907520ll
};

/*void display(ll x) {
    vint res;
    while (x) {
        res.emplace_back(x & 3);
        x >>= 2;
    }

    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 7; ++j) {
            if (i == 2 || i == 4 || j == 2 || j == 4) {
                cerr << res.back();
                res.pop_back();
            } else {
                cerr << " ";
            }
        }
        cerr << '\n';
    }
    cerr << string(10, '*') << endl;
}*/

void solve(int kaseId = -1) {

    const auto h = [&](ll s, ll t) -> int {
        int cnt = 0, u, v;
        while (t && s) {
            u = s & 3;
            v = t & 3;
            cnt += int(v > 0 && u != v);
            s >>= 2;
            t >>= 2;
        }
        return cnt;
    };

    const auto digitSwap = [](ll &s, ll a, ll b) {
        a = 2 * (a - 1);
        b = 2 * (b - 1);
        ll x = (s >> a) & 3;
        ll y = (s >> b) & 3;
        s = s - (x << a) - (y << b)
            + (x << b) + (y << a);
    };

    auto makeMove = [&](ll s, int c) -> ll {
        for (int i = 1; i < 7; ++i) {
            digitSwap(s, 25 - dir[c][i - 1], 25 - dir[c][i]);
        }
        return s;
    };

    auto DFS = [&](auto dfs, ll u, ll f, const ll &t,
                   const int &limit, trace_t &trace) -> bool {
        /*if (t == 45139271680ll) {
            debug(trace, h(u, t));
            if (trace.size() <= 2) {
                display(u);
            }
        }*/
        if (h(u, t) == 0) return true;
        if (trace.size() >= limit)return false;

        for (int i = 0; i < 8; ++i) {
            ll v = makeMove(u, i);
            if (v == f)continue;
            if (trace.size() + 1 + h(v, t) > limit)continue;
            trace.append(1, char(i + 'A'));
            if (dfs(dfs, v, u, t, limit, trace))return true;
            trace.pop_back();
        }
        return false;
    };

    const auto IDAstar = [&](ll s, ll t, trace_t &trace) {
        for (int depth = h(s, t);; depth++) {
            trace.clear();
            if (DFS(DFS, s, -1, t, depth, trace)) {
                return true;
            }
        }
        return false;
    };

    /*ll state = 94484427091359ll;
    display(state);
    digitSwap(state, 25 - 3, 25 - 7);
    display(state);*/

    ll state = 0;
    string input;
    while (getline(cin, input)) {

        state = 0;
        for (auto in:input)
            if ('0' <= in && in < '4')
                state = (state << 2) + int(in - '0');
        if (state == 0)break;
        debug(state);

        int ans = -1;
        trace_t tmp, res;
        tmp.reserve(300);
        res.reserve(300);
        for (int i = 0; i < 3; ++i) {
            if (IDAstar(state, target[i], tmp)) {
                if (ans == -1 || tmp.size() < res.size()) {
                    res.swap(tmp);
                    ans = i + 1;
                } else if (tmp.size() == res.size() && tmp < res) {
                    res.swap(tmp);
                    ans = i + 1;
                }
            }
        }

        if (res.size() == 0) {
            cout << "No moves needed" << endl;
        } else {
            for (const auto &ch:res)cout.put(ch);
            cout << endl;
        }
        cout << ans << endl;
    }
}

void solves() {
    MULTIKASE {
        solve(kase);

    }
}

int main() {
#ifdef DEBUG
    freopen("input.txt", "r+", stdin);
#endif
    STOPSYNC;
    solve();
    return 0;
}
/*
 ACECBH
        0 0 0 0 0 0 1 1 1 0 0 1 1 0 0 1 1 1 0 0 0 0 0 0
        0 0 0 0 0 0 2 2 2 0 0 2 2 0 0 2 2 2 0 0 0 0 0 0
        0 0 0 0 0 0 3 3 3 0 0 3 3 0 0 3 3 3 0 0 0 0 0 0

1 1 1 1 3 2 3 2 3 1 3 2 2 3 1 2 2 2 3 1 2 1 3 3
1 1 1 1 1 1 1 1 2 2 2 2 2 2 2 2 3 3 3 3 3 3 3 3
0

 */