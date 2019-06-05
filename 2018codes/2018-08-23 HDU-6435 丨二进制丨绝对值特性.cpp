/*http://acm.hdu.edu.cn/status.php?first=&pid=&user=tieway59&lang=0&status=0
����һ��ʼ���úܸ��ӵģ���������Ҳ�����ԡ�
�����һ��˼·�ǳ��������Ŀ��
http://note.youdao.com/noteshare?id=825fbd8b12abd00668e4a7530322217c&sub=270D48B160B84704A440B5DB2AC597F6
*/
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 65;
ll a[N], b[N], ans;
int val, n, m, k, sta, x[6];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &n, &m, &k);
        sta = 1 << k;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &val);
            for (int j = 0; j < k; j++)
                scanf("%d", &x[j]);

            for (int s = 0; s < sta; s++) {
                ll sum = val;
                for (int j = 0; j < k; j++)
                    sum += x[j] * ((((s >> j) & 1) << 1) - 1);
                a[s] = max(sum, a[s]);
            }
        }
        for (int i = 1; i <= m; i++) {
            scanf("%d", &val);
            for (int j = 0; j < k; j++)
                scanf("%d", &x[j]);

            for (int s = 0; s < sta; s++) {
                ll sum = val;
                for (int j = 0; j < k; j++)
                    sum += x[j] * ((((s >> j) & 1) << 1) - 1);
                b[s] = max(sum, b[s]);
            }
        }

        for (int s = 0; s < sta; s++)
            ans = max(ans, a[s] + b[sta - 1 - s]);
        printf("%lld\n", ans);

        ans = 0;
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
    }
    return 0;
}

