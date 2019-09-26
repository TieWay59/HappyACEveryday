/*
 * https://codeforces.com/contest/1216/problem/F
 *
 */
#include <bits/stdc++.h>

#define  _debug(x) cerr<<#x << " = " << x<<endl
using namespace std;

typedef long long ll;
const int MOD = -1;
const double eps = 1e-3;
const int MAXN = 4e5 + 59;
const ll INF = 0x3f3f3f3f3f3f3f;

int kase;
int n, m, k;

char s[MAXN];
ll l[MAXN];
ll dp[MAXN];
ll ans = INF;


ll a[MAXN << 2];

#define lson oo<<1
#define rson oo<<1|1

inline void build(int oo, int l, int r) {
    if (l == r) {
        a[oo] = INF;
        return;
    }
    a[oo] = min(a[lson], a[rson]);
}

inline void update(int oo, int l, int r, int pos, ll val) {
    if (l == r && r == pos) {
        a[oo] = val;
        return;
    }
    int m = (l + r) >> 1;
    if (pos <= m)update(lson, l, m, pos, val);
    else update(rson, m + 1, r, pos, val);
    a[oo] = min(a[lson], a[rson]);
}


inline ll query(int oo, int l, int r, int L, int R) {
    if (l > r) {
        _debug("ERROR");
        return INF;
    }

    if (L <= l && r <= R) {
        return a[oo];
    }

    int m = (l + r) >> 1;
    if (R <= m)return query(lson, l, m, L, R);
    else if (m < L) return query(rson, m + 1, r, L, R);
    else return min(query(lson, l, m, L, R), query(rson, m + 1, r, L, R));
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    cin >> (s + 1);
    m = n + k;
    //build(1, 1, m);

    memset(a, 0x3f, sizeof a);

    for (int i = 1; i <= n; ++i) {
        if (s[i] == '1')
            l[i + k] = i;
    }

    for (ll i = 1, d = 0; i <= m; ++i) {

        if (i <= n)d = i;
        else d = 0;

        dp[i] = dp[i - 1] + d;

        if (l[i]) {

            if (i - k - k - 1 <= 0) {
                dp[i] = l[i];
            } else {
                ll tmp = query(1, 1, m, max(1ll, i - k - k - 1), i);
                dp[i] = min(dp[i], tmp + l[i]);
            }

        }

        update(1, 1, m, i, dp[i]);

        if (i >= n)ans = min(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}
