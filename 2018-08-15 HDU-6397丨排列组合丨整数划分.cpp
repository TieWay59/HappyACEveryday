//wtw
#include<cstdio>
#include<algorithm>

using namespace std;
typedef long long ll;
const ll mod = 998244353;
const ll N = 2e5 + 5;
//��ʵ���ﻹ������һ�£�����Ҫ�����������ݷ�Χ����Ϊ���ǻ����k+m-1
ll fac[N], inv[N];

void Init() {
    inv[1] = 1;
    for (int i = 2; i < N; i++)//������Ԫɸ����Ԫ
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    fac[0] = 1;
    for (int i = 1; i < N; i++)
        fac[i] = (fac[i - 1] * i) % mod;
    inv[0] = 1;
    for (int i = 1; i < N; i++)
        inv[i] = (inv[i - 1] * inv[i]) % mod;
    //���ڱ��ⲻ̫��Ҫ��������Ԫ����ֱ�ӻ���ɽ׳˵���Ԫ
}

ll C(ll a, ll b)//����֮Ϊ�����ɶ��Եĺ���
{
    return fac[a] * inv[b] % mod * inv[a - b] % mod;
}

int main() {
    Init();
    int T;
    ll n, m, k;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld%lld%lld", &n, &m, &k);
        ll ans = 0, lim = min(m, k / n);//ע��k���ܳ���m*n��
        for (int i = 0; i <= lim; i++) {//��ʽ
            if (i & 1) ans = (ans + mod - C(k - i * n + m - 1, m - 1) * C(m, i) % mod) % mod;
            else ans = (ans + C(k - i * n + m - 1, m - 1) * C(m, i) % mod) % mod;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
/*
4
2 3 3
2 3 4
3 3 3
128 3 340
*/
