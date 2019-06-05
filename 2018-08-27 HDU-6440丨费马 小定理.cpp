/*http://acm.hdu.edu.cn/showproblem.php?pid=6440
�����̫�����ˣ�
����С����
a^(p-1)=1(mod p)
a^p=a(mod p)
(a+b)^p=a+b(mod p)
a^p+b^p=a+b(mod p)
���԰Ѽӷ��˷������¶����ȡģ�ľͿ����ˡ�����

*/
#include<cstdio>
#include<algorithm>

using namespace std;
typedef int ll;

int main() {
    int T, p;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &p);
        for (int i = 0; i < p; i++, puts(""))
            for (int j = 0; j < p; j++)
                printf("%d ", (i + j) % p);
        for (int i = 0; i < p; i++, puts(""))
            for (int j = 0; j < p; j++)
                printf("%d ", i * j % p);
    }
    return 0;
}

