#include<bits/stdc++.h>

using namespace std;
const int N = 50000 * 4;
int a[N], tree[N], add[N], L, R;
int Ti, T, n;
char op[15];

/*
�߶����㷨�߼�

build
����ӳٱ��
�����Ҷ�ӽڵ�
    ����Ԫ��
�������Ҷ�ӽڵ�
    build��
    build��
    ����ڵ�ֵ

pushdown
���ҽڵ�ֵ+=add
���ҽڵ��ӳٱ��+=add
��ǰ�ڵ��ӳٱ��=0��


query
����ڵ�������ѯ��������
    ���ز���ȷ��Ϣ
��������ڡ�����
    ֱ�ӷ��ؽڵ���ֵ
pushdown�´��ӳٱ��
����query
����query


update_sg
��ǰ�������� return��
��ǰ�������� �޸Ľڵ�ֵ����return��
��ǰ�����н���
    �´���ǣ����Ҽ������£����¼���ڵ�ֵ��
*/
int build(int root, int l, int r) {
    add[root] = 0;
    if (l == r) {
        tree[root] = a[l];
    } else {
        int m = (l + r) / 2;
        build(root * 2, l, m);
        build(root * 2 + 1, m + 1, r);
        tree[root] = tree[root * 2] + tree[root * 2 + 1];
    }
}

void PushDown(int root, int l, int r) {
    tree[root * 2] += add[root] * (r - l + 1);
    add[root * 2] += add[root];
    tree[root * 2 + 1] += add[root] * (r - l + 1);
    add[root * 2 + 1] += add[root];
    add[root] = 0;
}

int query(int root, int l, int r) {
    if (r < L || R < l)return 0;
    else if (L <= l && r <= R)return tree[root];

    PushDown(root, l, r);
    int m = (l + r) / 2;
    return query(root * 2, l, m) + query(root * 2 + 1, m + 1, r);
    //�����ֱ�����ҿ���������ȥϸ���ˣ���Ϊ�������Ѿ���return0
    //���������������һЩ��
}

void update(int root, int l, int r, int v) {
    if (r < L || R < l)return;
    else if (L <= l && r <= R) {
        add[root] += v;
        tree[root] += v * (l - r + 1);
        return;
    }

    PushDown(root, l, r);
    int m = (l + r) / 2;
    update(root * 2, l, m, v);
    update(root * 2 + 1, m + 1, r, v);
    //ͬ��Ϊ�˼�࣬���ﲻȥϸ��m��LR�Ĺ�ϵ����Ϊ�Ϸ���return��
    tree[root] = tree[root * 2] + tree[root * 2 + 1];
}


int main() {

    Ti = 1;
    scanf("%d", &T);
    while (Ti <= T) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        build(1, 1, n);

        int x, y;
        printf("Case %d:\n", Ti++);
        while (scanf("%s", op) != EOF) {

            if (strcmp(op, "Query") == 0) {
                scanf("%d%d", &L, &R);
                printf("%d\n", query(1, 1, n));
            } else if (strcmp(op, "Add") == 0) {
                scanf("%d%d", &L, &x);
                R = L;
                update(1, 1, n, x);
            } else if (strcmp(op, "Sub") == 0) {
                scanf("%d%d", &L, &x);
                R = L;
                update(1, 1, n, -x);
            } else {
                break;
            }
        }
    }
    return 0;
}
/*
1
10
1 2 3 4 5 6 7 8 9 10
Query 1 3
Add 3 6
Query 2 7
Sub 10 2
Add 6 3
Query 3 10
End

*/
