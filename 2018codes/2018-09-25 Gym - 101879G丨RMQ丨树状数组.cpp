#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;
const int N = 200005 << 2;//
int n, q;
char op[8];
int a[N], tr1[N];
int b[N], tr2[N];

inline int lowbit(int x) { return x & -x; }

/** ��״�������������ֵ��
    ������ʱ��Ϊ�˷��㣬��Сֵ��ֱ��ȡ�����ˡ�
    ò�ƻ�û�кܺõĸĳ���Сֵ�İ취����

    ˼·��������Щ����������߽磬����С�ұ߽�
*/
void update1(int x) {
    while (x <= n) {
        tr1[x] = a[x];
        for (int i = 1; i < lowbit(x); i <<= 1)
            tr1[x] = max(tr1[x], tr1[x - i]);
        x += lowbit(x);
    }
}

int query1(int l, int r) {
    int ret = -0x3f3f3f3f;
    while (l <= r) {
        ret = max(ret, a[r]);
        for (--r; l <= r - lowbit(r); r -= lowbit(r))
            ret = max(ret, tr1[r]);
    }
    return ret;
}

void update2(int x) {
    while (x <= n) {
        tr2[x] = b[x];
        for (int i = 1; i < lowbit(x); i <<= 1)
            tr2[x] = max(tr2[x], tr2[x - i]);
        x += lowbit(x);
    }
}

int query2(int l, int r) {
    int ret = -0x3f3f3f3f;
    while (l <= r) {
        ret = max(ret, b[r]);
        for (--r; l <= r - lowbit(r); r -= lowbit(r))
            ret = max(ret, tr2[r]);
    }
    return -ret;
}

int main() {
    //memset(b,0x80,sizeof b);
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &a[i], &b[i]);
        b[i] = -b[i];
        update1(i);
        update2(i);
    }
    while (q--) {
        int i, l, r;
        long long ans = 0;
        scanf("%s", op);
        if (op[0] == '?') {
            scanf("%d %d", &l, &r);
            //printf("[%d %d]\n",query1(l,r),query2(l,r));
            long long L = 1ll * query1(l, r);
            long long R = 1ll * query2(l, r);
            if (L > R)puts("0");
            else printf("%lld\n", R - L + 1);
        } else {
            scanf("%d%d%d", &i, &l, &r);
            a[i] = l;
            b[i] = -r;
            update1(i);
            update2(i);
        }
    }
    return 0;
}
/*

*/



