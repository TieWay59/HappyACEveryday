/*
http://acm.hdu.edu.cn/showproblem.php?pid=4825
�ֵ������⣬����д�˶�̬�ģ�
����Ҫע���������ǴӸ�λ���λȥ�����������ҵ������ֲ������ŵ�
*/

#include<cstdio>
#include<cstring>
#include<cstdlib>

struct node {
    int num;
    node *nxt[2];

    node() { memset(this, 0, sizeof(node)); }

    void insert(int x)//
    {
        node *p = this;
        int id;
        for (int i = 31; i >= 0; i--) {
            id = (x >> i) & 1;
            if (!p->nxt[id])
                p->nxt[id] = new node;
            p = p->nxt[id];
        }
        p->num = x;
    }

    int query(int x) {
        node *p = this;
        int id;
        for (int i = 31; i >= 0; i--) {
            id = (x >> i) & 1;
            if (p->nxt[id ^ 1])
                p = p->nxt[id ^ 1];
            else
                p = p->nxt[id];
        }
        return p->num;
    }
};

int main() {
    int T, kase = 0, n, m, t;
    scanf("%d", &T);
    while (kase++ < T) {
        node Trie;
        scanf("%d %d", &n, &m);
        while (n--) {
            scanf("%d", &t);
            Trie.insert(t);
        }
        printf("Case #%d:\n", kase);
        while (m--) {
            scanf("%d", &t);
            printf("%d\n", Trie.query(t));
        }
    }
    return 0;
}

