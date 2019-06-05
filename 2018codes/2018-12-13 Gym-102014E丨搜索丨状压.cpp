#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>

using namespace std;
typedef long long ll;

const int INF = 0x3F3F3F3F;
const ll Fx9 = 0x00FFFFFFFFF;
const ll Fx1 = 0x0000000000F;
const ll F11 = 0x10000000000;
//��41����λ����ʾ״̬
//ǰ36λ�ÿ4λ����һ�����ϵ���
//37~40λ��ʾ��0���ڲ�λ��
//41λ��0/1��ʾ���������ص����
//��ʾ��״̬�Ժ���map����¼���ѣ���dijkstra˫����
//��Ϊ��Ŀ���ݷ�Χ���ޣ�10�����ڵĽ��㴦�����ҵ���ֵ��
//����ʵ�����е�ʱ��û�кܴ�

int nbrs[9][4] = {
        // R, L, U, D
        {1, 8, 6, 3}, // 0
        {2, 0, 7, 4}, // 1
        {3, 1, 8, 5}, // 2
        {4, 2, 0, 6}, // 3
        {5, 3, 1, 7}, // 4
        {6, 4, 2, 8}, // 5
        {7, 5, 3, 0}, // 6
        {8, 6, 4, 1}, // 7
        {0, 7, 5, 2}, // 8
};
map<ll, int> dis;

struct Less {//���أ�������������ȶ���
    bool operator()(const ll &a, const ll &b) const {
        return dis[b] < dis[a];
    }
};

ll read() {
    ll bpos = 0, pos = 0;
    ll flds = 0, d = 0;
    for (int y = 0; y < 3; y++)
        for (int x = 0; x < 3; x++) {
            scanf("%lld", &d);
            flds |= d << (pos << 2);
            if (d == 0)bpos = pos;
            pos++;
        }
    return (flds | bpos << 36);
}

int main() {
    int ch, cv;
    ll st, gl;

    while (cin >> ch >> cv && ch + cv) {
        st = read();
        gl = read() | F11;

        dis.clear();
        dis[st] = dis[gl] = 0;

        priority_queue<ll, vector<ll>, Less> q;
        q.push(st);
        q.push(gl);
        //˫������

        int min_cost = INF;
        int min_check = 6;
        ll u, v;

        while (!q.empty()) {
            u = q.top();
            q.pop();
            v = u ^ F11;
            if (dis.find(v) != dis.end()) {
                int c = dis[u] + dis[v];
                if (min_cost > c) min_cost = c;
                if (--min_check <= 0)break;
            }
            ll upos = (u >> 36) & Fx1;
            for (int i = 0; i < 4; i++) {
                ll vpos = nbrs[upos][i];
                int nvd = dis[u] + (i < 2 ? ch : cv);
                ll k = (u >> (vpos * 4)) & Fx1;
                ll v = (u & (Fx9 | F11) & ~(Fx1 << (vpos * 4))) | (k << (upos * 4)) | (vpos << 36);

                if (dis.find(v) == dis.end())
                    dis[v] = nvd, q.push(v);
                else if (dis[v] > nvd)
                    dis[v] = nvd;
            }
        }
        cout << min_cost << endl;
    }

    return 0;
}
/*
4 9
6 3 0
8 1 2
4 5 7
6 3 0
8 1 2
4 5 7
31 31
4 3 6
0 1 5
8 2 7
0 3 6
4 1 5
8 2 7
92 4
1 5 3
4 0 7
8 2 6
1 5 0
4 7 3
8 2 6
12 28
3 4 5
0 2 6
7 1 8
5 7 1
8 6 2
0 3 4
0 0
*/
