/*
*  https://nanti.jisuanke.com/t/41414
*/
//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <tuple>

#define  _debug(x) cerr<<#x<<" = "<<x<<endl
using namespace std;
typedef __int128 ll;
typedef __int128 lll;
const int MAXN = 1e5 + 59;
const int MAXM = 2e5 + 59;
const ll MOD = 998244353;
const ll INF = 0x0f0f0f0f;

template<const int BCSize = 26, typename var = __int128> //add Mod as parameter;
struct Binomial_Coefficient {
    var c[BCSize + 1][BCSize + 1];
    //Pascal's Triangle

    Binomial_Coefficient() {    //add Mod as parameter;
        c[0][0] = 1;
        for (int n = 1; n <= BCSize; ++n) {
            c[n][0] = c[n][n] = 1;
            for (int k = 1; k < n; ++k)
                c[n][k] = (c[n - 1][k - 1] + c[n - 1][k]);//%
        }
    }

    var operator()(const int &n, const int &m) {
        if (n < m)return -1;//in case.
        return c[n][m];
    }
};

Binomial_Coefficient<120, lll> C;

ll G[33][33];//n,x

ll fpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1)res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

template<typename tp>
inline void read(tp &x) {
    char ch;
    bool flag = false;
    for (ch = getchar(); !isdigit(ch); ch = getchar())if (ch == '-') flag = true;
    for (x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    x = flag ? -x : x;
}

inline void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}

int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
    print(C(120, 60));
    puts("");
    print(C(80, 40));
    puts("");
    print(C(60, 30));
    puts("");


    for (int k = 0; k <= 26; ++k)
        G[0][k] = 1;

    for (int n = 1; n <= 26; ++n)
        for (int k = 0; k < n; k++)
            G[n][0] += C(n - 1, k) * G[k][0];

    for (int n = 1; n <= 26; ++n)
        for (int x = 1; x <= 26; ++x)
            for (int i = 0; i <= n; ++i)
                G[n][x] = (G[n][x] + C(n, i) * fpow(x, i) * G[n - i][0]);

    //print(G[26][0]);


    int kase = 0, Kase;
    read(Kase);
    int n;
    lll k;
    char ans[33];

    while (kase++ < Kase) {
        read(n);
        read(k);
        memset(ans, 0, sizeof ans);
        //print(k);

        for (int i = 0, cnt = 0, used = 'A' - 1; i < n; ++i) {
            for (int c = 'A'; c <= 'Z'; c++) {
                if (k <= G[n - i - 1][cnt + (c > used)]) {

                    ans[i] = c;
                    used = max(c, used);
                    cnt = used - 'A' + 1;

                    break;
                } else {

                    k -= G[n - i - 1][cnt + (c > used)];
                }
            }
        }

        printf("Case #%d: %s\n", kase, ans);
    }

    return 0;
}