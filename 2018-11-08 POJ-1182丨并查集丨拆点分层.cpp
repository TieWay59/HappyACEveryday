/*
https://blog.csdn.net/lisong_jerry/article/details/80029967
��㲢�鼯��
ԭ����ÿ��������˳������ԣ���һ��������ĸ�����ͬһ���ϡ�
ÿ����������������ԣ���һ���������������ͬһ������
���԰ѵ��������㣬��ÿ������ӵ����������㣬
������ĺϲ����ԣ�ʹ��ÿ�������������
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>

typedef long long ll;
const int N = 150005;
const int mod = 1e9 + 7;
int f[N];

int getf(int x) {
    if (x == f[x]) return f[x];
    return f[x] = getf(f[x]);
}

bool same(int x, int y) {
    return getf(x) == getf(y);
}

void unif(int x, int y) {
    if (!same(x, y))f[f[x]] = f[y];//���Ƽ�д����
}

int n, k, ans;

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n * 3; i++)f[i] = i;
    while (k--) {
        int op, a, b;
        scanf("%d%d%d", &op, &a, &b);
        if (a > n || b > n) {
            ans++;
            continue;
        }
        if (op == 2 && a == b) {
            ans++;
            continue;
        }
        if (op == 1) {
            if (same(a, b + n) || same(a + n, b)) {
                ans++;
            } else {
                unif(a, b);
                unif(a + n, b + n);
                unif(a + n * 2, b + n * 2);
            }
        }
        if (op == 2) {
            if (same(a, b) || same(a + n, b)) {
                ans++;
            } else {
                unif(a, b + n);
                unif(a + n, b + n * 2);
                unif(a + n * 2, b);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
/*
2
1 1
4 2 3 5 10
*/
