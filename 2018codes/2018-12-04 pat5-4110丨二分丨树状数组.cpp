#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;
int n;
int num[MAXN];
int stk[MAXN], top;
char op[25];

void add(int x, int val) {
    while (x < MAXN) {
        num[x] += val;
        x += x & -x;
    }
}

int ask(int x) {
    int res = 0;
    while (x) {
        res += num[x];
        x -= x & -x;
    }
    return res;
}

int bit(int x) {
    int l = 1, r = 100000, m;
    while (l < r) {
        m = (l + r) >> 1;
        if (ask(m) < x) l = m + 1;
        else r = m;//�ؼ�
    }
    return r;
}

int main() {
    scanf("%d", &n);

    for (int i = 1, key; i <= n; i++) {
        scanf("%s", op);
        if (op[1] == 'o') {
            if (top) {
                printf("%d\n", stk[top]);
                add(stk[top], -1);
                top--;
            } else puts("Invalid");
        } else if (op[1] == 'e') {
            if (top) printf("%d\n", bit((top + 1) / 2));
            else puts("Invalid");
        } else {
            scanf("%d", &key);
            stk[++top] = key;
            add(stk[top], 1);
        }
    }
    return 0;
}
/*
*/
