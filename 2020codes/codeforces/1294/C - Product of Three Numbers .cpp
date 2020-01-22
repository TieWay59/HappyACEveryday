/**
  *    █████╗  ██████╗       ██████╗ ██╗     ███████╗
  *   ██╔══██╗██╔════╝       ██╔══██╗██║     ╚══███╔╝
  *   ███████║██║            ██████╔╝██║       ███╔╝
  *   ██╔══██║██║            ██╔═══╝ ██║      ███╔╝
  *   ██║  ██║╚██████╗▄█╗    ██║     ███████╗███████╗
  *   ╚═╝  ╚═╝ ╚═════╝╚═╝    ╚═╝     ╚══════╝╚══════╝
  *
  *  @Author: TieWay59
  *  @Created: 2020/1/22 22:53
  *  @Link: http://m3.codeforces.com/contest/1294/problem/C
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

void solve(int kaseId = -1) {
    ll n;
    cin >> n;

    vector<ll> ans;
    bool found = false;

    for (ll a = 2; a * a <= n; ++a) {
        if (n % a != 0)continue;
        ans.emplace_back(a);
        for (ll b = 2; b * b <= n / a; ++b) {

            if ((n / a) % b != 0 || a == b)continue;
            ans.emplace_back(b);

            if (n / a / b != a && n / a / b != b && n / a / b >= 2) {
                found = true;
                ans.emplace_back(n / a / b);
            }

            if (!found)ans.pop_back();
            else break;
        }

        if (!found)ans.pop_back();
        else break;
    }

    if (found) {
        cout << "YES" << endl;
        cout << ans.at(0) << " " << ans.at(1) << " " << ans.at(2) << endl;
    } else {
        cout << "NO" << endl;
    }

}

void solves() {
    MULTIKASE {
        solve(kase);
    }
}

int main() {
    STOPSYNC;
    solves();
    return 0;
}
/*

 */