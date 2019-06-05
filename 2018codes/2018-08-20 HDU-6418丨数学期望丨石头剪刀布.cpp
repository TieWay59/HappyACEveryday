
/*http://acm.hdu.edu.cn/showproblem.php?pid=6418
hdu-6418-mutc9
���⣺ÿ���˸���ȷ����ʯͷ�����������ƣ����������
ʤ��+1�֣�����-1�֣���÷ֵ�������
˼·��ʵ���Ͽ����Ƴ���ʽ�������е��Ƶ����ǹ۲������Ĵ𰸣�Ѱ�ҹ�ϵ
������ʦ˵���ǣ������еĵ÷�����˳�������һ�¾���������
����ѧ���������ޣ����ǹ۲��ҹ�ʽ�ɡ�����
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll a, b, c, d, e, f;
    ll n, m, T, g;
    scanf("%lld", &T);
    while (T--) {
        scanf("%lld%lld%lld%lld%lld%lld", &a, &b, &c, &d, &e, &f);
        n = a + b + c;
        m = d * (c - b) + e * (a - c) + f * (b - a);
        g = __gcd(n, abs(m));
        n /= g;
        m /= g;
        if (n == 1)printf("%lld\n", m);
        else printf("%lld/%lld\n", m, n);
    }
    return 0;
}


/*
4
5 0 0
0 0 5
*/
