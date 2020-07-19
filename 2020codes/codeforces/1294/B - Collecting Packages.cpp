/**
  *    █████╗  ██████╗       ██████╗ ██╗     ███████╗
  *   ██╔══██╗██╔════╝       ██╔══██╗██║     ╚══███╔╝
  *   ███████║██║            ██████╔╝██║       ███╔╝
  *   ██╔══██║██║            ██╔═══╝ ██║      ███╔╝
  *   ██║  ██║╚██████╗▄█╗    ██║     ███████╗███████╗
  *   ╚═╝  ╚═╝ ╚═════╝╚═╝    ╚═╝     ╚══════╝╚══════╝
  *
  *  @Author: TieWay59
  *  @Created: 2020/1/22 23:56
  *  @Link: http://m3.codeforces.com/contest/1294/problem/B
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
    string ans;
    int n;
    cin >> n;
    vector<tuple<int, int>> nodes(n);
    for (int i = 0, x, y; i < n; ++i) {
        cin >> x >> y;
        nodes[i] = tie(x, y);
    }

    sort(nodes.begin(), nodes.end());

    int cnt = 0;
    int lx = 0, ly = 0;
    for (int j = 0, x, y; j < n; ++j) {
        tie(x, y) = nodes[j];
        if (x < lx || y < ly)break;
        if (lx < x)ans.append(x - lx, 'R');
        if (ly < y)ans.append(y - ly, 'U');
        tie(lx, ly) = tie(x, y);
        cnt++;
    }
    if (cnt < n) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl << ans << endl;
    }
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