
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 105;
ll H, h, m, s;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

struct Frac {
public:
    ll n, d;

    void norm() {
        ll g = gcd(n, d);
        n /= g;
        d /= g;
        if (d < 0)n = -n, d = -d;
    }//0
    Frac() {}

    Frac(ll n, ll d) : n(n), d(d) { norm(); }

    bool operator<(const Frac &T) const { return n * T.d < d * T.n; }

    bool operator>(const Frac &T) const { return n * T.d > d * T.n; }

    bool operator==(const Frac &T) const { return n * T.d == d * T.n; }

    Frac operator+(const Frac &T) const { return Frac(n * T.d + d * T.n, d * T.d); }

    Frac operator-(const Frac &T) const { return Frac(n * T.d - d * T.n, d * T.d); }

    Frac operator*(const Frac &T) const { return Frac(n * T.n, d * T.d); }

    Frac operator/(const Frac &T) const { return Frac(n * T.d, d * T.n); }

    Frac operator+(ll t) const { return Frac(n + t * d, d); }

    Frac operator-(ll t) const { return Frac(n - t * d, d); }

    Frac operator*(ll t) const { return Frac(n * t, d); }

    Frac operator/(ll t) const { return Frac(n, d * t); }

    Frac operator=(ll t) {
        *this = Frac(t, 1);
        return *this;
    }
};

bool chek(Frac fa, Frac fb, Frac fc) {
    fa.n %= fa.d;
    fb.n %= fb.d;
    fc.n %= fc.d;
    return !(fa == fb || fb == fc || fc == fa);
}

int main() {
    Frac dh, dm, ds;
    Frac _h, _m, _s;
    _s = Frac(1, 60);
    _m = Frac(1, 3600);
    Frac ans;
    while (scanf("%lld%lld%lld%lld", &H, &h, &m, &s) && H + h + m + s) {
        _h = Frac(1, H * 3600);
        ds = Frac(s, 60);
        dm = ds / 60 + Frac(m, 60);
        dh = dm / H + Frac(h, H);
        ans = Frac(3600, 1);
        for (ll k = -2; k <= 2; k++) {
            Frac a, b, x;
            a = _h + _m - _s * 2;
            b = ds * 2 + k - dm - dh;
            if (a.n != 0) {
                x = b / a;
                //printf("%lld %lld",x.n,x.d);
                if (x.n >= 0 && x < ans && chek(ds + _s * x, dm + _m * x, dh + _h * x))
                    ans = x;
            }
        }
        ans = ans + s;
        ll n = ans.n, d = ans.d;
        m += n / d / 60;
        n %= d * 60;
        h += m / 60;
        m %= 60;
        h %= H;
        printf("%lld %lld %lld %lld\n", h, m, n, d);
    }
    return 0;
}
/*
12 0 0 0
12 11 59 59
12 1 56 0
12 1 56 3
12 1 56 34
12 3 9 43
12 3 10 14
12 7 17 58
12 7 18 28
12 7 23 0
12 7 23 31
2 0 38 29
2 0 39 0
2 0 39 30
2 1 6 20
2 1 20 1
2 1 20 31
3 2 15 0
3 2 59 30
4 0 28 48
5 1 5 40
5 1 6 10
5 1 7 41
11 0 55 0
0 0 0 0
*/
