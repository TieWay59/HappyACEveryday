/*http://acm.hdu.edu.cn/showproblem.php?pid=1251
˼·���ֵ���ģ���⣬�����������Щ����ֵĿӵ㣬����������
���ܲ�Ҫ����Ϊ�ã����������Ƿǳ�����Ķ�̬�ֵ���
ֱ������26�������ɡ��ռ��Ϻܱ�����
�´������Զ�̬�ֵ�����
*/

#include<cstdio>
#include<cstring>
#include<cstdlib>

struct node {
    int cnt;
    node *nxt[26];

    node() { memset(this, 0, sizeof(node)); }

    void insert(char *s)//�����ַ���
    {
        node *p = this;
        int id;
        while (*s) {
            id = *s - 'a';
            if (!p->nxt[id])
                p->nxt[id] = new node;
            p = p->nxt[id];
            p->cnt++;
            s++;
        }
    }

    int query(char *s)//ѯ���ַ���
    {
        node *p = this;
        int id;
        while (*s) {
            id = *s - 'a';
            if (!p->nxt[id])
                return 0;
            p = p->nxt[id];
            s++;
        }
        return p->cnt;
    }
};

int main() {
    char s[15];
    node Trie;
    while (gets(s) && strcmp(s, ""))
        Trie.insert(s);
    while (gets(s) && strcmp(s, ""))
        printf("%d\n", Trie.query(s));
    return 0;
}

