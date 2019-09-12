/*
 *  https://codeforc.es/problemset/problem/750/E
 *
 */
#include <bits/stdc++.h>
//#include <stdio.h>
//#include <algorithm>

#define  _debug(x) cerr<<#x<<" = "<<x<<endl
using namespace std;
typedef long long ll;
const int MAXN = 1e6 + 59;
const int MAXM = 2e6 + 59;
const ll MOD = 998244353;
const ll INF = 1e6;


class Matrix {
public:
    int r{}, c{};
    vector<vector<int> > mat;

    Matrix() : r(5), c(5) {
        vector<int> t(5, 0);
        for (int i = 1; i <= 5; i++)
            mat.emplace_back(t);
    }

    void init(int _r, int _c) {
        mat.resize(_r);
        for (auto &v:mat) {
            v.resize(_c, 0);
        }
    }

    int operator()(const int &_r, const int &_c) const {

        return this->mat[_r][_c];
    }

    void operator()(const int &_r, const int &_c, const int &v) {
        //_debug(this->mat.size());
        this->mat[_r][_c] = v;
    }

    Matrix operator*(const Matrix &rht) {
        if (c != rht.r || rht.mat[0].empty() || this->mat.empty()) {
            cerr << "error" << endl;
            exit(0);
        }
        int n = c;
        Matrix &lft = *this;
        Matrix ret;
        ret.init(5, 5);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int t = INF;
                for (int k = 0; k < n; ++k) {
                    t = min(t, lft(i, k) + rht(k, j));
                }
                ret(i, j, t);
            }
        }
        return ret;
    }
};

int n, q;
string s;


#define lson o<<1
#define rson o<<1|1

Matrix tree[MAXN << 2];

void update(int o, int l, int r, const int &pos, const Matrix &v) {
    if (l > r)return;
    if (l == r && l == pos) {
        tree[o] = v;
        return;
    }
    int m = (l + r) >> 1;

    if (pos <= m)update(lson, l, m, pos, v);
    else update(rson, m + 1, r, pos, v);
    tree[o] = tree[lson] * tree[rson];
}

Matrix query(int o, int l, int r, const int &L, const int &R) {
    if (L <= l && r <= R)
        return tree[o];
    int m = (l + r) >> 1;
    Matrix ret;
    if (r <= m)ret = query(lson, l, m, L, R);
    else if (m < l)ret = query(rson, m + 1, r, L, R);
    else ret = query(lson, l, m, L, R) * query(rson, m + 1, r, L, R);
    return ret;
}


Matrix a[10], tmp, ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    tmp.mat = {{0,   INF, INF, INF, INF},
               {INF, 0,   INF, INF, INF},
               {INF, INF, 0,   INF, INF},
               {INF, INF, INF, 0,   INF},
               {INF, INF, INF, INF, 0}};
    a[3].mat = {{0,   INF, INF, INF, INF},
                {INF, 0,   INF, INF, INF},
                {INF, INF, 0,   INF, INF},
                {INF, INF, INF, 0,   INF},
                {INF, INF, INF, INF, 0}};
    a[2].mat = {{1,   0,   INF, INF, INF},
                {INF, 0,   INF, INF, INF},
                {INF, INF, 0,   INF, INF},
                {INF, INF, INF, 0,   INF},
                {INF, INF, INF, INF, 0}};
    a[0].mat = {{0,   INF, INF, INF, INF},
                {INF, 1,   0,   INF, INF},
                {INF, INF, 0,   INF, INF},
                {INF, INF, INF, 0,   INF},
                {INF, INF, INF, INF, 0}};
    a[1].mat = {{0,   INF, INF, INF, INF},
                {INF, 0,   INF, INF, INF},
                {INF, INF, 1,   0,   INF},
                {INF, INF, INF, 0,   INF},
                {INF, INF, INF, INF, 0}};
    a[7].mat = {{0,   INF, INF, INF, INF},
                {INF, 0,   INF, INF, INF},
                {INF, INF, 0,   INF, INF},
                {INF, INF, INF, 1,   0},
                {INF, INF, INF, INF, 0}};
    a[6].mat = {{0,   INF, INF, INF, INF},
                {INF, 0,   INF, INF, INF},
                {INF, INF, 0,   INF, INF},
                {INF, INF, INF, 0,   INF},
                {INF, INF, INF, INF, 1}};
    a[4] = a[5] = a[8] = a[9] = a[3];


    cin >> n >> q >> s;

    for (int i = 0, j; i < n; i++) {
        j = s[i] - '0';
        update(1, 1, n, i + 1, a[j]);
    }
    int l, r;
    while (q--) {
        cin >> l >> r;
        ans = tmp * query(1, 1, n, l, r);
        cout << ans(4, 4) << endl;
    }

    return 0;
}

/*


 */
