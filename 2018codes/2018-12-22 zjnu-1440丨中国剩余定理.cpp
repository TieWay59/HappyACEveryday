#include <stdio.h>

typedef long long LL;
const int MAXN = 100010;
using namespace std;


LL GCD(LL a, LL b) {
    return b ? GCD(b, a % b) : a;
}

LL ExpGcd(LL a, LL b, LL &X, LL &Y) {
    LL q, temp;
    if (!b) {
        q = a;
        X = 1;
        Y = 0;
        return q;
    } else {
        q = ExpGcd(b, a % b, X, Y);
        temp = X;
        X = Y;
        Y = temp - (a / b) * Y;
        return q;
    }
}

LL Product_Mod(LL a, LL b, LL mod) {
    LL sum = 0;
    LL flag = b >= 0 ? 1 : -1;
    if (flag < 0) {
        b = -b;
    }
    while (b) {
        if (b & 1) sum = (sum + a) % mod;
        a = (a + a) % mod;
        b >>= 1;
    }
    return (sum * flag + mod) % mod;
}

LL chineseRemain(int n, LL mod[], LL rem[]) {
    LL lcm = 1;
    int i;
    for (i = 0; i < n; ++i) {
        if (mod[i] < 0) {
            mod[i] = -mod[i];
        }
        rem[i] = (rem[i] % mod[i] + mod[i]) % mod[i];
    }
    for (i = 0; i < n; i++) {
        LL g = GCD(lcm, mod[i]);
        lcm = lcm / g * mod[i];
    }
    LL A, B, C, X, Y;
    for (i = 1; i < n; i++) {
        A = mod[0];
        B = -mod[i];
        C = rem[i] - rem[0];
        LL g = GCD(A, B);
        if (C % g) {
            return -1;
        }
        A /= g, B /= g, C /= g;
        if (A < 0) {
            A = -A, B = -B, C = -C;
            B = ((B % A) + A) % A;
        }
        ExpGcd(A, B, X, Y);
        Y = Product_Mod(Y, C, A);
        mod[0] = A * mod[i];
        rem[0] = (rem[i] + Product_Mod(mod[i], Y, mod[0])) % mod[0];
    }
    return rem[0];
}

LL m[MAXN], r[MAXN];

int main() {
    int t;
    int i;
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++)
            scanf("%lld", &r[i]);

        for (int i = 0; i < n; i++)
            scanf("%lld", &m[i]);
        printf("%lld\n", chineseRemain(n, m, r));
    }
    return 0;
}

/*
3
107 1
1007 3
10007 5
796407100
*/
