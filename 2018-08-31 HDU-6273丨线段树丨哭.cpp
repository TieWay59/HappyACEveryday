/*http://acm.hdu.edu.cn/showproblem.php?pid=6273
����Ŀ��pdf��
�߶����һ�����������Ҳ���Ķ����ⱾӦ����˫���Ŀ��֣�Ϊʲô���������أ�
�����������õ��߶���ģ����˴�bug��
��л�����Ŀ���Ҹĳ���Ƿ���µĴ�bug��
�ܼ򵥣�һ�����飬�������2��3��ȫ����gcd
�߶���ά��2��3�����ٴ������ɡ�
*/
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 410005;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;
int tree[2][N], add[2][N], L, R, I;
int T, n, m;

ll fpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1)res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void PushDown(int root) {
    //???
    tree[I][root << 1] += add[I][root];
    add[I][root << 1] += add[I][root];
    tree[I][root << 1 | 1] += add[I][root];
    add[I][root << 1 | 1] += add[I][root];
    add[I][root] = 0;
}

void update(int root, int l, int r, int v) {
    if (r < L || R < l)return;
    else if (L <= l && r <= R) {
        add[I][root] += v;
        tree[I][root] += v;
        return;
    }
    if (add[I][root])PushDown(root);
    int m = l + r >> 1;
    update(root << 1, l, m, v);
    update(root << 1 | 1, m + 1, r, v);
    tree[I][root] = min(tree[I][root << 1], tree[I][root << 1 | 1]);
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        memset(tree, 0, sizeof tree);
        memset(add, 0, sizeof add);
        while (m--) {
            scanf("%d%d%d", &L, &R, &I);
            I &= 1;
            update(1, 1, n, 1);
        }
        ll two = tree[0][1];
        ll thr = tree[1][1];
        printf("%lld\n", fpow(2, two) * fpow(3, thr) % mod);
    }
    return 0;
}
/*
2
5 3
1 3 2
3 5 2
1 5 3
6 3
1 6 3
1 6 2
1 6 2
*/
