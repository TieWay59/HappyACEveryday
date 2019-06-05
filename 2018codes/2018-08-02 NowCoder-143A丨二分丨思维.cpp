/** https://www.nowcoder.com/acm/contest/143/A
  * ���⣺ȥ��k����Ŀ�������ܴﵽ�������
  * ˼·�����֣����������ʽҪ��һ��ȥ˼��
  * ��˼���о��Զ��ֻ��������Ȳ�����Ӧ���ص�ȥ�Ӵ�һ�¶��ֵ�����
  */

#include <bits/stdc++.h>

#define rep(i, a, b) for(int i=a;i<=b;i++)
using namespace std;
const int N = 1e5 + 15;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const double upp = 1e5;
int n, k;

struct node {
    int s, c;
    double t;

    bool operator<(const node &x) const { return t < x.t; }
} a[N];

bool check(double m) {
    double ret = 0;
    rep(i, 1, n)a[i].t = a[i].s * (a[i].c - m);

    sort(a + 1, a + n + 1);

    rep(i, k + 1, n)ret += a[i].t;
    return ret > eps;//�����Ƿ�����
}

int main() {
    scanf("%d%d", &n, &k);
    rep(i, 1, n)scanf("%d", &a[i].s);
    rep(i, 1, n)scanf("%d", &a[i].c);

    double l = 0, r = upp, m;
    while (r - l > eps) {
        m = (l + r) / 2.0;
        if (check(m))l = m;//����״̬�˾ͼ������ӷ���
        else r = m;//�޷�����ͽ��ͷ���
    }
    printf("%.8f\n", m);

    return 0;
}
/**
3 1
1 2 3
3 2 1
*/



