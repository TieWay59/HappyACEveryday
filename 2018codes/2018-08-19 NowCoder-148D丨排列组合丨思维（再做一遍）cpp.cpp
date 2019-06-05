/*
https://www.nowcoder.com/acm/contest/148/D
�������Ҫ�����������е��������
http://note.youdao.com/noteshare?id=ec6a41fb2538a76293669ef0e441a92e&sub=3156CCBE9B6943C1ABD5398B0F44F880
*/

#include <bits/stdc++.h>

using namespace std;
//����ʱ����������x
typedef long long ll;
const int N = 2e5 + 7;
const ll mod = 998244353;
int cnt;
int step[N], inv[N], invf[N];
struct Node {
    int pos, val, times;
} a[N];

inline int C(int n, int m) {
    return 1ll * step[n] * invf[n - m] % mod * invf[m] % mod;
}

int calc(const Node &a, int l, int r, int times) {
    if (r < a.pos) return 0;
    int gap = times - a.times;
    int rt = C((r - a.pos) + gap, gap);
    if (l > a.pos)
        rt = (rt - C((l - 1 - a.pos) + gap, gap));
    return 1ll * rt * a.val % mod;
}

int main() {
    step[0] = 1;
    for (int i = 1; i < N; i++)step[i] = 1ll * step[i - 1] * i % mod;
    inv[1] = 1;
    for (int i = 2; i < N; i++)inv[i] = mod - 1ll * mod / i * inv[mod % i] % mod;
    invf[0] = 1;
    for (int i = 1; i < N; i++)invf[i] = 1ll * invf[i - 1] * inv[i] % mod;

    int t, n, m, op, l, r, p, now;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        now = cnt = 0;
        for (int i = 1; i <= m; i++) {
            scanf("%d", &op);
            if (op == 1) {
                scanf("%d%d%d", &l, &r, &p);
                a[cnt++] = {l, p, now - 1};
                a[cnt++] = {r + 1, -p, now - 1};
            } else if (op == 2) {
                now++;
            } else if (op == 3) {
                scanf("%d%d", &l, &r);
                int ans = 0;
                for (int i = 0; i < cnt; i++) {
                    ans = (ans + calc(a[i], l, r, now));
                    if (ans >= mod)ans -= mod;
                    if (ans < 0)ans += mod;
                }
                ans = (ans % mod + mod) % mod;
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}
