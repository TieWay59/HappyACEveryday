#include<bits/stdc++.h>

using namespace std;
/*
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

int ans[155555];
int n, m;
int neg1, neg2;
char str1[50005], str2[50005];

int main() {
    while (scanf("%s%s", str1, str2) != EOF) {
        neg1 = neg2 = 0;
        n = strlen(str1);
        m = strlen(str2);
        if (str1[n - 1] == '0' || str2[m - 1] == '0') {
            puts("0");
            continue;
        }
        if (str1[0] == '-')
            str1[0] = '0', neg1 = 1;
        if (str2[0] == '-')
            str2[0] = '0', neg2 = 1;

        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        memset(c, 0, sizeof c);
        for (int i = n - 1, j = 0; i >= neg1; j++, i--)
            a[j] = str1[i] - '0';
        if (neg1)n--;
        for (int i = m - 1, j = 0; i >= neg2; j++, i--)
            b[j] = str2[i] - '0';
        if (neg2)m--;

        conv(a, n - 1, b, m - 1, c);

        int lim = 0, tmp = 0;
        memset(ans, 0, sizeof ans);
        for (int i = 0; i <= n + m - 2; i++)
            ans[i] = (int) round(c[i].real());

        for (int i = 0, cur; i <= n + m - 2 || tmp; i++) {
            cur = (ans[i] + tmp) % 10;
            tmp = (ans[i] + tmp) / 10;
            ans[i] = cur;
            lim = i;
        }//printf(":%d:",neg);
        if (neg1 ^ neg2)putchar('-');

        for (int i = lim; i >= 0; i--)
            printf("%d", ans[i]);
        puts("");
    }
    return 0;
}

