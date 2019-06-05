#include <stdio.h>
#include <string.h>
#include <math.h>

typedef long long ll;
const int MAXN = 1000008;
const int INF = 0x3f3f3f3f;
ll fac[MAXN], cnt[MAXN], top;
ll n, m, y, t;

int main() {
    scanf("%lld", &n);
    m = n;
    t = (ll) sqrt(n);
    for (int i = 2; i <= t && i <= n; i++) {
        if (n % i == 0) {
            fac[++top] = i;
            while (n % i == 0)
                cnt[top]++, n /= i;
            //��Ϊn�ᱻ��������ʵ�������кܿ�
        }
    }
    if (n > 1) {
        fac[++top] = n;//��������
        cnt[top] = 1;//�������Ӹ���
    }
    y = 1;
    for (int i = 1; i <= top; i++) {
        if (cnt[i] & 1)
            y *= fac[i];
    }
    printf("%lld\n", m + y + 2 * (ll) sqrt(m * y));
    return 0;
}
/*
x=min(n+y+2*sqrt(n*y));
�ҵ���С��yʹ�ã�x�������⼴�ɡ�
˼ά���������ֽ⡣
*/
