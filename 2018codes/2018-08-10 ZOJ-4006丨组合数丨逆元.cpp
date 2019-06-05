/**http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemId=5724
  *������Ҫ���ǿ���ʽ�ɣ������ӣ������Ҷ����������̫������
  */

#include<bits/stdc++.h>

using namespace std;
const int mo = 1e9 + 7;
const int N = 1e5 + 5;
typedef long long ll;
ll fac[N], inv[N], ans, tmp, P, Q;

ll fpow(ll base, ll idx) {
    ll ans = 1;
    base %= mo;//��������
    while (idx) {
        if (idx & 1)ans = (ans * base) % mo;
        base = (base * base) % mo;
        idx >>= 1;
    }
    return ans;
}

ll getinv(ll a) {
    return fpow(a, mo - 2);
}

ll C(int n, int m)//�������
{
    if (n < m)return 0;
    return fac[n] * inv[n - m] % mo * inv[m] % mo;
}

int main() {
    int T, n, m;
    scanf("%d", &T);

    fac[0] = 1;
    for (int i = 1; i < N - 4; i++)
        fac[i] = (fac[i - 1] * i) % mo;
    inv[N - 5] = getinv(fac[N - 5]);
    for (int i = N - 6; i >= 0; i--)
        inv[i] = (inv[i + 1] * (i + 1)) % mo;

    while (T--) {
        scanf("%d%d", &n, &m);
        m = abs(m);
        if (n < m) {
            puts("0");
            continue;
        }
        P = 0;
        for (int i = 0; i <= (n - m) / 2; i++)
            P = (P + getinv(fpow(4, i)) * C(n, i) % mo * C(n - i, m + i)) % mo;
        Q = fpow(2, m + n);
        ans = P * getinv(Q) % mo;
        printf("%lld\n", ans);
    }
    return 0;
}
/*

*/
