#include<bits/stdc++.h>

using namespace std;
/*http://uoj.ac/submissions
这个多项式乘法的模板是求两个多项式的~
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
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; i++)
        scanf("%lf", &a[i]);//a存入第一个多项式的0到n次项系数
    for (int i = 0; i <= m; i++)
        scanf("%lf", &b[i]);//b存入第二个多项式的0到m次项系数。
    conv(a, n, b, m, c);//计算多项式乘法，答案存入c
    for (int i = 0; i <= n + m; i++)
        printf("%d ", (int) round(c[i].real()));//答案记得输出实部四舍五入

    return 0;
}

