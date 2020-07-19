/**
  *    █████╗  ██████╗       ██████╗ ██╗     ███████╗
  *   ██╔══██╗██╔════╝       ██╔══██╗██║     ╚══███╔╝
  *   ███████║██║            ██████╔╝██║       ███╔╝
  *   ██╔══██║██║            ██╔═══╝ ██║      ███╔╝
  *   ██║  ██║╚██████╗▄█╗    ██║     ███████╗███████╗
  *   ╚═╝  ╚═╝ ╚═════╝╚═╝    ╚═╝     ╚══════╝╚══════╝
  *
  *  @Author: TieWay59
  *  @Created: 2020/1/13 13:48
  *  @Link: https://pintia.cn/problem-sets/1216577066538311680/problems/1216577133471023104
  *  @Tags: math
  *
  *******************************************************/

#include <bits/stdc++.h>

#ifdef DEBUG

#   include "libs59/debugers.h"
//  #define debug(x)  cerr <<#x << " = "<<x<<endl;
#else
#   define endl '\n'
#   define debug(x)  59
#endif

#define STOPSYNC ios::sync_with_stdio(false);cin.tie(nullptr)
#define MULTIKASE int Kase=0;cin>>Kase;for(int kase=1;kase<=Kase;kase++)
typedef long long ll;
const int MAXN = 2e6 + 59;
const int MOD = 1e9 + 7;
const int INF = 0x3F3F3F3F;
const ll llINF = 0x3F3F3F3F3F3F3F3F;
using namespace std;

char s[MAXN];
int n;
double pre1[MAXN];
double pre2[MAXN];
double ans;

void solve(int kaseId = -1) {
    cin >> (s + 1);
    n = strlen(s + 1);

    for (int i = 1; i <= n; ++i) {
        pre1[i] = pre1[i - 1] + 1.0 / (double) i;
    }

    for (int i = n, j = 1; i >= 1; --i, j++) {
        pre2[j] = pre2[j - 1] + (double) j / (double) i;
    }

    set<char> check = {'a', 'e', 'i', 'o', 'u', 'y'};

    for (int i = 1, j; i <= n; ++i) {
        j = i;
        if (check.count(s[j]) > 0) {
            debug(j);
            if (j > n / 2)
                j = n - j + 1;

            ans += j - 1 +
                   pre2[j - 1] +
                   (pre1[n - j + 1] - pre1[j - 1]) * j;
            debug(j - 1);
            debug(pre2[j - 1]);
            debug((pre1[n - j + 1] - pre1[j - 1]) * j);
        }
    }
    //  n*(n+1)/2;
    debug(ans);
    ans /= (double) n;
    ans /= (double) (n + 1);
    ans *= 2.0;
    cout << setprecision(9) << ans << endl;
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

 */