/*
 *
 * src: https://codeforces.com/gym/101808/problem/D
 * use: 状压dp
 *
 *
 */
#define _debug(x) cerr<<#x<<" = "<<(x)<<endl;fflush(stdout)

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1 << 18;
const int inf = 0x3F3F3F3F;
const int mod = 1e9 + 7;

int Kase, n, p;
double p1, p2;
double dp[25][maxn];
double ans[20][105];
int cnt[maxn];

inline int cnt1s(int x) {
    return cnt[x >> 1];
}

inline int lowBit(int x) { return x & -x; }

double dfs(int i, int j) {
    if (i <= 0)return 0;
    if (dp[i][j] > 0)return dp[i][j];
    int nxj, nxi, add;

    if (j & 2) {
        dp[i][j] += dfs(i - 1, 4) * p1;
    } else {
        nxj = j + 4;
        add = ((lowBit(nxj) - 1) & j) << 1;
        nxi = i + cnt1s(j) - cnt1s(nxj);
        dp[i][j] += (dfs(nxi, nxj) + add) * p1;
    }
    nxj = j + 2;
    add = ((lowBit(nxj) - 1) & j) << 1;
    nxi = i + cnt1s(j) - cnt1s(nxj);
    dp[i][j] += (dfs(nxi, nxj) + add) * p2;

    return dp[i][j];
}


int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);

//    cin >> Kase;

    for (int i = 1; i < maxn; ++i) {
        cnt[i] = cnt[i >> 1] + (i & 1);
    }

    for (p = 0; p <= 100; ++p) {
        memset(dp, 0, sizeof dp);
        p1 = p / 100.0;
        p2 = 1 - p / 100.0;
        for (int i = 1; i <= 16; ++i) {
            ans[i][p] = dfs(i, 0);
        }
    }

    scanf("%d", &Kase);
    while (Kase--) {
        scanf("%d %d", &n, &p);
        printf("%.6f\n", ans[n][p]);
    }
    return 0;
}


/*
3
 2 25

 */