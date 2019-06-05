/*
http://acm.hdu.edu.cn/showproblem.php?pid=4771
���⣺�����Թ����ߣ�ȡ��������Ʒ�����·��
˼·����Ʒ����ĸ�������״̬ѹ������һ��BFS���ɣ�
ÿ�θ�����״̬�����൱�����µ�ͼ���ˡ�
��˼����˼·�ܻ��ҵ�����һЩС�¹ʣ�ѧ��һ�����ϵĴ��룬ϣ���ܸ��õ�������˼�롣
*/

#include<stdio.h>
#include<string.h>
#include<queue>

#define N 100 + 5

using namespace std;

typedef struct node {
    int x, y, s;

    bool operator==(const node &nd) const { return x == nd.x && y == nd.y; }
};

node st;
int mark[1 << 4][N][N];
char g[N][N];
int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
node K[5];
int n, m, k;

bool check(int x, int y, int s) {
    return x >= n || x < 0 || y >= m || y < 0 || mark[s][x][y] || g[x][y] == '#';
}

int BFS() {
    memset(mark, 0, sizeof(mark));
    queue<node> q;
    q.push(st);
    mark[st.s][st.x][st.y] = 0;

    node t, p;

    while (!q.empty()) {
        t = q.front();
        q.pop();

        //printf("(%d,%d,%d)\n",t.x+1,t.y+1,t.s);
        if (t.s == (1 << k) - 1)
            return mark[t.s][t.x][t.y] - 1;
        for (int i = 0; i < 4; i++) {
            p = {t.x + dir[i][0], t.y + dir[i][1], t.s};
            for (int j = 1; j <= k; j++)//
                if (t == K[j]) {
                    //printf("(%d,%d,%d)\n",t.x+1,t.y+1,t.s);
                    p.s = t.s | (1 << (j - 1));
                    break;
                }

            if (check(p.x, p.y, p.s))
                continue;
            mark[p.s][p.x][p.y] = mark[t.s][t.x][t.y] + 1;
            q.push(p);
        }
    }
    return -1;
}

int main() {
    char str[N];
    while (scanf("%d %d", &n, &m) != EOF && n + m) {
        for (int i = 0; i < n; i++) {
            scanf("%s", g[i]);
            for (int j = 0; j < m; j++)
                if (g[i][j] == '@')
                    st = {i, j, 0};
        }

        scanf("%d", &k);
        for (int i = 1, a, b; i <= k; i++) {
            scanf("%d %d", &a, &b);
            K[i] = {a - 1, b - 1, 0};
        }

        printf("%d\n", BFS());
    }
    return 0;
}

/*
4 4
#@##
....
####
....
2
2 1
2 4
*/
