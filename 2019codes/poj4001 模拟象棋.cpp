#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <iostream>

#define  _debug(x) cerr<<#x << " = " << x<<endl
using namespace std;

typedef long long ll;
//typedef _int128 lll;
const int MOD = 0;
const double eps = 1e-3;
const int MAXN = 2e4 + 59;
const int INF = 0x3f3f3f3f;
const ll INFll = 0x3f3f3f3f3f3f3f;

int dir[][2] = {
        {1,  0},
        {-1, 0},
        {0,  -1},
        {0,  1}
};
int dirma[][2] = {
        {2,  1},
        {2,  -1},
        {-2, 1},
        {-2, -1},
        {1,  2},
        {-1, 2},
        {1,  -2},
        {-1, -2}
};
int majiao[][2] = {
        {1,  0},
        {1,  0},
        {-1, 0},
        {-1, 0},
        {0,  1},
        {0,  1},
        {0,  -1},
        {0,  -1}
};

struct node {
    char tp;
    int r, c;
} b, a[11];

int n;
char ch[2];
bool board[15][15];

int cntBetween(int ri, int ci, int rj, int cj) {
    if (ri > rj)swap(ri, rj);
    if (ci > cj)swap(ci, cj);
    int ret = 0;

    if (ri == rj)
        for (int c = ci + 1; c < cj; ++c)
            if (board[ri][c])ret++;

    if (ci == cj)
        for (int r = ri + 1; r < rj; ++r)
            if (board[r][ci])ret++;

    return ret;
}

bool chek(int r, int c) {

    for (int i = 1; i <= n; i++) {
        if (a[i].r == r && a[i].c == c)
            continue;

        switch (a[i].tp) {
            case 'G':
                if ((r == a[i].r || c == a[i].c)
                    && cntBetween(r, c, a[i].r, a[i].c) == 0)
                    return false; // special
                break;
            case 'R':
                if ((r == a[i].r || c == a[i].c)
                    && cntBetween(r, c, a[i].r, a[i].c) == 0)
                    return false;
                break;
            case 'H':
                for (int j = 0; j < 8; j++) {
                    int dr = a[i].r + dirma[j][0];
                    int dc = a[i].c + dirma[j][1];
                    if (dr < 1 || dc < 1 || dr > 10 || dc > 9)
                        continue;
                    int ddr = a[i].r + majiao[j][0];
                    int ddc = a[i].c + majiao[j][1];
                    if (board[ddr][ddc])continue;
//                    _debug(dr);
//                    _debug(dc);
                    if (dr == r && dc == c)
                        return false;
                }
                break;
            case 'C':
                if ((r == a[i].r || c == a[i].c)
                    && cntBetween(r, c, a[i].r, a[i].c) == 1)
                    return false;
                break;
            default:
                exit(0);
                break;
        }
    }
    return true;
}

int main() {
    b.tp = 'G';
    while (scanf("%d%d%d", &n, &b.r, &b.c) != EOF && n + b.r + b.c) {
        memset(board, 0, sizeof board);
        memset(a, 0, sizeof a);

        for (int i = 1; i <= n; ++i) {
            scanf("%s %d %d", ch, &a[i].r, &a[i].c);
            board[a[i].r][a[i].c] = 1;
            a[i].tp = ch[0];
        }

        bool ans = true;
        bool testTg = false;
        for (int i = 1; i <= n; i++) {
            if (a[i].tp == 'G') {
                if ((b.r == a[i].r || b.c == a[i].c)
                    && cntBetween(b.r, b.c, a[i].r, a[i].c) == 0) {
                    testTg = true;
                }
            }
        }

        if (testTg) {
            puts("YES");
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int dr = b.r + dir[i][0];
            int dc = b.c + dir[i][1];

            if (dr < 1 || dc < 4 || dr > 3 || dc > 6)
                continue;

            //check this position valid & safe.
            if (chek(dr, dc)) {
//                _debug(dr);
//                _debug(dc);
                ans = false;
                break;
            }
        }
        if (ans)puts("YES");
        else puts("NO");
    }

    return 0;
}
/*

3 1 4
H 3 2
G 10 5
C 1 5

 */