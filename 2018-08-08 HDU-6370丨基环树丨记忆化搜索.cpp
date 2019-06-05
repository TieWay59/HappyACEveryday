/*
http://acm.hdu.edu.cn/showproblem.php?pid=6370
���⣺����ɱ��Ϸ����������˻���ָ�ϣ�����˵�ѣ����˿���˵��
����Ǵ������������������
˼·������ȫ�����ǿ��ܵģ����ԡ����塱�ǲ������գ�������������ȥ������
��ʵ��Ҫͨ��һЩö�ٷ��֣��ڵ��ǵĻ���Ǵ���һֻ���ǵģ�
���ѡ��ֻ����ֻ���ǵ�������ڵ��ǻ��е������˾Ͷ��Ǵ���
��ô����ָ�ϴ���Ϊ�ǵ���Ҳ�������ˡ�
��˼����ʵ������ûʲô���壬���ǱϾ�����û���������͵�����һ��˼ά�ɡ�
��ο�����Ϊ�Ի�������ģ�ͺ�İ������Ҳ���������ǵ��뷨��
˵�����뷨��Ҳ�ǽ������Լ���֪ʶ�����ϵġ�
*/

#include <bits/stdc++.h>

using namespace std;
const int N = 100005;
struct players {
    int p, t;
} plr[N];
int ans[N];
bool flag[N];

void dfs(int x) {
    flag[x] = true;
    int p = plr[x].p;

    if (plr[x].t) {//xָ�����Ǵ���
        if (!flag[p]) {//xָ����δ�����
            dfs(p);
            if (ans[p] == -1)//xָ��������ʵ����
                ans[x] = -1;//x������
            else if (ans[p] == x)//xǰ�������ָ����x����
                ans[x] = -1;//x������
            else
                ans[x] = ans[p];//������ǰ�����ָ������

        } else if (ans[p]) {//p�Ѽ����ȷ������
            if (ans[p] == x)//xǡ���Ǳ�ָ�����ǣ����ֵ��ǻ�
                ans[x] = -1;
            else//������ǰ�����ָ������
                ans[x] = ans[p];
        } else {//aָ�����Ѽ����ǰ��û����
            ans[x] = N;
        }
    } else {//aָ��������
        ans[x] = p;//��¼x��ָ������
    }
}

int main() {
    int T, n, res;
    char s[15];
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1, x; i <= n; i++) {
            ans[i] = flag[i] = 0;
            scanf("%d %s", &x, s);
            if (s[0] == 'v')plr[i] = {x, 1};
            else plr[i] = {x, 0};
        }

        for (int i = 1; i <= n; i++)
            if (!ans[i])
                dfs(i);

        res = 0;
        for (int i = 1; i <= n; i++)
            if (ans[i] == -1)//ͳ����������
                res++;

        printf("0 %d\n", res);
    }
    return 0;
}
