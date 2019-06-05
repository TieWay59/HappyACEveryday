#include<bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;
int a[N], n, m, k;
bool vis[N];
int head[N], cnt_ed;
struct Edge {
    int v, nx;
} ed[N];

void AddEd(int u, int v) {
    cnt_ed++;
    ed[cnt_ed].nx = head[u];
    ed[cnt_ed].v = v;
    head[u] = cnt_ed;
}

/* http://codeforces.com/gym/100187/problem/J
 * ���⣺��һ�����У���m�������������ܷ��ԭ��������k���ֻ���1
 * ˼·��ÿһ����������һ������ߣ����������Ŀ���ݹ�ģ��С������ʽǰ��������ͼ
 * ��һ�����Ѽ��ɡ�
 * ��˼��������ʱ��̫�����ڱ����Ŀ�ˣ���Ϊ���������������ܸ��ӣ�
 * û�м�ʱ�뵽��ʽǰ���ǡ�
 */
void dfs(int u) {
    vis[u] = true;
    if (u == 1)return;
    for (int i = head[u]; ~i && !vis[1]; i = ed[i].nx)
        if (!vis[ed[i].v])dfs(ed[i].v);
}

int main() {
    cnt_ed = 0;
    memset(head, -1, sizeof head);

    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
        for (int u, v = 1; v <= n; v++) {
            scanf("%d", &u);
            AddEd(u, v);
        }

    scanf("%d", &k);
    for (int i = 1; i <= n; i++)
        if (a[i] == k)dfs(i);

    if (vis[1])puts("YES");
    else puts("NO");
    return 0;
}
