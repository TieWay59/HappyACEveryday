#include <bits/stdc++.h>

using namespace std;
//����ʱ����������x
typedef long long ll;
const int N = 2e5 + 7;
const ll mod = 998244353;
ll fac[N], inv[N], invf[N];
struct node {
    int p, t, v;
} a[N];

inline ll C(int n, int m) {
    ll ret = fac[n] * invf[m] % mod * invf[n - m] % mod;
    return ret;
}

ll calc(const node &x, int l, int r, int t) {
    if (r < x.p)return 0;//ÿ��if���ڼ�鱻�����������Ƿ����ѯ�ʵ�����
    int gap = t - x.t + 1;
    int ret = C(r - x.p + gap, gap);
    if (l > x.p)//l�ȱ��޸ĵ�λ�ÿ���һ�㣬������Ҫ��ȥһ�㡣
        ret -= C(l - x.p - 1 + gap, gap);
    return ret * x.v % mod;//����ϵ��������
}

int main() {
    fac[0] = 1;
    for (int i = 1; i < N; i++)
        fac[i] = fac[i - 1] * i % mod;
    inv[1] = 1;
    for (int i = 2; i < N; i++)
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    invf[0] = 1;
    for (int i = 1; i < N; i++)
        invf[i] = invf[i - 1] * inv[i] % mod;

    int T, n, m, l, r, w, op, now = 0, cnt = 0;
    ll ans;
    scanf("%d", &T);
    while (T--) {
        now = 0, cnt = 0;
        scanf("%d%d", &n, &m);

        while (m--) {
            scanf("%d", &op);
            if (op == 1) {
                scanf("%d%d%d", &l, &r, &w);
                a[cnt++] = {l, now, w};//ÿ�μ�¼λ�ã���ǰ׺�������ۼ���
                a[cnt++] = {r + 1, now, -w};//���Ҷ������ֵȡ�������£��ʹ����˼�ȥ
            } else if (op == 2) {
                now++;
            } else if (op == 3) {
                scanf("%d%d", &l, &r);
                ans = 0;
                for (int i = 0; i < cnt; i++)//�������1��������������
                    ans = (ans + calc(a[i], l, r, now) + mod) % mod;
                printf("%lld\n", ans);
            }
        }
    }
    return 0;
}
/*
1
100000 7
1 1 3 1
2
3 2333 6666
2
3 2333 6666
2
3 2333 6666
*/
