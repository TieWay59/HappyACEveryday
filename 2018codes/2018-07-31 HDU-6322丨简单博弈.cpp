#include <bits/stdc++.h>

typedef long long ll;
const int N = 100000 + 5;
int T, a[N], n;
int sum, maxa;

/* http://acm.hdu.edu.cn/showproblem.php?pid=6324
���⣺���Ͻڵ㣬ȥȡһЩ�ڵ�ֵ��ÿ����õĽڵ�ֵ�����
Q��һ���ڵ㿪ʼ��ȡû�б�ֱ�������Ľڵ㣬��Q����ֵ�ܷ񳬹�T
˼·��ȫ����ֵ�������һ���������������ȫ�����Ϊ0��
˵������ȥȡ���ٶ�һ����ƽ�ֵģ�
���ȡ�õ���ֵ��Ϊ�㣬˵��������һ���취ȡ�����λ��1�����֣�
��T����һλ��0������ʹ��Q����T
*/

int main() {
    scanf("%d", &T);
    while (T--) {
        maxa = sum = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            sum ^= a[i];
            maxa = std::max(maxa, a[i]);
        }
        for (int u, v, i = 1; i < n; i++)
            scanf("%d %d", &u, &v);
        if (!sum)puts("D");
        else puts("Q");
    }

    return 0;
}
/*

*/
