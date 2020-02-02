/**
  *    █████╗  ██████╗       ██████╗ ██╗     ███████╗
  *   ██╔══██╗██╔════╝       ██╔══██╗██║     ╚══███╔╝
  *   ███████║██║            ██████╔╝██║       ███╔╝
  *   ██╔══██║██║            ██╔═══╝ ██║      ███╔╝
  *   ██║  ██║╚██████╗▄█╗    ██║     ███████╗███████╗
  *   ╚═╝  ╚═╝ ╚═════╝╚═╝    ╚═╝     ╚══════╝╚══════╝
  *
  *  @Author: TieWay59
  *  @Created: 2020/2/3 5:00
  *  @Link: https://codeforces.com/contest/1291/problem/E
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

typedef vector<int> vint;

vint fa(MAXN);
vint sz(MAXN);
vint tag(MAXN);

int getf(const int &x) {
    if (fa[x] == x) {
        return x;
    } else {
        sz[fa[x]] += sz[x];
        sz[x] = 0;
        return getf(fa[x]);
    }
}

void merf(const int &x, const int &y) {
    int fx = getf(x);
    int fy = getf(y);
    if (fx != fy) {
        if (sz[fx] > sz[fy]) {
            sz[fx] += sz[fy];
            sz[fy] = 0;
            fa[fy] = fx;
        } else {
            sz[fy] += sz[fx];
            sz[fx] = 0;
            fa[fx] = fy;
        }
    }
}

void inif(const int &n) {
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
        sz[i] = 1;
    }
}

void solve(int kaseId = -1) {

    int n, k;
    string states;

    cin >> n >> k;
    cin >> states;
    states = " " + states;

    vector<vint> a(n + 1);
    vint ans(n + 1);

    for (int i = 1, m; i <= k; ++i) {
        cin >> m;
        for (int j = 1, t; j <= m; ++j) {
            cin >> t;
            a[t].emplace_back(i);
        }
    }

    inif(k);
    int cnt = 0;
    for (int i = 1, u, v; i <= n; ++i) {
        if (a[i].size() == 1) {
            if (states[i] == '0' && tag[a[i][0]] == 0) {
                tag[a[i][0]] = 1;
                cnt++;
            }
            debug(a[i][0], cnt);
        } else if (a[i].size() == 2) {
            u = a[i][0];
            v = a[i][1];
            debug(u, v, cnt);
            if (tag[u] != tag[v]) {
                if (states[i] == '1') {
                    if (tag[u] == 0) {
                        cnt++;
                        tag[u] = 1;
                    }
                    if (tag[v] == 0) {
                        cnt++;
                        tag[v] = 1;
                    }
                }
            } else {
                if (states[i] == '0') {
                    if (tag[u] == 0) {
                        cnt++;
                        tag[u] = 1;
                    }
                }
            }
        }
        ans[i] = min(cnt, k - cnt);
    }
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << endl;
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