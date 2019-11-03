#include <bits/stdc++.h>
#include <tuple>
//https://codeforces.com/gym/101196/my
#define  debug(x)  cerr <<#x << " = "<<x<<endl
const int MAXN = 100 + 59;
using namespace std;

typedef long long ll;

int dir[4][2] = {
        {1,  0},
        {-1, 0},
        {0,  1},
        {0,  -1}
};

int n, m;
pair<int, int> A, B;
char mp[MAXN][MAXN];
bool isEdge[MAXN][MAXN];
char loopType[MAXN][MAXN];
bool vis[MAXN][MAXN];

void visit(int r, int c) { vis[r][c] = true; }

void dfsEdge(int r, int c) {
    vis[r][c] = true;
    for (int i = 0; i < 4; ++i) {
        int dr = r + dir[i][0];
        int dc = c + dir[i][1];
        if (dr < 0 || dc < 0 || dr > n + 1 || dc > m + 1)
            continue;
        if (vis[dr][dc])
            continue;
        if (mp[dr][dc] != '.') {
            isEdge[dr][dc] = true;
            vis[dr][dc] = true;
            continue;
        }
        dfsEdge(dr, dc);
    }
}

void dfsLoop(int r, int c, int rd, int cd, char ch) {
    if (mp[r + 1][c] != '.' &&
        mp[r][c + 1] != '.' &&
        mp[r - 1][c] != '.' &&
        mp[r][c - 1] != '.' &&
        !vis[r + rd][c + cd]) {
        dfsLoop(r + rd, c + cd, rd, cd, ch);
        return;
    }
    visit(r, c);
    loopType[r][c] = ch;

    for (int i = 0; i < 4; ++i) {
        int dr = r + dir[i][0];
        int dc = c + dir[i][1];
        if (dr < 0 || dc < 0 || dr > n + 1 || dc > m + 1)
            continue;
        if (vis[dr][dc] || mp[dr][dc] == '.')
            continue;
        dfsLoop(dr, dc, dir[i][0], dir[i][1], ch);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    memset(mp, '.', sizeof(mp));
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> (mp[i] + 1);
        mp[i][m + 1] = '.';
        for (int j = 1; j <= m; ++j) {
            if (mp[i][j] == 'A') {
                A = {i, j};
            }
            if (mp[i][j] == 'B') {
                B = {i, j};
            }
        }
    }

    dfsEdge(0, 0);

//    for (int i = 0; i <= n + 1; i++) {
//        for (int j = 0; j <= m + 1; j++) {
//            cout << (int) isEdge[i][j];
//        }
//        cout << endl;
//    }

    memset(vis, 0, sizeof vis);
    dfsLoop(A.first, A.second, 0, 0, 'A');
    dfsLoop(B.first, B.second, 0, 0, 'B');

    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= m + 1; j++) {
            cout << loopType[i][j];
        }
        cout << endl;
    }

    return 0;
}
/*
6
Balaji David Alex Scott Andrew Ravi
WWBBWWBBWW
 */