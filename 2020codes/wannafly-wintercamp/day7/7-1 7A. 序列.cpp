/**
  *    █████╗  ██████╗       ██████╗ ██╗     ███████╗
  *   ██╔══██╗██╔════╝       ██╔══██╗██║     ╚══███╔╝
  *   ███████║██║            ██████╔╝██║       ███╔╝
  *   ██╔══██║██║            ██╔═══╝ ██║      ███╔╝
  *   ██║  ██║╚██████╗▄█╗    ██║     ███████╗███████╗
  *   ╚═╝  ╚═╝ ╚═════╝╚═╝    ╚═╝     ╚══════╝╚══════╝
  *
  *  @Author: TieWay59
  *  @Created: 2020/1/18 14:44
  *  @Link: https://pintia.cn/problem-sets/1218331719966515200/problems/1218332009230884871
  *  @Tags:
  *
  *******************************************************/

#include <bits/stdc++.h>

#ifdef DEBUG

#   include "libs59/debugers.h"
//  #define debug(x)  cerr <<#x << " = "<<x<<endl;
#else
#   define endl '\n'
#   define debug(...)
#endif

#define STOPSYNC ios::sync_with_stdio(false);cin.tie(nullptr)
#define MULTIKASE int Kase=0;cin>>Kase;for(int kase=1;kase<=Kase;kase++)
typedef long long ll;
const int MAXN = 5e3 + 59;
const int MOD = 1e9 + 7;
const int INF = 0x3F3F3F3F;
const ll llINF = 0x3F3F3F3F3F3F3F3F;
using namespace std;

bool isCoprime[MAXN][MAXN];
ll n, m;
ll cnt = 0;

void solve(int kaseId = -1) {
    cin >> n;

    if (n == 1) {
        cout << "0/1" << endl;
        return;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (__gcd(i, j) == 1) {
                isCoprime[i][j] = true;
                isCoprime[j][i] = true;
                cnt += 2;
                debug(i, j);
                debug(j, i);
            }
        }
    }

    ll ans_n = cnt;
    ll ans_d = 2 * (n - 1);
    if (n & 1) {
        ans_n *= (n - 1);
        ans_d *= n;
    }

    ll d = __gcd(ans_d, ans_n);
    ans_d /= d;
    ans_n /= d;

    cout << ans_n << '/' << ans_d << endl;
}

void solves() {
    MULTIKASE {
        solve(kase);
    }
}

int main() {
    STOPSYNC;
    solve();
    return 0;
}
/*
    if N is even then:
        comment: cnt * [ 1 * (n-2)! * (n/2) ] / n!
        answer := cnt / ( 2 * n - 2 )

    else then:
        comment: cnt * [ 1 * (n-2)! * (n/2) * ((n-1)/n)] / n!
                diff in the pairs sequence position.
        answer := cnt * ( n - 1 ) / n * ( 2 * n - 2 )

    end if;

 */