#include<bits/stdc++.h>

using namespace std;
const int N = 100002 << 2;
int a[N], b[N];
int tree[N], amax[N], bmin[N], add[N];
int n, q, L, R;
char op[15];

/*
*/

void PushUp(int root) {
    tree[root] = tree[root << 1] + tree[root << 1 | 1];
    amax[root] = max(amax[root << 1], amax[root << 1 | 1]);
    bmin[root] = min(bmin[root << 1], bmin[root << 1 | 1]);
}

int build(int root, int l, int r) {
    add[root] = 0;
    if (l == r) {
        tree[root] = 0;
        amax[root] = a[l];
        bmin[root] = b[l];
    } else {
        int m = (l + r) >> 1;
        build(root << 1, l, m);
        build(root << 1 | 1, m + 1, r);

        PushUp(root);
    }
}

void PushDown(int root) {//unchecked
    if (!add[root])return;

    if (root << 1 <= n) {
        amax[root << 1] += add[root];
        add[root << 1] += add[root];
    }
    if (root << 1 | 1 <= n) {
        amax[root << 1 | 1] += add[root];
        add[root << 1 | 1] += add[root];
    }
    add[root] = 0;
}

int query(int root, int l, int r) {
    if (r < L || R < l)return 0;
    else if (L <= l && r <= R)return tree[root];

    PushDown(root);
    int m = (l + r) >> 1;
    return query(root << 1, l, m) + query(root << 1 | 1, m + 1, r);
}

void update(int root, int l, int r, int v) {
    //printf("[%d-%d]\n",l,r);
    if (r < L || R < l)return;
    else if (L <= l && r <= R) {
        amax[root] += v;
        if (amax[root] < bmin[root]) {
            add[root] += v;
            return;
        }
        if (l == r && amax[root] >= bmin[root]) {
            tree[root]++;//确保了1
            bmin[root] += b[l];
            return;
        }
    }

    PushDown(root);
    int m = (l + r) >> 1;
    update(root << 1, l, m, v);
    update(root << 1 | 1, m + 1, r, v);
    PushUp(root);
}

int main() {
    while (scanf("%d%d", &n, &q) != EOF) {
        memset(a, 0, sizeof a);
        for (int i = 1; i <= n; i++)
            scanf("%d", &b[i]);
        build(1, 1, n);

        while (q--) {
            scanf("%s %d %d", op, &L, &R);
            if (op[0] == 'q')
                printf("%d\n", query(1, 1, n));
            else
                update(1, 1, n, 1);
            //puts("OK");
        }
    }
    return 0;
}
/*
5 12
1 5 2 4 3
add 1 4
add 2 5
add 3 5
add 2 4
query 1 4
add 2 5
query 2 5
add 2 2
query 1 5

*/
