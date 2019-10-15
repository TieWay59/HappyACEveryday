#include <bits/stdc++.h>

#define  _debug(x) cerr<<#x << " = " << x<<endl
using namespace std;

typedef long long ll;
//typedef _int128 lll;
const double eps = 1e-3;
const int MAXN = 1e5 + 59;
const ll MOD = 1e9 + 7;
const int MAXM = 2e4 + 59;
const int INF = 0x3f3f3f3f;
const ll INFll = 0x3f3f3f3f3f3f3f;

map<int, int> dsc;
//int csd[MAXN << 1];

#define lson (oo<<1)
#define rson (oo<<1|1)
int tr[MAXN << 3];

void update(int oo, int l, int r, int pos, int val) {
    if (l == r && r == pos) {
        tr[oo] += val;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) update(lson, l, mid, pos, val);
    else update(rson, mid + 1, r, pos, val);
    tr[oo] = tr[lson] + tr[rson];
}

int query(int oo, int l, int r, int L, int R) {
    if (L <= l && r <= R) {
        return tr[oo];
    }

    int mid = (l + r) >> 1;
    if (mid >= R)
        return query(lson, l, mid, L, R);
    else if (mid < L)
        return query(rson, mid + 1, r, L, R);
    else
        return query(lson, l, mid, L, R)
               + query(rson, mid + 1, r, L, R);
}


struct node {
    int x, t, v, i;

    bool operator<(const node &rht) const {
        if (x == rht.x) {
            return t < rht.t;
        }
        return x < rht.x;
    }
} a[MAXN * 3];

int ans[MAXN];

int main() {
    freopen("business.in","r+",stdin);
    int kase;
    int n, m;
    scanf("%d", &kase);
    while (kase--) {
        dsc.clear();
        int tot = 0;
        int maxPos = 0;
        scanf("%d%d", &n, &m);

        for (int i = 1, x, q, r; i <= n; ++i) {
            scanf("%d%d%d", &x, &q, &r);
            dsc[q - x] = 1;
            a[tot++] = {x, 1, q - x, i};
            a[tot++] = {x + r, 3, q - x, i};
        }

        for (int i = 1, y, d; i <= m; ++i) {
            scanf("%d%d", &y, &d);
            dsc[d - y] = 1;
            a[tot++] = {y, 2, d - y, i};
        }

        for (auto &di:dsc) {
            di.second = ++maxPos;
//            csd[maxPos] = di.first;
        }

        for (int j = 0; j < tot; ++j) {
            a[j].v = dsc[a[j].v];
        }
        sort(a, a + tot);

//        _debug(maxPos);
        for (int i = 0; i < tot; ++i) {
//            _debug(a[i].v);
//            _debug(a[i].x);
//            _debug(a[i].t);
//            _debug(a[i].i);
//            _debug(i);
//            _debug("                                           ");
            if (a[i].t == 1) {
                update(1, 1, maxPos, a[i].v, 1);
            } else if (a[i].t == 2) {
                ans[a[i].i] = query(1, 1, maxPos, a[i].v, maxPos);
            } else if (a[i].t == 3) {
                update(1, 1, maxPos, a[i].v, -1);
            }

//            for (int j = 1; j <= maxPos; j++) {
//                printf("%d%c", query(1, 1, maxPos, j, j), " \n"[j == maxPos]);
//            }
        }

        for (int i = 1; i <= m; ++i) {
            printf("%d%c", ans[i], " \n"[i == m]);
        }
    }
}
/*

2
3 3
1 2
2 3
3 1
6 6
1 2
2 3
3 1
2 4
4 5
5 2

 */
