/*http://acm.hdu.edu.cn/showproblem.php?pid=6447
��һ���Ƚ��ۺϵ���Ŀ��ɢ��+dp+��״����
��������
*/

#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;
#define ll long long
const int N = 200005;//��״���鿪����������
const int INF = 1e9 + 7;
int kase, n;

struct Point {
    int x, y, w;

    void read() {
        scanf("%d%d%d", &x, &y, &w);
    }

    bool operator<(const Point &a) const {
        return x == a.x ? y > a.y : x < a.x;//
    }
} poi[N];

int hashx[N], hashy[N];
int cntx, cnty;

void disc() {
    for (int i = 1; i <= n; ++i) {
        hashx[i] = poi[i].x;
        hashy[i] = poi[i].y;
    }
    //sort(hashx+1,hashx+1+n);//x��ʵ�Ѿ�����
    sort(hashy + 1, hashy + 1 + n);
    cntx = unique(hashx + 1, hashx + 1 + n) - hashx;
    cnty = unique(hashy + 1, hashy + 1 + n) - hashy;
    for (int i = 1; i <= n; ++i) {
        poi[i].x = lower_bound(hashx + 1, hashx + 1 + cntx, poi[i].x) - hashx;
        poi[i].y = lower_bound(hashy + 1, hashy + 1 + cnty, poi[i].y) - hashy;
    }
}

int dp[N], tr[N];

inline int lowbit(int x) { return x & -x; }

void update(int x) {
    while (x <= n) {
        tr[x] = dp[x];
        for (int i = 1; i < lowbit(x); i <<= 1)
            tr[x] = max(tr[x], tr[x - i]);
        x += lowbit(x);
    }//��״���飬ά���������ֵ
}

int query(int l, int r) {
    int ret = 0;
    while (l <= r) {
        ret = max(ret, dp[r]);
        for (--r; l <= r - lowbit(r); r -= lowbit(r))
            ret = max(ret, tr[r]);
    }//���ѭ���ͱȽ����棬һ��ʼfor������״��������������䣬
    //���while������С������õ��𰸣�����ʱ�䲻�Ǻ��Ż������������
    return ret;
}

int main() {
    scanf("%d", &kase);
    while (kase--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            poi[i].read();
        sort(poi + 1, poi + 1 + n);
        disc();
        int cur = 1;
        memset(tr, 0, sizeof(tr));
        memset(dp, 0, sizeof(dp));

        while (cur <= n) {
            Point p = poi[cur];
            dp[p.y] = max(dp[p.y], query(1, p.y - 1) + p.w);
            //�����query��ʵ�������Ż�����Ϊ���Ǵ�1��ʼ�ġ�
            update(p.y);
            cur++;
        }
        printf("%d\n", query(1, cnty));
    }
    return 0;
}
