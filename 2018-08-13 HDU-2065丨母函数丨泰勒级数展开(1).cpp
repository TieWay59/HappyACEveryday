/** http://acm.zjnu.edu.cn/CLanguage/showproblem?problem_id=1136
  * ������Ƴ������ʽ�����Ǻܼ򵥵���Ŀ�������������ʽ������
  * ������
  * https://blog.csdn.net/ramay7/article/details/50251645
  */

#include <bits/stdc++.h>

using namespace std;
const int mo = 100;
typedef long long ll;

ll fpow(ll a, ll b) {
    ll ans = 1;
    a %= mo;
    while (b) {
        if (b & 1)ans = (ans * a) % mo;
        b >>= 1;
        a = (a * a) % mo;
    }
    return ans;
}


int main(void) {
    int T;
    ll n;
    while (scanf("%d", &T) != EOF && T) {
        for (int i = 1; i <= T; i++) {
            scanf("%lld", &n);
            printf("Case %d: %lld\n", i, (fpow(4, n - 1) + fpow(2, n - 1)) % mo);
        }
    }
    return 0;
}
/*
10 2
0 2 8 3 6 7 5 1 4 0
7 10
6 10
*/
