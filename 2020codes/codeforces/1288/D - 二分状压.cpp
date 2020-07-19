/**
  *    █████╗  ██████╗       ██████╗ ██╗     ███████╗
  *   ██╔══██╗██╔════╝       ██╔══██╗██║     ╚══███╔╝
  *   ███████║██║            ██████╔╝██║       ███╔╝
  *   ██╔══██║██║            ██╔═══╝ ██║      ███╔╝
  *   ██║  ██║╚██████╗▄█╗    ██║     ███████╗███████╗
  *   ╚═╝  ╚═╝ ╚═════╝╚═╝    ╚═╝     ╚══════╝╚══════╝
  *
  *  @Author: TieWay59
  *  @Created: 2020/1/14 23:38
  *  @Link: http://m2.codeforces.com/contest/1288/problem/D
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
const int MAXN = 3e5 + 59;
const int MOD = 1e9 + 7;
const int INF = 0x3F3F3F3F;
const ll llINF = 0x3F3F3F3F3F3F3F3F;
using namespace std;

int a[MAXN][8];
int n, m;


int trans(int id, int comp) {

    int x = 0;
    for (int i = m; i >= 1; --i) {
        x = (x << 1) + (a[id][i] >= comp);
    }

    return x;
}

vector<int> chk;
pair<int, int> ans;

bool chek(int cmp) {

    chk = vector<int>(256, -1);

    for (int i = n; i >= 1; --i) {
        chk[trans(i, cmp)] = i;
    }

    for (int i = 0; i < 256; ++i) {
        for (int j = 0; j < 256; ++j) {
            if ((i | j) == (1 << m) - 1
                && chk[i] != -1
                && chk[j] != -1) {
                ans = {chk[i], chk[j]};
                return true;
            }
        }
    }

    return false;
}

void solve(int kaseId = -1) {

    cin >> n >> m;
    vector<int> vals;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            vals.emplace_back(a[i][j]);
        }
    }
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    //    debug(vals);


    int l = 0, r = vals.size() - 1;
    int mid;


    while (l <= r) {
        mid = (l + r) >> 1;
        if (chek(vals[mid])) {
            //            debug(vals[mid]);
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans.first << " " << ans.second << endl;
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