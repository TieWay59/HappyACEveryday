/*https://www.nowcoder.com/acm/contest/180/D
���⣬ת��������a[n]���ܲ����������õ���x^y��
�����Ի����Լ����һ�����ܲ���ͨ�����õ�ĳ������
*/
#include<stdio.h>

int f[32];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        for (int j = 31; j >= 0; j--)
            if (x >> j) {
                if (!f[j]) {
                    f[j] = x;
                    break;
                }
                x ^= f[j];
            }
    }
    int q;
    scanf("%d", &q);
    while (q--) {
        int x, y;
        scanf("%d%d", &x, &y);
        x ^= y;
        for (int i = 31; i >= 0; i--)
            if (x >> j)
                x ^= f[i];
        if (x) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
