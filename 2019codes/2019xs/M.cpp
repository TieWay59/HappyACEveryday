/**
  *    █████╗  ██████╗       ██████╗ ██╗     ███████╗
  *   ██╔══██╗██╔════╝       ██╔══██╗██║     ╚══███╔╝
  *   ███████║██║            ██████╔╝██║       ███╔╝
  *   ██╔══██║██║            ██╔═══╝ ██║      ███╔╝
  *   ██║  ██║╚██████╗▄█╗    ██║     ███████╗███████╗
  *   ╚═╝  ╚═╝ ╚═════╝╚═╝    ╚═╝     ╚══════╝╚══════╝
  *
  *  @Author: TieWay59
  *  @Created: 2019/12/15 13:06
  *  @Link: 最大攻击
  *  @Tags:
  *
  *******************************************************/


#include <bits/stdc++.h>

#ifdef DEBUG
//#define debug(x)  cerr <<#x << " = "<<x<<endl;
#include "libs59/debugers.h"

#else
#define endl '\n'
#define debug(...)  59
#endif

#define STOPSYNC ios::sync_with_stdio(false);cin.tie(nullptr)
#define MULTIKASE int Kase=0;cin>>Kase;for(int kase=1;kase<=Kase;kase++)
typedef long long ll;
const int MAXN = 2e5 + 59;
const int MOD = 1e9 + 7;
const int INF = 0x3F3F3F3F;
const ll llINF = 0x3F3F3F3F3F3F3F3F;
using namespace std;

int n;
int a[105];

void solve(int kaseId = -1) {

    int ans = 0;
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i) {
        x -= a[i];
        if (x >= 0)ans++;
        else break;
        x += 1;
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
    solves();
    return 0;
}
/*

 */