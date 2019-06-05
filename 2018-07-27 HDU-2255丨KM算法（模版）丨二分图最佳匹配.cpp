/*
ʵ���ϣ�O(n^4)��KM�㷨���ֲ��ף�ʹ��O(n^3)������ܴ�����KM������Ч��
��Ҫ��O(1)��ʱ���ҵ�����һ���ߣ�ʹ���ڽӾ���洢��Ϊ����
*/
#include <cstring>
#include <cstdio>

const int N = 305;
const int INF = 0x3f3f3f3f;
int match[N], slack[N];
int potentialX[N], potentialY[N];
int weight[N][N];
bool visX[N], visY[N];
int n, size_X, size_Y, ans;

bool FindPath(int u) {
    int tempDelta;

    visX[u] = true;
    for (int v = 0; v < size_Y; ++v) {
        if (visY[v]) continue;
        tempDelta = potentialX[u] + potentialY[v] - weight[u][v];
        if (tempDelta == 0) {//(u,v)�������ͼ��
            visY[v] = true;
            if (match[v] == -1 || FindPath(match[v])) {
                match[v] = u;
                return true;
            }
        } else if (slack[v] > tempDelta)
            slack[v] = tempDelta;//(u,v)���������ͼ����y���ڽ�������
    }
    return false;
}

void Kuhn_Munkres() {
    for (int x = 0; x < size_X; ++x) {
        for (int j = 0; j < size_Y; ++j)
            slack[j] = INF;
        //���ﲻҪ���ˣ�ÿ�λ��µ�x��㶼Ҫ��ʼ��slack

        while (true) {
            memset(visX, false, sizeof(visX));
            memset(visY, false, sizeof(visY));
            //��������ʼ�������������,���ÿ��findpath()��Ҫ����
            if (FindPath(x)) break;
            else {
                int delta = INF;
                for (int j = 0; j < size_Y; ++j)
                    //��Ϊdfs(x)ʧ��������xһ���ڽ������У�y���ڽ������У��ڶ����
                    if (!visY[j] && delta > slack[j])
                        delta = slack[j];

                for (int i = 0; i < size_X; ++i)
                    if (visX[i]) potentialX[i] -= delta;
                for (int j = 0; j < size_Y; ++j) {
                    if (visY[j]) potentialY[j] += delta;
                    else slack[j] -= delta;

                    //�޸Ķ����Ҫ�����е�slackֵ����ȥdelta
                    //������Ϊlx[i] ��С��delta
                    //slack[j] = min(potentialX[i] + potentialY[j] -w[i][j]) --j�����ڽ�����--Ҳ��Ҫ����delta���ڶ����
                }
            }
        }
    }
}

void KM_Solve() {
    //��ʼ��XY���ϵ����������
    memset(match, -1, sizeof(match));
    memset(potentialY, 0, sizeof(potentialY));
    for (int i = 0; i < size_X; ++i) {
        potentialX[i] = -INF;
        for (int j = 0; j < size_Y; ++j)
            if (potentialX[i] < weight[i][j])
                potentialX[i] = weight[i][j];
    }
    Kuhn_Munkres();
}

/*
�򵥵�˵��KM�㷨����������ǣ�����X�뼯��YԪ�ظ��ݶ�Ԫ�ı�Ȩ�໥ƥ�䣬
�ڴ�ʹ��Ծ����ܶ��ǰ���£�����ص���ֵ�����п�����ͬһ�����ϲ�ͬ���Խ���ƥ�䣩
*/

int main() {
    //��������Ҫ�����XY���ϵĴ�С��Ȩֵweight���Լ�����Ҫ��ʲô
    //���⣨HDU-2255��ģ�������� ���ƥ����������Ȩֵ��
    //�����������ƥ��������ͼ������ɣ�
    //���������С�����ø�����Ȩ���ٸ���ȡ�𰸣�
    while (scanf("%d", &n) != EOF) {

        size_X = size_Y = n;
        for (int i = 0; i < size_X; ++i)
            for (int j = 0; j < size_Y; ++j)
                scanf("%d", &weight[i][j]);

        KM_Solve();

        int ans = 0;
        for (int i = 0; i < size_Y; ++i)
            if (match[i] != -1)
                ans += weight[match[i]][i];
        printf("%d\n", ans);
    }
    return 0;
}
/*
�ο����£�
http://www.cnblogs.com/wenruo/p/5264235.html
https://www.cnblogs.com/jackge/archive/2013/05/03/3057028.html
https://blog.csdn.net/sixdaycoder/article/details/47720471
https://en.wikipedia.org/wiki/Hungarian_algorithm
*/
