/*
*  https://nanti.jisuanke.com/t/41402
*
*/
//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <tuple>

#define  _debug(x) cerr<<#x<<" = "<<x<<endl
using namespace std;
typedef long long ll;
const int MAXN = 2e3 + 59;
const int MAXM = 2e5 + 59;
const ll MOD = 998244353;
const ll INF = 0x0f0f0f0f;

int kase;
int n, m;

// 1 6 12 40
int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);

    scanf("%d", &n);
    ll ans = 0;
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= n; ++j) {
            for (ll k = 1; k <= n; ++k) {
                for (ll l = 1; l <= n; ++l) {
                    for (ll i1 = 1; i1 <= n; ++i1) {
                        for (int k1 = 1; k1 <= n; ++k1) {
                            for (int l1 = 1; l1 <= n; ++l1) {
                                for (int m1 = 1; m1 <= n; ++m1) {

                                    if (i + j + k + l + i1 + k1 + l1 + m1 == i * j * k * l * i1 * k1 * l1 * m1) {
//                                _debug(i);
//                                _debug(j);
//                                _debug(k);
//                                _debug(l);
//                                _debug(i1);
//                                cerr << "===================" << endl;
                                        ans++;
                                    }
                                }
                            }

                        }
                    }
                }
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}