#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 100005;
ll a[N], b[N], tree[N << 2], add[N << 2], L, R;
int n, q;

void build(int root, int l, int r) {
    add[root] = 0;
    if (l == r) {
        tree[root] = a[l];
    } else {
        int m = l + r >> 1;
        build(root << 1, l, m);
        build(root << 1 | 1, m + 1, r);
        tree[root] = tree[root << 1] + tree[root << 1 | 1];
    }
}

void PushDown(int root, int l, int r) {
    int m = (l + r) / 2;
    tree[root << 1] += add[root] * (m - l + 1);//!!!
    add[root << 1] += add[root];
    tree[root << 1 | 1] += add[root] * (r - (m + 1) + 1);
    add[root << 1 | 1] += add[root];
    add[root] = 0;
}

ll query(int root, int l, int r) {
    if (r < L || R < l)return 0;
    else if (L <= l && r <= R)return tree[root];

    PushDown(root, l, r);
    int m = l + r >> 1;
    return query(root << 1, l, m) + query(root << 1 | 1, m + 1, r);
}

void update(int root, int l, int r, ll v) {
    if (r < L || R < l)return;
    else if (L <= l && r <= R) {
        add[root] += v;
        tree[root] += v * (r - l + 1);
        return;
    }
    PushDown(root, l, r);
    int m = l + r >> 1;
    update(root << 1, l, m, v);
    update(root << 1 | 1, m + 1, r, v);
    tree[root] = tree[root << 1] + tree[root << 1 | 1];
}

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", b + i);
        a[i] = a[i - 1] + b[i];
    }
    build(1, 1, n);
    while (q--) {
        int op, x, y;
        scanf("%d%d%d", &op, &x, &y);
        if (op == 1) {

            L = x, R = y;
            ll ans = query(1, 1, n);

            if (x != 1) {
                L = x - 1, R = x - 1;
                ans -= (y - x + 1) * query(1, 1, n);
            }
            printf("%lld\n", ans);

        } else {
            L = x, R = n;
            update(1, 1, n, y - b[x]);
            b[x] = y;
        }
    }
    return 0;
}
/*
5 100
1 2 3 4 5
2 1 0
1 1 5
*/
