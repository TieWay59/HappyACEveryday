#define _debug(x) cerr<<#x<<" = "<<x<<endl

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

template<typename _Tp>
_Tp fpow(_Tp base, _Tp exp, _Tp Mod) {
    _Tp res = 1;
    while (exp) {
        if (exp & 1)res = res * base % Mod;
        base = base * base % Mod;
        exp >>= 1;
    }
    return res;
}
/*

// O(MlogN) O(1) Large N,M prime Mod
template<typename _Tp, const int BCSize> //add Mod as parameter;
struct Binomial_Coefficient {
    _Tp fac[BCSize + 1];
    _Tp inv[BCSize + 1];
    _Tp Mod;

    inline Binomial_Coefficient(const int &m) {    //add Mod as parameter;
        fac[0] = 1;
        Mod = m;
        for (int i = 1; i <= BCSize; i++)
            fac[i] = fac[i - 1] * i % Mod;

        inv[BCSize] = fpow<_Tp>(fac[BCSize], Mod - 2, Mod);
        // printf inv[BCSize] to get & save it;

        for (int i = BCSize - 1; ~i; i--)
            inv[i] = inv[i + 1] * (i + 1) % Mod;
    }

    inline _Tp operator()(const int &n, const int &m) {
        return fac[n] * inv[m] % Mod * inv[n - m] % Mod;
    }

    inline _Tp operator()(int n, int m, const int &mod) {
        this->Mod = mod;//if change mod;
        _Tp res = 1;
        while (n | m)res = res * (*this)(n % Mod, m % Mod) % Mod, n /= Mod, m /= Mod;
        return res;
    }
};

typedef Binomial_Coefficient<long long, 10000000> zuHeShu;
zuHeShu C = zuHeShu(1000000007);
*/

//********in normal writing style***********

const int MAXN = 1e6 + 59;
const int MOD = 1e9 + 7;
ll fac[MAXN];
ll inv[MAXN];

inline void initC(const int &sz) {
    fac[0] = 1;
    for (int i = 1; i <= sz; i++)
        fac[i] = fac[i - 1] * i % MOD;
    inv[sz] = fpow<ll>(fac[sz], MOD - 2, MOD);
    // printf inv[BCSize] to get & save it;
    for (int i = sz - 1; ~i; i--)
        inv[i] = inv[i + 1] * (i + 1) % MOD;
}

inline ll C(const int &n, const int &m) {
    return fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}

// Lucas
inline ll C(int n, int m, const int &P) {
    ll res = 1;
    while (n | m)res = res * C(n % P, m % P) % P, n /= P, m /= P;
    return res;
}

int main() {

    initC(100000);

    cout << C(4, 3, 1000000007) << endl;
    cout << C(4, 1, 1000000007) << endl;
    //cout << C(2, 5) << endl;
    cout << C(5, 2, 1000000007) << endl;


    return 0;
}
/*




 * */