/*
 * 线段树
 *  https://ac.nowcoder.com/acm/contest/946/D
 */
#include <bits/stdc++.h>

#define  _debug(x) cerr<<#x<<" = "<<x<<endl


using namespace std;
const int MAXN = 1e3 + 5;
const int INF = 2005;
const int MOD = 1e9 + 7;
typedef long long ll;

class SegTree {
private:
    int size;
    vector<ll> tr;
    vector<ll> lz;

    inline void pushDown(const int &oo) {
        if ((oo << 1) <= (size << 2)) {
            lz[oo << 1] = (lz[oo << 1] + lz[oo]) % MOD;
            tr[oo << 1] = (tr[oo << 1] + lz[oo]) % MOD;
        }

        if ((oo << 1 | 1) <= (size << 2)) {
            lz[oo << 1 | 1] = (lz[oo << 1 | 1] + lz[oo]) % MOD;
            tr[oo << 1 | 1] = (tr[oo << 1 | 1] + lz[oo]) % MOD;
        }
        lz[oo] = 0;
    }

    void SegUpdate(const int &oo, const int &st, const int &ed, const int &L, const int &R, const ll &Val) {
        if (ed < L || R < st || st > ed)return;
        if (L <= st && ed <= R) {
            tr[oo] = (tr[oo] + Val) % MOD;
            lz[oo] = (lz[oo] + Val) % MOD;
            return;
        }

        if (lz[oo] > 0)pushDown(oo);

        int m = (st + ed) >> 1;
        SegUpdate(oo << 1, st, m, L, R, Val);
        SegUpdate(oo << 1 | 1, m + 1, ed, L, R, Val);
        tr[oo] = (tr[oo << 1] + tr[oo << 1 | 1]) % MOD;
    }

    ll SigQuery(const int &oo, const int &st, const int &ed, const int &Pos) {
        if (st == ed && ed == Pos)return tr[oo];

        if (lz[oo] > 0)pushDown(oo);

        int m = (st + ed) >> 1;
        if (Pos <= m)return SigQuery(oo << 1, st, m, Pos);
        else return SigQuery(oo << 1 | 1, m + 1, ed, Pos);
    }

public:
    void init(const int &n) {
        this->size = n;
        tr.resize((n + 5) << 3, 0);
        lz.resize((n + 5) << 3, 0);
    }

    void Update(const int &l, const int &r, const ll &v) {
        SegUpdate(1, 1, size, l, r, v);
    }

    ll Query(const int &p) {
        return SigQuery(1, 1, size, p);
    }
};

struct Operation {
    int tp, l, r;
};

SegTree arr, opt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    arr.init(n);
    opt.init(m);
    vector<Operation> a(m);
    opt.Update(1, m, 1);

    for (auto &ai:a) {
        cin >> ai.tp >> ai.l >> ai.r;
    }

    for (int id, l, r, i = m - 1; i >= 0; i--) {
        l = a[i].l;
        r = a[i].r;
        id = i + 1;
        if (a[i].tp == 1) {
            arr.Update(l, r, opt.Query(id));
        } else {
            opt.Update(l, r, opt.Query(id));
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << arr.Query(i) << " \n"[i == n];
    }

    return 0;
}
/*
4 4
1 1 4
2 1 1
2 1 2
2 1 3

 100000 5
1 1 100000
2 1 1
2 1 2
1 1 99999
2 1 4
 */