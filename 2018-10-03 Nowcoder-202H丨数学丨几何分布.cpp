/*
https://www.cnblogs.com/tobyw/p/9737629.html
�����֪�����֪ʶ�㣬����һ��ˮ���ˡ�
*/

#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;
const int MAXN = 10050;

int main() {
    int T, Ti = 0, n, m, k;
    scanf("%d", &T);
    while (Ti++ < T) {
        scanf("%d %d %d", &n, &m, &k);
        double ans = 0.0;
        for (int i = 0; i < k; i++)
            ans += (n - i) * 1.0 / (m - i);
        printf("Case #%d: %f\n", Ti, ans);
    }
    return 0;
}
