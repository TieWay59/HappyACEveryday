/*
    @Author: TieWay59
    @Date: 2019/11/22 13:38
    @Link: https://atcoder.jp/contests/agc040/tasks/agc040_b
    @Tags: idea
*/

#include <bits/stdc++.h>

#define  debug(x)  cerr <<#x << " = "<<x<<endl

#define endl '\n'
#define STOPSYNC ios::sync_with_stdio(false);cin.tie(nullptr)
#define MULTIKASE int Kase=0;cin>>Kase;for(int kase=1;kase<=Kase;kase++)
typedef long long ll;
const int MAXN = 2e5 + 59;
const int MOD = 1e9 + 7;
const int INF = 0x3F3F3F3F;
const ll llINF = 0x3F3F3F3F3F3F3F3F;
using namespace std;

int n, m;
struct node {
    ll l, r;
} a[MAXN];
ll maxL;
ll minR;
ll ans;
ll ansInLeft[MAXN];
ll ansInRight[MAXN];
pair<int, int> pairInLeft[MAXN];
pair<int, int> pairInRight[MAXN];

void solve(int kaseId = -1) {

    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i].l >> a[i].r;
        ans = max(ans, a[i].r - a[i].l + 1);
    }

    sort(a + 1, a + 1 + n, [](node x, node y) {
        if (x.l == y.l)return x.r < y.r;
        return x.l < y.l;
//        return (x.r - x.l) < (y.r - y.l);
    });

    maxL = 0;
    minR = llINF;
    for (int i = 1; i <= n; ++i) {
        maxL = max(maxL, a[i].l);
        minR = min(minR, a[i].r);
        if (maxL <= minR) {
            ansInLeft[i] = minR - maxL + 1;
            pairInLeft[i] = {maxL, minR};
        } else {
            break;
        }
    }

    maxL = 0;
    minR = llINF;
    for (int i = n; i >= 1; --i) {
        maxL = max(maxL, a[i].l);
        minR = min(minR, a[i].r);
        if (maxL <= minR) {
            ansInRight[i] = minR - maxL + 1;
            pairInRight[i] = {maxL, minR};
        } else {
            break;
        }
    }

    for (int i = 1; i < n; ++i) {
        ans = max(ans, ansInLeft[i] + ansInRight[i + 1]);
    }

    for (int i = 2; i < n; ++i) {
        ll len = a[i].r - a[i].l + 1;
        if (pairInRight[i + 1].first > 0 &&
            pairInLeft[i - 1].first > 0 &&
            pairInRight[i + 1].first <= pairInLeft[i - 1].second) {
            ans = max(ans, len +
                           min(pairInLeft[i - 1].second, pairInRight[i + 1].second)
                           - pairInRight[i + 1].first + 1);
        }
    }

    cout << ans << endl;
}

/*void solves() {
    MULTIKASE {
        solve(kase);
    }
}*/

int main() {
    STOPSYNC;
//    solves();
    solve();
    return 0;
}
/*

 */