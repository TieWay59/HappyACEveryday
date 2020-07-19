/**
  *    █████╗  ██████╗       ██████╗ ██╗     ███████╗
  *   ██╔══██╗██╔════╝       ██╔══██╗██║     ╚══███╔╝
  *   ███████║██║            ██████╔╝██║       ███╔╝
  *   ██╔══██║██║            ██╔═══╝ ██║      ███╔╝
  *   ██║  ██║╚██████╗▄█╗    ██║     ███████╗███████╗
  *   ╚═╝  ╚═╝ ╚═════╝╚═╝    ╚═╝     ╚══════╝╚══════╝
  *
  *  @Author: TieWay59
  *  @Created: 2020/2/3 2:42
  *  @Link: https://codeforces.com/contest/1291/problem/C
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
typedef long long ll;
const int MAXN = 2e5 + 59;
const int MOD = 1e9 + 7;
const int INF = 0x3F3F3F3F;
const ll llINF = 0x3F3F3F3F3F3F3F3F;
using namespace std;


void solve(int kaseId = -1) {
    int n, m, k, t;

    cin >> n >> m >> k;

    vector<int> a(n);
    vector<int> b;

    for (auto &ai:a) {
        cin >> ai;
    }

    k = min(k, m - 1);
    t = n - (m - 1);
    for (int i = 0; i + t - 1 < n; ++i) {
        b.emplace_back(max(a[i], a[i + t - 1]));
    }

    int w = b.size() - k;
    deque<pair<int, int>> q;
    int ans = -1;

    debug(b);
    debug(w);

    for (int i = 0; i < b.size(); ++i) {

        while (!q.empty() && q.front().first <= i - w) {
            q.pop_front();
        }

        while (!q.empty() && b[i] < q.back().second) {
            q.pop_back();
        }

        q.emplace_back(i, b[i]);

        if (i >= w - 1) {
            ans = max(ans, q.front().second);
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
    solves();
    return 0;
}
/*

 */