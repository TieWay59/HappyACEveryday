/*http://acm.hdu.edu.cn/showproblem.php?pid=6441
��������ù�ʽ���������Ӽ���
Ȼ��Ϊʲô������ʱ��wa��4���أ��о�������̫�����ˡ�����
*/
#include<cstdio>
#include<algorithm>

using namespace std;
typedef int ll;

int main() {
    int T, n, a;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &a);
        if (n < 1 || n > 2) {
            puts("-1 -1");
        } else if (n == 1) {
            printf("1 %d\n", a + 1);
        } else {
            if (a & 1)printf("%lld %lld\n", (1ll * a * a - 1) / 2, (1ll * a * a + 1) / 2);
            else printf("%lld %lld\n", 1ll * a * a / 4 - 1, 1ll * a * a / 4 + 1);
        }
    }
    return 0;
}
/*
*/
