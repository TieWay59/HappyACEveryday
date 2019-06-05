#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;
const int MAXN = 5e5 + 15;
const int MAXM = 1e7 + 15;

struct node {
    int w, x, y, i;

    bool operator<(const node &t) const {
        if (x != t.x)return x < t.x;
        if (y != t.y)return y < t.y;
        return w < t.w;
    }
} a[MAXN * 5];

int n, m, tot;
int ans[MAXN], cnt[MAXM];

void add(int i) {
    while (i <= MAXM - 5) {
        cnt[i]++;
        i += i & -i;
        if (i <= 1)break;
    }
}

int ask(int i) {
    int res;
    while (i) {
        res += cnt[i];
        i -= i & -i;
    }
    return res;
}

int main() {
    freopen("test.txt", "r", stdin);//����
    scanf("%d %d", &n, &m);
    tot = n;
    //Ϊ�˷�����״���飬yȫ��+2����ֹ����y-1<=0��
    for (int x, y, i = 1; i <= n; i++) {
        scanf("%d %d", &x, &y);
        a[i] = {-2, x, y + 2, 0};
    }
    for (int x1, y1, x2, y2, i = 1; i <= m; i++) {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        y1 += 2, y2 += 2;
        a[++tot] = {+1, x1 - 1, y1 - 1, i};
        a[++tot] = {-1, x1 - 1, y2, i};
        a[++tot] = {-1, x2, y1 - 1, i};
        a[++tot] = {+1, x2, y2, i};
    }
    sort(a + 1, a + 1 + tot);
    for (int i = 1; i <= tot; i++) {
        if (a[i].w != -2)ans[a[i].i] += a[i].w * ask(a[i].y);
        else add(a[i].y);
    }
    for (int i = 1; i <= m; i++)
        printf("%d\n", ans[i]);
    return 0;
}
/*
3 1
0 0
0 1
1 0
0 0 1 1
*/
