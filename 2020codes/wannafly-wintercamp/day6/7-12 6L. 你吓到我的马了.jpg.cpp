/**
  *    █████╗  ██████╗       ██████╗ ██╗     ███████╗
  *   ██╔══██╗██╔════╝       ██╔══██╗██║     ╚══███╔╝
  *   ███████║██║            ██████╔╝██║       ███╔╝
  *   ██╔══██║██║            ██╔═══╝ ██║      ███╔╝
  *   ██║  ██║╚██████╗▄█╗    ██║     ███████╗███████╗
  *   ╚═╝  ╚═╝ ╚═════╝╚═╝    ╚═╝     ╚══════╝╚══════╝
  *
  *  @Author: TieWay59
  *  @Created: 2020/1/17 13:24
  *  @Link: https://pintia.cn/problem-sets/1217973933671833600/problems/1217974362208067595
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

int dir[][2] = {
        {+1, +2},
        {-1, +2},
        {+1, -2},
        {-1, -2},
        {+2, +1},
        {+2, -1},
        {-2, +1},
        {-2, -1}
};

char g[155][155];
int vis[155][155];
int n, m;
int sr, sc;

void solve(int kaseId = -1) {

    memset(vis, -1, sizeof vis);

    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> g[i];
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == 'M') {
                sr = i;
                sc = j;
            }
        }
    }

    struct node {
        int r, c, d;
    };

    queue<node> que;
    vis[sr][sc] = 0;
    que.push({sr, sc, 0});

    while (!que.empty()) {
        int r = que.front().r;
        int c = que.front().c;
        int d = que.front().d;
        que.pop();


        for (int dr, dc, dd, i = 0; i < 8; ++i) {
            dr = r + dir[i][0];
            dc = c + dir[i][1];
            dd = d + 1;

            if (dr >= n || dc >= m || dr < 0 || dc < 0)
                continue;

            if (g[dr][dc] == 'X' || vis[dr][dc] != -1)
                continue;

            if (g[r + dir[i][0] / 2][c + dir[i][1] / 2] == 'X')
                continue;

            vis[dr][dc] = dd;
            que.push({dr, dc, dd});
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << vis[i][j] << " \n"[j == m - 1];
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