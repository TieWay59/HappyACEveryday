/*��д�˳���ϸ����⣺
http://note.youdao.com/noteshare?id=6ba546030563c976fcd2acb763a8e3f2&sub=FD6AA29A54B9408DBD9406C8DD81ED11
*/

#include<cstdio>

typedef long long ll;
const int maxn = 2e6 + 5;
const long long mod = 1e9 + 7;
ll fib[maxn];
ll inv[maxn], fac[maxn], invf[maxn];
ll rav[maxn];
int div[maxn];

ll fpow(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1)ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return ans;
}

ll calinv(ll x) {
    return fpow(x, mod - 2);
}

void Init() {
    fib[0] = 0, fib[1] = fib[2] = 1;
    for (int i = 3; i < maxn; i++)//fib����
        fib[i] = (fib[i - 1] + fib[i - 2]) % (mod - 1);
    //ŷ�����ݣ�����mod-1�Ǧ�(mod)��ֵ

    inv[1] = 1;//��Ԫ
    for (int i = 2; i < maxn; i++)
        inv[i] = ((mod - mod / i) * inv[mod % i]) % mod;

    fac[0] = 1;//�۳�
    for (int i = 1; i < maxn; i++)
        fac[i] = (fac[i - 1] * i) % mod;

    invf[0] = 1;//�۳���Ԫ
    for (int i = 1; i < maxn; i++)
        invf[i] = (invf[i - 1] * inv[i]) % mod;
}

ll C(ll a, ll b) {
    return fac[a] * invf[b] % mod * invf[a - b] % mod;
}

int main() {
    int Kase, n, k, bok, cnt;
    ll sum, tot;
    Init();
    scanf("%d", &Kase);
    while (Kase--) {
        scanf("%d %d", &n, &k);
        bok = n, cnt = 0;

        for (int i = 1; i <= bok; i++)
            if (bok % i == 0)
                div[cnt++] = i;

        for (int i = 0; i < cnt; i++)//��ʽ
            rav[i] = C(n / div[i] + k - 1, k - 1);

        for (int i = cnt - 2; i >= 0; i--)//ȥ��
            for (int j = i + 1; j < cnt; j++)
                if (div[j] % div[i] == 0)
                    rav[i] = (rav[i] - rav[j] + mod) % mod;

        sum = 0;
        for (int i = 0; i < cnt; i++)//��ʽ�����
            sum = (sum + (fpow(2, fib[div[i]]) + mod - 1) % mod * rav[i] % mod) % mod;
        //����mod-1���Ǧ�(mod)

        tot = calinv(C(n + k - 1, k - 1));
        //C(n+k-1,k-1)��������
        printf("%lld\n", (sum * tot) % mod);
    }
    return 0;
}

