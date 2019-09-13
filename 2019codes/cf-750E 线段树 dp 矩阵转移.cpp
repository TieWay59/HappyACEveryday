/*
*  https://codeforc.es/problemset/problem/750/E
*
*/
//#include <bits/stdc++.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>

#define  _debug(x) cerr<<#x<<" = "<<x<<endl
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 59; //todo change the size

const int MAXM = 2e6 + 59;
const ll MOD = 998244353;
const ll INF = 0x0f0f0f0f;


struct Matrix {
    int mat[5][5]{};

    Matrix() = default;

    void init(int _r, int _c) { memset(mat, 0, sizeof mat); }

    int operator()(const int &_r, const int &_c) const {
        return this->mat[_r][_c];
    }

    void operator()(const int &_r, const int &_c, const int &v) {
        //_debug(this->mat.size());
        this->mat[_r][_c] = v;
    }

    Matrix operator*(const Matrix &rht) {

        int n = 5;
        Matrix &lft = *this;
        Matrix ret;
        //ret.init(5, 5);
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

//    void show() {
//        for (int _r = 0; _r < 5; ++_r) {
//            for (int _c = 0; _c < 5; ++_c) {
//                if (mat[_r][_c] < INF)cout << mat[_r][_c] << "\t";
//                else cout << "INF\t";
//            }
//            cout << endl;
//        }
//    }
};

int n, q;
char s[MAXN];


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

    int M = (l + r) >> 1;
    Matrix ret;
    if (R <= M)ret = query(lson, l, M, L, R);
    else if (M < L)ret = query(rson, M + 1, r, L, R);
    else ret = query(lson, l, M, L, R) * query(rson, M + 1, r, L, R);
    return ret;
}


Matrix a[10], tmp, ans;

/*


 */


int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);

    vector<int> index = {2, 0, 1, 7, 6, 3, 4, 5, 8, 9};
    for (int i = 0, j = 0; i < 10; i++) {
        j = index[i];
        memset(a[j].mat, INF, sizeof a[j].mat);
        for (int k = 0; k < 5; k++) {
            a[j].mat[k][k] = (i == k);
            if (i == k && k < 4)a[j].mat[k][k + 1] = 0;
        }
        //a[j].show();
    }
//    tmp = a[3];
    a[6].mat[3][3] = 1;
    //memset(tmp.mat, 0, sizeof(tmp.mat));
//    for (int m = 0; m < 5; ++m) {
//        tmp.mat[m][m] = 0;
//
//    }
    tmp = a[3];
//    ans = tmp * a[2] * a[0] * a[1] * a[6] * a[6] * a[7] * a[6] * a[6];
//    ans.show();


    scanf("%d%d%s", &n, &q, s);
//    cin >> n >> q >> s;

    for (int i = 0, j; i < n; i++) {
        j = s[i] - '0';
        update(1, 1, n, i + 1, a[j]);
    }

    int l, r, out;
    while (q--) {
//        cin >> l >> r;
        scanf("%d%d", &l, &r);
        ans = tmp * query(1, 1, n, l, r);
        //ans.show();
        if (ans(0, 4) < INF)out = ans(0, 4);
        else out = -1;
//        cout << out << endl;
        printf("%d\n", out);
    }

    return 0;
}