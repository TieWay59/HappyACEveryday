/**
  *    █████╗  ██████╗       ██████╗ ██╗     ███████╗
  *   ██╔══██╗██╔════╝       ██╔══██╗██║     ╚══███╔╝
  *   ███████║██║            ██████╔╝██║       ███╔╝
  *   ██╔══██║██║            ██╔═══╝ ██║      ███╔╝
  *   ██║  ██║╚██████╗▄█╗    ██║     ███████╗███████╗
  *   ╚═╝  ╚═╝ ╚═════╝╚═╝    ╚═╝     ╚══════╝╚══════╝
  *
  *  @Author: TieWay59
  *  @Created: 2020/2/13 17:22
  *  @Link: https://vjudge.net/contest/356796#problem/J
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
typedef unsigned long long ull;
const int MAXN = 4e4 + 59;
const int MOD = 1e9 + 7;
const int INF = 0x3F3F3F3F;
const ll llINF = 0x3F3F3F3F3F3F3F3F;
using namespace std;

int n, m;
char s[MAXN];
const ull p = 19491001;
int Pos = -1;
ull h[MAXN];
ull v[MAXN];
pair<ull, int> tmp[MAXN];

void hush() {
    h[0] = s[0];
    v[0] = 1;
    for (int i = 1; i < n; ++i) {
        h[i] = h[i - 1] * p + s[i];
        v[i] = v[i - 1] * p;
    }
}


bool check(const int &len) {
    Pos = -1;
    memset(tmp, 0, sizeof tmp);
    for (int i = 0; i + len <= n; ++i) {
        ull r = h[i + len - 1] - (i == 0 ? 0 : h[i - 1] * v[len]);
        tmp[i] = make_pair(r, i);
    }
    sort(tmp, tmp + n - len + 1);

    for (int i = 0, j = 0; i < n - len + 1; ++i) {
        if (tmp[j].first == tmp[i].first) {
            tmp[j].second = max(tmp[j].second, tmp[i].second);
        } else {
            j = i;
        }
        if (i - j + 1 >= m) Pos = max(Pos, tmp[j].second);
    }
    return Pos != -1;
}

void solve(int kaseId = -1) {
    while (scanf("%d", &m) && m != 0) {
        scanf("%s", s);
        n = strlen(s);
        hush();
        int l = 1, r = n;
        int ans = 0, pos = -1, mid = 0;
        while (l <= r) {
            mid = (l + r) >> 1;
            if (check(mid)) {
                ans = mid;
                pos = Pos;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if (pos == -1)
            puts("none");
        else
            printf("%d %d\n", ans, pos);
    }
}

void solves() {
    MULTIKASE {
        solve(kase);
    }
}

int main() {
//    STOPSYNC;
    solve();
    return 0;
}
/*

 */