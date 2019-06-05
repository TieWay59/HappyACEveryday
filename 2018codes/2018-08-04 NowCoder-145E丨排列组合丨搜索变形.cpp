#include<bits/stdc++.h>

using namespace std;
const int maxn = 100005;
int stk[maxn], top;
int c3[maxn], c4[maxn];

void printans() {
    int n = stk[1] + top - 1;
    int m = stk[1] * (stk[1] - 1) / 2;
    for (int i = 2; i <= top; i++)
        m += stk[i];

    printf("%d %d\n", n, m);
    //�����������ȫͼ���ı�
    for (int i = 1; i <= stk[1]; i++)
        for (int j = i + 1; j <= stk[1]; j++)
            printf("%d %d\n", i, j);
    //��������к󲹵ĵ����ӵı�
    for (int i = 1; i < top; i++)
        for (int j = 1; j <= stk[i + 1]; j++)
            printf("%d %d\n", i + stk[1], j);
    //��ż�����ȫͼ֮�����ȥȡ

    exit(0);
    //����ֱ���˳������ˣ���Ϊ�����dfs�ݹ�û�н���������͵���İ취��
}

void dfs(int cliques, int nodes) {//clique����Ҫ������ nodes�����е����ӵ���
    if (stk[1] + top - 1 > 75)//��ʹ�õĵ�������75���Ͳ���
        return;

    if (!cliques) {
        printans();
        return;
    }

    if (!nodes) {//��Ȼ���ʼ��ʱ����0��Ҳ����˵���ȹ���һ���ϴ���ȫͼ
        //ע�����ﲻһ�����������ţ�������ʱ�����û��ͨ���
        for (int i = 75; i >= 4; i--)
            if (c4[i] <= cliques) {
                stk[++top] = i;
                dfs(cliques - c4[i], i);
                //����ȫͼ�ܹ��ɵ��ż�ȥ����������
                --top;
            }
    } else {//��ȥ�ϴ���ȫͼ֮�󣬾Ͷ���ʼ�ҵ����ĵ�������ȫͼ
        for (int i = nodes; i >= 3; i--)
            if (c3[i] <= cliques) {
                stk[++top] = i;
                dfs(cliques - c3[i], i);
                //ÿ����������ȫͼ�ı�������һ��C(i,3)�������ӵ�����
                //��ĵ����������ˣ�cliques��С�����´�nodes�������е������ټ��ٵ�i����
                --top;
            }
    }
}

int main() {
    //��ʼ��C(i,3),C(i,4);
    for (int i = 3; i <= 75; i++)
        c3[i] = i * (i - 1) * (i - 2) / 6;
    for (int i = 4; i <= 75; i++)
        c4[i] = i * (i - 1) * (i - 2) * (i - 3) / 24;

    int k;
    scanf("%d", &k);
    dfs(k, 0);
    return 0;
}
