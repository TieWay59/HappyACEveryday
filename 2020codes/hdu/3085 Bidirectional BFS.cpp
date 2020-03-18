/**
  *    █████╗  ██████╗       ██████╗ ██╗     ███████╗
  *   ██╔══██╗██╔════╝       ██╔══██╗██║     ╚══███╔╝
  *   ███████║██║            ██████╔╝██║       ███╔╝
  *   ██╔══██║██║            ██╔═══╝ ██║      ███╔╝
  *   ██║  ██║╚██████╗▄█╗    ██║     ███████╗███████╗
  *   ╚═╝  ╚═╝ ╚═════╝╚═╝    ╚═╝     ╚══════╝╚══════╝
  *
  *  @Author: TieWay59
  *  @Created: 2020/3/17 15:58
  *  @Link: http://acm.hdu.edu.cn/showproblem.php?pid=3085
  *  @Tags: Bidirectional BFS
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
const int MAXN = 800 + 59;
const int MOD = 1e9 + 7;
const int INF = 0x3F3F3F3F;
const ll llINF = 0x3F3F3F3F3F3F3F3F;
using namespace std;

using pii = pair<int, int>;
using vint = vector<int>;
const int dir[4][2] = {
        {1,  0},
        {0,  1},
        {-1, 0},
        {0,  -1}
};

int bfs(vector<string> &g, int n, int m, pii s, pii t, pii z1, pii z2) {
    queue<pii> s_que;
    queue<pii> t_que;
    s_que.emplace(s);
    t_que.emplace(t);
    int steps = 0;

    auto checkInvalid = [&](int dr, int dc) -> bool {
        if (dr < 0 || dc < 0 || dr >= n || dc >= m)return true;
        if (g[dr][dc] == 'X')return true;
        if (abs(dr - z1.first) + abs(dc - z1.second) <= 2 * steps) return true;
        if (abs(dr - z2.first) + abs(dc - z2.second) <= 2 * steps) return true;
        return false;
    };

    auto makeMove = [&](queue<pii> &$_que, char charac, char target) -> bool {
        int r, c;
        queue<pii> que;
        que.swap($_que);
        while (!que.empty()) {
            tie(r, c) = que.front(), que.pop();
            if (checkInvalid(r, c))continue;
            for (int i = 0; i < 4; i++) {
                int dr = r + dir[i][0];
                int dc = c + dir[i][1];
                if (checkInvalid(dr, dc))continue;
                if (g[dr][dc] == charac)continue;
                if (g[dr][dc] == target) return true;
                g[dr][dc] = charac;
                $_que.emplace(dr, dc);
            }
        }
        return false;
    };

    while (t_que.empty() == false || s_que.empty() == false) {
        steps++;
        if (makeMove(s_que, 'M', 'G'))return steps;
        if (makeMove(s_que, 'M', 'G'))return steps;
        if (makeMove(s_que, 'M', 'G'))return steps;
        if (makeMove(t_que, 'G', 'M'))return steps;
    }

    return -1;
}

void solve(int kaseId = -1) {
    int n = 0, m = 0;
    vector<pii> st(2);
    vector<pii> z;
    cin >> n >> m;
    vector<string> g(n, string(m, 0));
    for (int i = 0; i < n; ++i) {
        while (cin.peek() == '\n' || cin.peek() == ' ')cin.get();
        for (int j = 0; j < m; ++j) {
            g[i][j] = cin.get();
            if (g[i][j] == 'M') st[0] = make_pair(i, j);
            if (g[i][j] == 'G') st[1] = make_pair(i, j);
            if (g[i][j] == 'Z') z.emplace_back(i, j);
        }
    }
//    debug(g);
    int ans = bfs(g, n, m, st[0], st[1], z[0], z[1]);
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

3
5 6
XXXXXX
XZ..ZX
XXXXXX
M.G...
......
5 6
XXXXXX
XZZ..X
XXXXXX
M.....
..G...
10 10
..........
..X.......
..M.X...X.
X.........
.X..X.X.X.
.........X
..XX....X.
X....G...X
...ZX.X...
...Z..X..X

 */