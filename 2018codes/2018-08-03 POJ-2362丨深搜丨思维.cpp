/** http://poj.org/problem?id=2362
  * ���⣺�жϸ����Ĺ����ܷ�ƴ��������
  * ˼·���ȼ����Ĺ��Ӻ��ۺϵ��ķ�֮һ�ܷ����㣬
  * Ȼ��ʼ����������ȥ������bgn��������֦�ģ�
  * ��ǰ��ƴ��cnt���ߣ�����״̬�Ǵ�ǰ���������ģ�
  * ˵����i֮ǰ�Ĺ��Ѿ����жϹ��Ƿ��������������
  * ���Դ�bgn��ʼ�ѾͿ��Լ���ļ���ʱ�䣡
  * ��˼���������������ˣ�����Ϊ�Ǵ�����ѡһ������������Σ�
  * Ȼ���û�뷨�ˡ�
  * �ο���https://blog.csdn.net/u013480600/article/details/27581015
  */


#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int N = 25;
int n, m, T, sum, mxlen;
int len[N];
bool vis[N];

bool dfs(int cnt, int left, int bgn) {
    if (cnt == 4)return true;
    for (int i = bgn; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = true;
            if (left == len[i]) {
                if (dfs(cnt + 1, sum, 1))
                    return true;
            } else if (len[i] < left) {
                if (dfs(cnt, left - len[i], i + 1))
                    return true;
            }
            vis[i] = false;
        }
    }
    return false;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        mxlen = sum = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &len[i]);
            sum += len[i];
            mxlen = max(mxlen, len[i]);
        }
        if (sum % 4 != 0 || mxlen > sum / 4) {
            puts("no");
            continue;
        }

        sum /= 4;
        memset(vis, 0, sizeof vis);
        if (dfs(1, sum, 1))puts("yes");
        else puts("no");
    }

    return 0;
}

/*

*/






