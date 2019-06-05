
/** https://www.nowcoder.com/acm/contest/144/C
  * ���⣺����1-N�����ظ��ļ��ϣ��涨ÿ�β�������1��Mѡһ��x��
  * ��������һ�����ϣ������������N�Σ�������Щ���ϲ������ٿ��ܵ�״̬
  * ˼·������N�β�����õ������ֵ�����Ϊi������ȫ��������Ȼ���ڳ��Է��뼯�ϵ������
  * ��˼������ѧ���У��Һò�
  */
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1000010;
const int mo = 998244353;
ll n, m;
ll inv[N];

int main() {
    int T, kase = 0;
    scanf("%d", &T);
    inv[1] = inv[0] = 1;
    for (int i = 2; i < N; ++i)
        inv[i] = (mo - mo / i) * inv[mo % i] % mo;

    while (kase++ < T) {
        scanf("%lld%lld", &n, &m);
        ll A = m % mo, C = 1;
        ll ans = 0;

        for (int i = 1; i <= n && i <= m; ++i) {
            ans = (ans + A * C) % mo;
            A = A * ((m - i) % mo) % mo;
            //A(m,i)��ʾȡ��i�����ֵ�������
            C = C * ((n - i) % mo) % mo * inv[i] % mo;
            //C(n,i)��ʾ��n�����ַ��뼯�ϵ������
        }
        printf("Case #%d: %lld\n", kase, ans);
    }
    return 0;
}
/*
2
2 2
3 4
*/
