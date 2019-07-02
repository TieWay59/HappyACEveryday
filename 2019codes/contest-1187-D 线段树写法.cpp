/*
 * https://codeforces.com/contest/1187/problem/D
 *
 */
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>

#define eps 1e-9
#define _debug(x) cerr<<#x<<" = "<<(x)<<endl;fflush(stdout)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 300005;
const int inf = 0x3F3F3F3F;


int n, Kase;
int A[MAXN], B[MAXN];
int iA[MAXN], iB[MAXN];

class SegTree {
private:
    int num = 0;
    int node[MAXN << 2];

    void update(int oo, int s, int e, const int &pos, const int &val) {
        if (s == e && s == pos) {
            node[oo] = val;
            return;
        }
        int m = (s + e) >> 1;
        if (pos <= m)update(oo << 1, s, m, pos, val);
        else update(oo << 1 | 1, m + 1, e, pos, val);
        node[oo] = max(node[oo << 1], node[oo << 1 | 1]);
    }

    int query(int oo, int s, int e, const int &l, const int &r) {
        if (l <= s && e <= r) return node[oo];
        if (e < l || r < s)return 0;
        int m = (s + e) >> 1;
        return max(query(oo << 1, s, m, l, r), query(oo << 1 | 1, m + 1, e, l, r));
    }

public:
    void init(const int &_n) {
        this->num = _n;
        for (int i = 1; i <= num; ++i) {
            update(1, 1, num, i, 0);
        }
    }

    int Query(const int &l, const int &r) {
        return query(1, 1, num, l, r);
    }

    void Update(const int &pos, const int &val) {
        update(1, 1, num, pos, val);
    }

} segTree;


bool solve() {
    cin >> n;
    vector<pii> a(n), b(n);
    int id = 0;
    for (auto &ai:a) {
        cin >> ai.first;
        ai.second = ++id;
    }
    id = 0;
    for (auto &bi:b) {
        cin >> bi.first;
        bi.second = ++id;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for (int i = 0; i < n; ++i) {
        if (a[i].first != b[i].first)
            return false;
        A[a[i].second] = i + 1;
        B[b[i].second] = i + 1;
    }
    for (int i = 1; i <= n; ++i) {
        iA[A[i]] = i;
        iB[B[i]] = i;
    }

    segTree.init(n);
    for (int i = 1; i <= n; ++i) {
        int ia = iA[i];
        int ib = iB[i];
        id = segTree.Query(1, ia - 1);
        if (ib < id) {
            return false;
        }
        segTree.Update(ia, ib);
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> Kase;
    while (Kase--) {
        cout << (solve() ? "YES\n" : "NO\n");
    }
    return 0;
}


/*
3 3
1 0 1
0 0 0
1 0 1
 */