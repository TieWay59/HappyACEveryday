#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;
const int maxn = 1e5 + 5;
int n, m, cnt, root[maxn], a[maxn], kase, x, y, k;
struct node {
    int l, r, sum;
} T[maxn * 20];
vector<int> v;

int getid(int x) {
    //����ɢ��������6ѽ�����ֲ���vector��Ȼ�󷵻��±꣨��1��ʼҪ+1��
    return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}

void update(int l, int r, int &x, int y, int pos) {
    T[++cnt] = T[y];//��¼ÿ��ǰ׺
    T[cnt].sum++;
    x = cnt;
    if (l == r)return;

    int mid = (l + r) / 2;
    if (mid >= pos)update(l, mid, T[x].l, T[y].l, pos);
    else update(mid + 1, r, T[x].r, T[y].r, pos);
}

int query(int l, int r, int x, int y, int k) {
    if (l == r)return l;
    int mid = (l + r) / 2;
    int sum = T[T[y].l].sum - T[T[x].l].sum;

    if (sum >= k)return query(l, mid, T[x].l, T[y].l, k);
    else return query(mid + 1, r, T[x].r, T[y].r, k - sum);
}

int main() {
    scanf("%d", &kase);
    while (kase--) {
        cnt = 0;
        v.clear();
        memset(T, 0, sizeof T);
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]), v.push_back(a[i]);

        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        //ɾ���ظ�Ԫ�صĲ���

        for (int i = 1; i <= n; i++)
            update(1, n, root[i], root[i - 1], getid(a[i]));

        for (int i = 1; i <= m; i++) {
            scanf("%d%d%d", &x, &y, &k);
            printf("%d\n", v[query(1, n, root[x - 1], root[y], k) - 1]);
        }

    }
    return 0;
}
/*
2
10 1
1 4 2 3 5 6 7 8 9 0
1 3 2

7 3
1 5 2 6 3 7 4
2 5 3
4 4 1
1 7 3
*/
