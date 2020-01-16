/**
  *    █████╗  ██████╗       ██████╗ ██╗     ███████╗
  *   ██╔══██╗██╔════╝       ██╔══██╗██║     ╚══███╔╝
  *   ███████║██║            ██████╔╝██║       ███╔╝
  *   ██╔══██║██║            ██╔═══╝ ██║      ███╔╝
  *   ██║  ██║╚██████╗▄█╗    ██║     ███████╗███████╗
  *   ╚═╝  ╚═╝ ╚═════╝╚═╝    ╚═╝     ╚══════╝╚══════╝
  *
  *  @Author: TieWay59
  *  @Created: 2020/1/16 15:32
  *  @Link: https://pintia.cn/problem-sets/1217641604302602240/problems/1217642214674497536
  *  @Tags:
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
const int MAXN = 2e5 + 59;
const int MOD = 1e9 + 7;
const int INF = 0x3F3F3F3F;
const ll llINF = 0x3F3F3F3F3F3F3F3F;
using namespace std;


int a[MAXN];
int b[8];

void solve(int kaseId = -1) {
    int n, k;
    cin >> n >> k;

    for (int i = 1, m; i <= 4; i <<= 1) {
        cin >> m;
        for (int j = 1, x; j <= m; ++j) {
            cin >> x;
            a[x] |= i;
        }
    }

    for (int i = 1; i <= n; ++i) {
        b[a[i]]++;
    }

    int ans = 0;
    for (int i = 1; i <= 4; i <<= 1) {
        b[i] -= min(b[i], b[7 ^ i]);
        ans = max(ans, b[i]);
        b[i] = 0;
    }

    for (int i = 1; i <= 7; ++i) {
        ans += b[i];
    }

    cout << ans << endl;
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