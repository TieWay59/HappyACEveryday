/*http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemId=5805
���⣺
�����ֲ������޸�r�����ж�r��Ȼ������ĳһ���裬���r����n+1���yes��������ѭ�����no
˼·��
��ʵvis���ǣ�����һ�پͿ����ˣ�������Ŀ����ʱ��Ƚ��٣���ò�Ҫ��string��
Ϊ���Ż�ʱ�䣬��д��while�ķǵݹ���ʽ
���и���Сϸ�ڻ�Ӱ��ʱ��ģ��Ҷ���ע��
*/

#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;
typedef long long ll;
const int N = 1e4 + 5;

struct Oprat {
    char op[10];
    int v, k;
} data[N];
int T, n, r;
bool vis[N][256], flag;//�ռ��Ż���

int main() {
    scanf("%d", &T);
    while (T--) {
        flag = false;
        r = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%s %d", data[i].op, &data[i].v);
            if (data[i].op[0] != 'a') {
                scanf("%d", &data[i].k);
            }
        }
        int i = 1;
        while (i <= n) {
            if (flag || vis[i][r]) {
                flag = true;
                break;
            }
            vis[i][r] = true;
            switch (data[i].op[1]) {
                case 'd':
                    r = r + data[i].v;
                    while (r >= 256)r -= 256;//ȡģ�Ż���
                    i = i + 1;
                    break;
                case 'e':
                    if (r == data[i].v)i = data[i].k;
                    else i = i + 1;
                    break;
                case 'n':
                    if (r != data[i].v)i = data[i].k;
                    else i = i + 1;
                    break;
                case 'l':
                    if (r < data[i].v)i = data[i].k;
                    else i = i + 1;
                    break;
                case 'g':
                    if (r > data[i].v)i = data[i].k;
                    else i = i + 1;
                    break;
            }
        }

        if (flag)puts("No");
        else puts("Yes");
        memset(vis, false, sizeof vis);
    }
    return 0;
}
