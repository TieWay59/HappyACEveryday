/**
  *    █████╗  ██████╗       ██████╗ ██╗     ███████╗
  *   ██╔══██╗██╔════╝       ██╔══██╗██║     ╚══███╔╝
  *   ███████║██║            ██████╔╝██║       ███╔╝
  *   ██╔══██║██║            ██╔═══╝ ██║      ███╔╝
  *   ██║  ██║╚██████╗▄█╗    ██║     ███████╗███████╗
  *   ╚═╝  ╚═╝ ╚═════╝╚═╝    ╚═╝     ╚══════╝╚══════╝
  *
  *  @Author: TieWay59
  *  @Created: 2019/11/23 19:05
  *  @Link: https://www.cometoj.com/contest/79/problem/A?problem_id=4198
  *  @Tags:
  *
  *******************************************************/


#include <bits/stdc++.h>

#ifdef DEBUG
//#define debug(x)  cerr <<#x << " = "<<x<<endl;
#include "libs59/debugers.h"

#else
#define endl '\n'
#define debug(x)  59
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
    string v;
    cin >> v;
    bool valid = true;
    for (int i = 1; i < v.length(); ++i) {
        if (v[i - 1] > v[i]) {
            valid = false;
            break;
        }
    }
    if (!valid) {
        cout << "Impossible" << endl;
    } else {
        v.erase(unique(v.begin(), v.end()), v.end());
        v = "0" + v;
        debug(v);
        int ans = 0;
        for (int i = 1, x = 0; i < v.length(); i++) {
            ans += (int) v[i] - v[i - 1];
        }
        if (ans > 9) {
            cout << "Impossible" << endl;
        } else {
            cout << ans << endl;
        }
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