/**
  *    █████╗  ██████╗       ██████╗ ██╗     ███████╗
  *   ██╔══██╗██╔════╝       ██╔══██╗██║     ╚══███╔╝
  *   ███████║██║            ██████╔╝██║       ███╔╝
  *   ██╔══██║██║            ██╔═══╝ ██║      ███╔╝
  *   ██║  ██║╚██████╗▄█╗    ██║     ███████╗███████╗
  *   ╚═╝  ╚═╝ ╚═════╝╚═╝    ╚═╝     ╚══════╝╚══════╝
  *
  *  @Author: TieWay59
  *  @Created: 2020/2/3 2:08
  *  @Link: https://codeforces.com/contest/1291/problem/B
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
    int n;
    cin >> n;

    vector<int> a(n);
    vector<bool> b(n, false);
    vector<bool> c(n, false);

    for (auto &ai:a) {
        cin >> ai;
    }

    for (int i = 0; i < n; ++i) {
        if (a[i] >= i) {
            b[i] = true;
        }
        if (a[i] >= n - 1 - i) {
            c[i] = true;
        }
    }

    int i, j;
    for (i = 0; i < n; ++i) {
        if (b[i] == false) {
            i--;
            break;
        }
    }
    for (j = n - 1; j >= 0; --j) {
        if (c[j] == false) {
            j++;
            break;
        }
    }


    if (i < j) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
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