/** https://www.nowcoder.com/acm/contest/146/G
  * ���ʩ�޵���/������������
  * �����Ҳ��Ǻ����ף��������￪��ͷ
  * https://blog.csdn.net/Tony5t4rk/article/details/81586522
  */

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mo = 998244353;
const int N = 262144 + 6;
ll inv[N], ans, p1, p2;
int n;

int main() {

    scanf("%d", &n);
    if (n == 1)
        return 0 * puts("1");
    n--;

    inv[1] = 1;
    for (int i = 2; i < N; i++)
        inv[i] = inv[mo % i] * (mo - mo / i) % mo;

    ans = 0, p1 = p2 = 1;
    for (int i = 0; i <= n; i++) {
        ans = (ans + p1 * p2 % mo * inv[i + 1] % mo) % mo;
        p1 = p1 * (n - i) % mo * inv[i + 1] % mo;
        p2 = p2 * (n + i + 1) % mo * inv[i + 1] % mo;
    }
    printf("%lld\n", ans);
    return 0;
}
