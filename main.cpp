/**
  *    █████╗  ██████╗       ██████╗ ██╗     ███████╗
  *   ██╔══██╗██╔════╝       ██╔══██╗██║     ╚══███╔╝
  *   ███████║██║            ██████╔╝██║       ███╔╝
  *   ██╔══██║██║            ██╔═══╝ ██║      ███╔╝
  *   ██║  ██║╚██████╗▄█╗    ██║     ███████╗███████╗
  *   ╚═╝  ╚═╝ ╚═════╝╚═╝    ╚═╝     ╚══════╝╚══════╝
  *
  *  @Author: TieWay59
  *  @Created: 2020/1/17 14:00
  *  @Link: https://pintia.cn/problem-sets/1217973933671833600/problems/1217974362208067586
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

int solveMax(int n, int a, int b, int c, int d, string s) {
    int res = 0;
    int cntUnshieldUnits = 0;
    for (const auto &si:s) {
        if (si == '1') {
            if (c > 0) {
                c--;
                res++;
            } else if (d > 0) {
                d--;
                c++;
            } else if (a > 0) {
                a--;
                res++;
            } else {
                if (cntUnshieldUnits > 0) {
                    cntUnshieldUnits--;
                    res++;
                } else {
                    b--;
                    cntUnshieldUnits++;
                }
            }
        } else {
            if (d > 0) {
                d--;
                c++;
                // can't kill;
            } else if (c > 0) {
                // can't kill;
                // can't alt
            } else if (b > 0) {
                b--;
                cntUnshieldUnits++;
            }
        }
    }
    return res;
}

int solveMin(int n, int a, int b, int c, int d, string s) {
    int res = 0;
    int cntUnshieldUnits = 0;
    for (const auto &si:s) {
        if (si == '1') {
            if (d > 0) {
                d--;
                c++;
            } else if (c > 0) {
                c--;
                res++;
            } else if (b > 0) {
                b--;
                a++;
            } else if (a > 0) {
                a--;
                res++;
            }
        } else {
            if (c > 0) {
                // can't kill;
                // can't alt
            } else if (d > 0) {
                d--;
                c++;
            } else if (d > 0) {
                d--;
                c++;
                // can't kill;
            } else if (a > 0) {

            } else if (b > 0) {
                b--;
                a++;
            }
        }
    }
    return res;
}

void solve(int kaseId = -1) {
    int n, a, b, c, d;
    string s;
    cin >> n >> a >> b >> c >> d >> s;
    int ans1 = solveMax(n, a, b, c, d, s);
    int ans2 = solveMin(n, a, b, c, d, s);

    cout << ans1 << " " << ans2 << endl;
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