#include <bits/stdc++.h>

const int N = 1e7 + 5;
int T, a;

/* http://acm.hdu.edu.cn/showproblem.php?pid=6322
���⣺����һ��ŷ�����̣������aС����ʹ��a��ŷ�����̵Ľ��Ǻ���
˼·���ҹ��ɣ�https://en.wikipedia.org/wiki/Euler%27s_totient_function
��˼�������Լ����ģ����뵽��Ҫ�ҹ����ˣ�������û�㣬
�����������Ҫ��ѧרҵ���ء�
*/
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &a);
        if (a == 1)puts("5");
        else if (a == 2)puts("7");
        else printf("%d\n", a + 5);
    }
    return 0;
}
/*

*/
