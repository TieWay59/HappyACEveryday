/*http://acm.hdu.edu.cn/showproblem.php?pid=6153

*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
const int mod = 1000000007;

/* ��� T �� next[]��ע�Ͳο� GetExtend()
T[i]...T[m - 1]��T�����ͬǰ׺���ȣ�
*/
void GetNext(char T[], int &m, int next[]) {
    int a = 0, p = 0;
    next[0] = m;

    for (int i = 1; i < m; i++) {
        if (i >= p || i + next[i - a] >= p) {
            if (i >= p)p = i;
            while (p < m && T[p] == T[p - i])p++;
            next[i] = p - i;
            a = i;
        } else next[i] = next[i - a];
    }
}

/* ��� extend[]
extend[i]�� S[i]...S[n - 1]��T�����ͬǰ׺���ȡ�
*/
void GetExtend(char S[], int &n, char T[], int &m, int extend[], int next[]) {
    int a = 0, p = 0;
    GetNext(T, m, next);

    for (int i = 0; i < n; i++) {
        if (i >= p || i + next[i - a] >= p) { // i >= p �����ã��ٸ��������ӣ�S �� T ��һ�ַ���ͬ
            if (i >= p)p = i;
            while (p < n && p - i < m && S[p] == T[p - i])p++;
            extend[i] = p - i;
            a = i;
        } else extend[i] = next[i - a];
    }
}

int Extend[N], Next[N];
char a[N], b[N];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s %s", a, b);
        int la = strlen(a);
        int lb = strlen(b);
        reverse(a, a + la);
        reverse(b, b + lb);
        GetExtend(a, la, b, lb, Extend, Next);

        ll ans = 0;
        for (int i = 0; i < la; i++)
            ans = (ans + (1ll + Extend[i]) * Extend[i] / 2ll % mod) % mod;

        printf("%lld\n", ans);
        memset(Next, 0, sizeof Next);
        memset(Extend, 0, sizeof Extend);
    }
    return 0;
}

