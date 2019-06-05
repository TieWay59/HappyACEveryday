/*https://www.cnblogs.com/tobyw/p/9737575.html
��һ��DP����Ŀ�����Ǳ�����뷨�������뵽��
����һ��������������һ����С��ƽ������
��С����һ���ж��صĹ��췽������������ȥ����һ��Ӧ�û������
*/
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;
typedef long long ll;
ll n, d, dp[65] = {0, 1};

ll build(ll x) {
    if (x <= 0)return 0;
    if (dp[x] || x <= 1)return dp[x];
    dp[x] = 1 + build(x - 1 - d) + build(x - 1);
    return dp[x];
}

int main() {
    while (scanf("%lld %lld", &n, &d) != EOF) {
        ll a = (1ll << (n - 1)) - 1;
        ll b = build(n - 1 - d);
        printf("%lld\n", abs(a - b));
    }
    return 0;
}
