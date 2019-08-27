#include<bits/stdc++.h>

using namespace std;
/*http://www.51nod.com/onlineJudge/questionCode.html#!problemId=1027
c++
31 ms
14376 KB
*/
const int maxn = 1 << 18;
typedef complex<double> C;

C wn(int n, int f) {
    return C(cos(acos(-1.0) / n), f * sin((acos(-1.0)) / n));
}

C inv(int n) {
    return C(1.0 / n, 0);
}

C a[maxn], b[maxn], c[maxn];
int g[maxn];

void FFT(C *a, int n, int f) {
    for (int i = 0; i < n; i++)if (i > g[i])swap(a[i], a[g[i]]);
    for (int i = 1; i < n; i <<= 1) {
        C w = wn(i, f), x, y;
        for (int j = 0; j < n; j += i + i) {
            C e;
            e = 1;
            for (int k = 0; k < i; e = e * w, k++) {
                x = a[j + k];
                y = a[j + k + i] * e;
                a[j + k] = x + y;
                a[j + k + i] = x - y;
            }
        }
    }
    if (f == -1) {
        C Inv = inv(n);
        for (int i = 0; i < n; i++)a[i] = a[i] * Inv;
    }
}

void conv(C *a, int n, C *b, int m, C *c) {
    int k = 0, s = 2;
    while ((1 << k) < max(n, m) + 1)k++, s <<= 1;
    for (int i = 1; i < s; i++)g[i] = (g[i / 2] / 2) | ((i & 1) << k);
    FFT(a, s, 1);
    FFT(b, s, 1);
    for (int i = 0; i < s; i++)c[i] = a[i] * b[i];
    FFT(c, s, -1);
}

int main() {
    int n, m;
    char str1[1005], str2[1005];
    scanf("%s%s", str1, str2);
    n = strlen(str1);
    m = strlen(str2);

    for (int i = n - 1; i >= 0; i--)
        a[n - 1 - i] = str1[i] - '0';//a存入第一个多项式的0到n次项系数
    for (int i = m - 1; i >= 0; i--)
        b[m - 1 - i] = str2[i] - '0';//b存入第二个多项式的0到m次项系数。
    conv(a, n - 1, b, m - 1, c);//计算多项式乘法，答案存入c
    int ans[2505], lim = 0, tmp = 0;
    memset(ans, 0, sizeof ans);
    for (int i = 0; i <= n + m - 2; i++)
        ans[i] = (int) round(c[i].real());

    for (int i = 0, cur; i <= n + m - 2 || tmp; i++) {
        cur = (ans[i] + tmp) % 10;
        tmp = (ans[i] + tmp) / 10;
        ans[i] = cur;
        lim = i;
    }
    for (int i = lim; i >= 0; i--)
        printf("%d", ans[i]);
    puts("");
    return 0;
}