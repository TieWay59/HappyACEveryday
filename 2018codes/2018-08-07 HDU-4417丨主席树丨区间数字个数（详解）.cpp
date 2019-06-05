/*
���ȣ��Ҷ��������������
������У���Ŀ����һ�����У���ʾĳ�ض����壬���¼�����У�
�������У�������Ͱ�����˼�룬�����У����ܾ�����ɢ����
���뵽1-n�������У����ڽ�����ϯ����ͳ�ƣ����¼�����С�

�ҵ�����ֻ�Ǹ�������������������߶������ϯ�����а�����

���涨������������ϯ���Ļ�������
Update(int l,int r,int last,int &now)

*/
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
#define MAXN 100010

int root[MAXN], tcnt;
int ls[MAXN * 17], rs[MAXN * 17], sum[MAXN * 17];

void update(int l, int r, int pre, int &cur, int pos) {
    cur = ++tcnt;
    if (l == r)//����Ѿ�����Ҷ�ӽڵ㣬����ǰһ��ת����+1
    {
        sum[cur] = sum[pre] + 1;
        return;
    }
    ls[cur] = ls[pre];//�̳�ǰ״̬˫�׵����ӱ��
    rs[cur] = rs[pre];//�̳�ǰ״̬˫�׵��Һ��ӱ��

    int mid = l + r >> 1;//�������Һ��ӣ��������pos��1-n���������ĸ�����
    if (pos <= mid)update(l, mid, ls[pre], ls[cur], pos);//�������Ӧ���õ��޸�
        //ͬʱ����lch[pre]��Ϊ�˴��ݴ���ͬһ������ڵ��ǰ��״̬
    else update(mid + 1, r, rs[pre], rs[cur], pos);

    sum[cur] = sum[ls[cur]] + sum[rs[cur]];
    //���Ӹ�����Ϻ󣬸���˫�׵�sum
    //�õ�b��ָ������[l,r]�� ������a[1~l]�����ָ��� �ڵ�ǰ״̬�µ����
}

int query(int l, int r, int old, int nuw, int h)//new����ռ��QAQ
{//ѯ��ԭ������(old,nuw]С��h�����ָ���
    if (0 > h)return 0;
    if (0 <= l && r <= h)//��ǰ��������[l,r]�ĵ㶼С�ڵ���h
        return sum[nuw] - sum[old];
    //nuw״̬����������ָ�����ȥoldʱ������������ܺ�
    //Ҳ����ԭ����(old,nuw]�ڣ�����С��h���������ָ���

    int mid = l + r >> 1, ret = 0;//�������������[0,h]�н�������һ��ѯ��
    if (0 <= mid) ret += query(l, mid, ls[old], ls[nuw], h);
    if (h > mid) ret += query(mid + 1, r, rs[old], rs[nuw], h);
    return ret;//����ͳ������
}

int dsc[MAXN], dcnt;//discrete
int a[MAXN];

int main() {
    int n, m, t;
    scanf("%d", &t);
    for (int kase = 1; kase <= t; kase++) {
        printf("Case %d:\n", kase);
        scanf("%d%d", &n, &m);
        dcnt = 0;

        for (int i = 1; i <= n; i++) {
            scanf("%d", a + i);
            dsc[dcnt++] = a[i];//��ɢ������1��¼
        }

        sort(dsc, dsc + dcnt);//��ɢ������2����
        dcnt = unique(dsc, dsc + dcnt) - dsc;//��ɢ������3ȥ��
        tcnt = 0;

        for (int x, i = 1; i <= n; i++) {
            x = lower_bound(dsc, dsc + dcnt, a[i]) - dsc;
            update(0, dcnt - 1, root[i - 1], root[i], x);
        }

        int old, nuw, h;
        while (m--) {
            scanf("%d%d%d", &old, &nuw, &h);
            old++, nuw++;
            h = upper_bound(dsc, dsc + dcnt, h) - dsc - 1;
            //�����ҵ���һ������h�������±꣬��ȥ1����������С�ڵ���h���±�
            //������ɢ���±꣬ȥ���Ҹ���(ע���п����Ҳ������ڵ�λ�ã�h����-1��)
            printf("%d\n", query(0, dcnt - 1, root[old - 1], root[nuw], h));
        }
    }
    return 0;
}

