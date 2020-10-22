
/**
 *  @Source: https://caojiangxia.github.io/Meissel-Lehmer/
 *  @Author: caojiangxia Meissel-Lehmer算法
 *  @Complexity: $O(n^{\frac{2}{3}})$
 *  @Description:
 *      求素数的个数
 *      init();
 *      ans = lehmer_pi(n);
 *
 *  @Example:
 *      lehmer_pi(10) := 7
 *
 *  @Verification:
 *      https://ac.nowcoder.com/acm/contest/8051/C
 *      求素数幂和。
 */

//
typedef long long LL;
const int N = 3.2e5; // $sqrt(MAXN)$
bool np[N];
int prime[MAXN], pi[N];

int getprime() {
    int cnt = 0;
    np[0] = np[1] = true;
    pi[0] = pi[1] = 0;
    for (int i = 2; i < N; ++i) {
        if (!np[i]) prime[++cnt] = i;
        pi[i] = cnt;
        for (int j = 1; j <= cnt && i * prime[j] < N; ++j) {
            np[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
    prime[0] = cnt;
    return cnt;
}

const int M = 2;//为了减小内存可以不过是质数
const int PM = 2 * 3 * 5;//为了减小内存可以不过要按质数减小如去掉17
int phi[PM + 1][M + 1], sz[M + 1];

void init() {
    getprime();
    sz[0] = 1;
    for (int i = 0; i <= PM; ++i) phi[i][0] = i;
    for (int i = 1; i <= M; ++i) {
        sz[i] = prime[i] * sz[i - 1];
        for (int j = 1; j <= PM; ++j) phi[j][i] = phi[j][i - 1] - phi[j / prime[i]][i - 1];
    }
}

int sqrt2(LL x) {
    LL r = (LL) sqrt(x - 0.1);
    while (r * r <= x) ++r;
    return int(r - 1);
}

int sqrt3(LL x) {
    LL r = (LL) cbrt(x - 0.1);
    while (r * r * r <= x) ++r;
    return int(r - 1);
}

LL getphi(LL x, int s) {
    if (s == 0) return x;
    if (s <= M) return phi[x % sz[s]][s] + (x / sz[s]) * phi[sz[s]][s];
    if (x <= prime[s] * prime[s]) return pi[x] - s + 1;
    if (x <= prime[s] * prime[s] * prime[s] && x < N) {
        int s2x = pi[sqrt2(x)];
        LL ans = pi[x] - (s2x + s - 2) * (s2x - s + 1) / 2;
        for (int i = s + 1; i <= s2x; ++i) ans += pi[x / prime[i]];
        return ans;
    }
    return getphi(x, s - 1) - getphi(x / prime[s], s - 1);
}

LL getpi(LL x) {
    if (x < N) return pi[x];
    LL ans = getphi(x, pi[sqrt3(x)]) + pi[sqrt3(x)] - 1;
    for (int i = pi[sqrt3(x)] + 1, ed = pi[sqrt2(x)]; i <= ed; ++i) ans -= getpi(x / prime[i]) - i + 1;
    return ans;
}

LL lehmer_pi(LL x) {//小于等于n的素数有多少个
    if (x < N) return pi[x];
    int a = (int) lehmer_pi(sqrt2(sqrt2(x)));
    int b = (int) lehmer_pi(sqrt2(x));
    int c = (int) lehmer_pi(sqrt3(x));
    LL sum = getphi(x, a) + (LL) (b + a - 2) * (b - a + 1) / 2;
    for (int i = a + 1; i <= b; i++) {
        LL w = x / prime[i];
        sum -= lehmer_pi(w);
        if (i > c) continue;
        LL lim = lehmer_pi(sqrt2(w));
        for (int j = i; j <= lim; j++) sum -= lehmer_pi(w / prime[j]) - (j - 1);
    }
    return sum;
}