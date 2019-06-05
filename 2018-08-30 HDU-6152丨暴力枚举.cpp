/*http://acm.hdu.edu.cn/showproblem.php?pid=6152
�����˺ܾã�˼·������ţ��䵽�һ������ռ俨����
֮ǰ���ʱ��û�������intҪ*4
������ͼ�ŷ��������������㲻ȫ�����Ҳ�ȫ��ͨ��
���ǰɣ��Ҿ��û�TLE�����ˣ����ˣ����ˣ���û���ˡ�
Ȼ�������Ŀ��ʵ�һ���������ʵn>5���޽�ģ�
����i����û��ϵ��������ö�٣�ʹ�ļ��װ�������
�����Ŀ�����ң���λ������1���ڽӾ���ֱ����bool���ͺ���
�Խ�ûת��������������֪����
ʱ���Ȼ��С��1000ms�����ȣ�
*/

#include<bits/stdc++.h>

using namespace std;
const int N = 6;
bool g[N][N];

int main() {
    int T, n;
    scanf("%d", &T);
    while (T--) {
        bool flag = true;
        scanf("%d", &n);
        if (n > 5)flag = false;

        for (int i = 1, x; i < n; i++)
            for (int j = 1; j <= n - i; j++) {
                scanf("%d", &x);
                if (flag)g[i][i + j] = g[i + j][i] = x;
            }
        for (int i = 0 + 1; flag && i <= n; i++)
            for (int j = i + 1; flag && j <= n; j++)
                for (int k = j + 1; flag && k <= n; k++) {
                    if (g[i][j] + g[j][k] + g[k][i] == 3)
                        flag = false;
                    else if (g[i][j] + g[j][k] + g[k][i] == 0)
                        flag = false;
                }
        if (flag)puts("Great Team!");
        else puts("Bad Team!");
    }
    return 0;
}
/*
2
4
1 1 0
0 0
1
4
0 0 0
0 0
0
*/

/*
2
4
1 1 0
0 0
1
4
0 0 0
0 0
0
*/
