#include <bits/stdc++.h>

#define  debug(x)  cerr <<#x << " = "<<x<<endl

#define endl '\n'
#define $STOPSYNC ios::sync_with_stdio(false);cin.tie(nullptr)
#define $MULTIKASE int Kase=0;cin>>Kase;for(int kase=1;kase<=Kase;kase++)
const int MAXN = 2e5 + 59;
const int MOD = 1e9 + 7;

using namespace std;
typedef long long ll;

int a[MAXN];
int p[MAXN];
int s[MAXN];
int mxp[MAXN];
int mxa;

int n, m;

void solve(int kaseId = -1) {
    cin >> n;
    mxa = 0;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        mxa = max(mxa, a[i]);
        mxp[i + 1] = mxp[i] = 0;
    }

    cin >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> p[i] >> s[i];
        mxp[s[i]] = max(mxp[s[i]], p[i]);
    }

    for (int i = n; i >= 1; --i) {
        mxp[i] = max(mxp[i], mxp[i + 1]);
    }

    int ans = 0;
    if (mxp[1] < mxa) {
        //debug(mxp[1]);
        cout << -1 << endl;
    } else {
        ans = 1;
        mxa = 0;
        for (int i = 1, j = 1; i <= n; i++, j++) {
            mxa = max(mxa, a[i]);
            if (mxa > mxp[j]) {
                ans++;
                mxa = a[i];
                j = 1;
            }
        }
        cout << ans << endl;
    }
}

void solves() {
    $MULTIKASE {
        solve(kase);
    }
}

int main() {
    $STOPSYNC;
    solves();
    return 0;
}
/*

1
6
2 3 11 14 1 8
2
3 2
100 6
 */