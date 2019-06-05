/*
HDU-6425-mutc9
http://acm.hdu.edu.cn/showproblem.php?pid=6425
������������븴������������a���˶��ǰ��Σ�������ȥ
Ȼ������һ�¼�������������ͺ��ˣ�����ܼ򵥣�Ҫ�뵽������

*/
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
const int MOD = 998244353;

ll _pow(ll a, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n % 2)res = res * a % MOD;
        a = a * a % MOD;
        n /= 2;
    }
    return res;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        ll a, b, c, d;
        scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
        ll ans = _pow(2, c) * d % MOD + _pow(2, c) * (b + 1) % MOD + (_pow(2, b) - 1 - b);
        ///1.ֻ��һ��d��+�кܶ���
        ///2.ֻ��һ���ģ�����û��+1��+�кܶ���
        ///3.�кܶ����ӣ�-ֻ��һ�����ӣ�-û�����ӣ���2�ظ���
        ans = ans * _pow(2, a) % MOD;
        printf("%lld\n", ans);
    }
}
