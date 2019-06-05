/** https://cn.vjudge.net/problem/1509595/origin
  * ��ʵҲ�����������������Ҫת��˼ά��
  * ���Ҵ����ϵ�Сϸ��Ҫ����ע��
  */

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mo = 1e9 + 7;
const int N = 100001;
ll inv[N + 5];

ll fpow(ll a, ll b) {
    ll ans = 1;
    a %= mo;
    while (b) {
        if (b & 1)ans = (ans * a) % mo;
        a = (a * a) % mo;
        b >>= 1;
    }
    return ans;
}

ll ginv(ll x) {
    return fpow(x, mo - 2);
}

void Init() {
    for (int i = 1; i <= N; i++)
        inv[i] = ginv(i);
}

int main() {
    Init();
    int kase = 0, T;
    ll n, k, ans, com;
    scanf("%d", &T);
    while (kase++ < T) {
        scanf("%lld%lld", &n, &k);
        ans = 0;
        if (n >= k)//���ﻹ���к�����
        {
            ans = fpow(2, n);
            com = 1;
            for (int i = 0; i < k; i++) {
                ans = (ans + mo - com) % mo;
                com = com * (n - i) % mo * inv[1 + i] % mo;//���µõ������C(n,i)
                //ȡģ����һ��ϸ�µĶ�����ȡ���˻Ῠʱ�䣬ȡ���˻᲻��
            }
        }
        printf("Case #%d: %lld\n", kase, ans);
    }
    return 0;
}
