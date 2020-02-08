/**
  *    █████╗  ██████╗       ██████╗ ██╗     ███████╗
  *   ██╔══██╗██╔════╝       ██╔══██╗██║     ╚══███╔╝
  *   ███████║██║            ██████╔╝██║       ███╔╝
  *   ██╔══██║██║            ██╔═══╝ ██║      ███╔╝
  *   ██║  ██║╚██████╗▄█╗    ██║     ███████╗███████╗
  *   ╚═╝  ╚═╝ ╚═════╝╚═╝    ╚═╝     ╚══════╝╚══════╝
  *
  *  @Author: TieWay59
  *  @Created: 2020/2/8 12:35
  *  @Link: https://vjudge.net/contest/355794?tdsourcetag=s_pctim_aiomsg#problem/A
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
const int MAXN = 2e5 + 59;
const int MOD = 1e9 + 7;
const int INF = 0x3F3F3F3F;
const ll llINF = 0x3F3F3F3F3F3F3F3F;
using namespace std;

ll fpow(ll a, ll b, ll mod = MOD) {
    ll ret = 1;
    while (b) {
        if (b & 1)ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}

vector<int> a;
vector<pair<int, int >> s;
vector<int> ans;
int n;

void solve(int kaseId = -1) {
    cin >> n;
    ans.assign(n, 0);
    a.assign(n, 0);

    for (auto &ai:a) {
        cin >> ai;
    }

    for (int i = 0; i < n; ++i) {
        while (!s.empty() && s.back().first < a[i]) {
            int j = s.back().second;
            ans[j] = i - j - 1;
            ans[j] = min(ans[j], s.back().first);
            s.pop_back();
        }
        s.emplace_back(a[i], i);
    }
    while (!s.empty()) {
        int j = s.back().second;
        ans[j] = n - 1 - j;
        ans[j] = min(ans[j], s.back().first);
        s.pop_back();
    }

    for (auto ai:ans) {
        cout << ai << " ";
    }

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