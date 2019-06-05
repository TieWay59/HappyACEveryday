/** http://acm.hdu.edu.cn/showproblem.php?pid=6321
  * ���⣺��n���㣬�����ȡû�й�����ļ����ߵķ�����Ŀ
  * ��̬��ӻ�ɾ��ͼ�еıߣ�ÿ�θĶ������������ȡ1��n/2���ߵķ�����
  * ˼·��nС�ڵ���10����һ���������ѣ���ʵ�ǰ�ʾ״ѹdp��
  * ת�ƹ��̼�����ע��
  *
  * ��˼�������ѧ��״ѹdp������������������Ľⷨ�����һῨȡģ
  * �ο���https://ideone.com/neLUcC
  */
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const int N = 1025;
const int M = 12;

int Kase, n, q, u, v, mxs;
int dp[N][M];
int cnt[N];//ͳ��cnt[state]�м���1����
char op[2];


int main() {
    for (int i = 1; i < N; i++)
        cnt[i] = cnt[i >> 1] + (i & 1);
    //Ԥ����ͳ������״̬�м����㣬Ҳ����dp��˼ά

    scanf("%d", &Kase);
    while (Kase--) {
        scanf("%d %d", &n, &q);
        memset(dp, 0, sizeof dp);
        mxs = (1 << n) - 1;//��״̬�ı�ʾ ����n=5 mxs=(11111)B

        for (int i = 0; i <= mxs; i++)
            dp[i][0] = 1;

        while (q--) {
            scanf("%s%d%d", op, &u, &v);
            u--, v--;
            int uv = (1 << u) | (1 << v);//��u��v��ת���ɶ�������uv����ʾ����u��v���״̬

            for (int s = mxs; s >= 0; s--) {
                //����״̬��ʼ���£��ӵ�ൽ���ٸ��£������ظ��ۼ�
                if ((s & uv) != uv)continue;//������u��v���״̬����������

                for (int j = 1; j <= cnt[s]; j++) {//����ͷ���Ӧ��û��ϵ��ʵ��������񷴹�������һЩ
                    dp[s][j] += (op[0] == '+') ? dp[s ^ uv][j - 1] : (mod - dp[s ^ uv][j - 1]);
                    //״̬ת�Ʒ��̣���ǰ״̬������uv��ļ���s��ȡj���ߵĵķ�������
                    //�������в�����uv��ļ��ϣ�ȡj-1���ߵķ�����ת�ƶ���

                    if (dp[s][j] >= mod)dp[s][j] -= mod;
                    //����Ῠȡģ���Է���һ�ü�������
                }
            }

            for (int i = 1; i <= n / 2; i++)
                printf("%d%c", dp[mxs][i], i == n / 2 ? '\n' : ' ');
        }
    }
    return 0;
}
/*
1
4 8
+ 1 2
+ 3 4
+ 1 3
+ 2 4
- 1 2
- 3 4
+ 1 2
+ 3 4
*/
