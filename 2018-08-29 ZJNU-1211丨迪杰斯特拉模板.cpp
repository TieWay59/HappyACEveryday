#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>

using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 100005;
const int M = 500005;
int n, m, head[N], vis[N], dist[N], cnt;

struct Edge {
    int to, val, next;
} e[M * 2];//ע���˫���Ҫ�˶�

void init(int x, int y, int v) {
    e[++cnt].to = y, e[cnt].val = v, e[cnt].next = head[x], head[x] = cnt;
    e[++cnt].to = x, e[cnt].val = v, e[cnt].next = head[y], head[y] = cnt;
}

struct node {
    int id, val;

    node(int id, int val) : id(id), val(val) {}

    bool operator<(const node &x) const {
        return val > x.val;
    }
};

priority_queue <node> q;

void dij(int x) {
    dist[x] = 0;
    q.push(node(x, 0));
    while (!q.empty()) {
        int u = q.top().id;
        q.pop();
        vis[u] = 1;
        for (int i = head[u]; i != -1; i = e[i].next) {
            int v = e[i].to;
            if (vis[v])continue;
            if (dist[v] - dist[u] > e[i].val) {
                dist[v] = dist[u] + e[i].val;
                q.push(node(v, dist[v]));
                //�ǰѸ��µĽ��������ȶ��У��ҰѴ�����µĽڵ�Ĳ������if���ˣ�����
            }

        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    memset(dist, INF, sizeof(dist));
    memset(head, -1, sizeof(head));
    cnt = 0;
    for (int i = 1, x, y, z; i <= m; i++) {
        scanf("%d%d%d", &x, &y, &z);
        init(x, y, z);
    }
    dij(1);
    printf("%d\n", dist[n]);
    return 0;
}
