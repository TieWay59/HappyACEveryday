/**
  *    █████╗  ██████╗       ██████╗ ██╗     ███████╗
  *   ██╔══██╗██╔════╝       ██╔══██╗██║     ╚══███╔╝
  *   ███████║██║            ██████╔╝██║       ███╔╝
  *   ██╔══██║██║            ██╔═══╝ ██║      ███╔╝
  *   ██║  ██║╚██████╗▄█╗    ██║     ███████╗███████╗
  *   ╚═╝  ╚═╝ ╚═════╝╚═╝    ╚═╝     ╚══════╝╚══════╝
  *
  *  @Author: TieWay59
  *  @Created: 2020/1/18 15:43
  *  @Link: https://pintia.cn/problem-sets/1218331719966515200/problems/1218332009230884864
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


bool check_bits(int bits, int i) {
    return bits & (1 << --i);
}

int insert_bits(int bits, int i) {
    return bits | (1 << --i);
}

vector<int> ed[21];
int n, m, q;
int lastCnt[21];    // count how many black has generated for every i.
bool vis[1 << 21 | 1023];

int x;

void solve(int kaseId = -1) {

    cin >> n >> m >> q;

    int cur = 0, tmp;
    for (int i = 1, si; i <= n; ++i) {
        cin >> si;
        if (si == 1)
            cur = insert_bits(cur, i);
    }

    x++;

    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        ed[u].emplace_back(v);
        ed[v].emplace_back(u);
    }
    while (!vis[cur]) {

        for (int u = 1; u <= n; ++u) {
            for (auto v:ed[u]) {

            }
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