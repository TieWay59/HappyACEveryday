/**
  *    █████╗  ██████╗       ██████╗ ██╗     ███████╗
  *   ██╔══██╗██╔════╝       ██╔══██╗██║     ╚══███╔╝
  *   ███████║██║            ██████╔╝██║       ███╔╝
  *   ██╔══██║██║            ██╔═══╝ ██║      ███╔╝
  *   ██║  ██║╚██████╗▄█╗    ██║     ███████╗███████╗
  *   ╚═╝  ╚═╝ ╚═════╝╚═╝    ╚═╝     ╚══════╝╚══════╝
  *
  *  @Author: TieWay59
  *  @Created: 2020/2/3 3:41
  *  @Link: https://codeforces.com/contest/1291/problem/D
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


inline int ctoi(const char &c) {
    return (int) (c - 'a');
}

char s[MAXN];
int chc[MAXN][26];
int n;

void solve(int kaseId = -1) {

    cin >> (s + 1);
    n = strlen(s + 1);

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 26; ++j) {
            chc[i][j] = chc[i - 1][j];
        }
        chc[i][ctoi(s[i])]++;
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        int ch_c = 0;

        cin >> l >> r;

        for (int i = 0; i < 26; ++i) {
            if (chc[r][i] - chc[l - 1][i] > 0) {
                ch_c++;
            }
        }


        if (ch_c >= 3) {
            cout << "Yes" << endl;
        } else if (ch_c == 1) {
            if (l == r) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        } else {
            if (s[l] != s[r]) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
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
    solve();
    return 0;
}
/*

 */