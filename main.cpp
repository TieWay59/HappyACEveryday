/*
*  https://codeforc.es/contest/1220/problem/D?csrf_token=a6aa4329bb73ab3e1847c9e973e7af85
*/
//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <tuple>

#define  _debug(x) cerr<<#x<<" = "<<x<<endl
using namespace std;
typedef long long ll;
typedef long long lll;
const int MAXN = 1e3 + 59;
const int MAXM = 2e5 + 59;
const ll MOD = 998244353;
const ll INF = 0x0f0f0f0f;

ll sav[100];
ll a[MAXN];
ll k[MAXN];
ll n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    ll id = 0;
    ll mx = 0;
    for (ll i = 0, t; i < n; ++i) {
        cin >> a[i];
        t = a[i];
        k[i] = 0;
        while (1 & ~t)k[i]++, t >>= 1;
        sav[k[i]]++;
        if (sav[k[i]] > mx) {
            mx = sav[k[i]];
            id = k[i];
        }
    }
    cout << n - mx << endl;
    for (int i = 0; i < n; ++i) {
        if (k[i] != id) {
            cout << a[i] << endl;
        }
    }

    return 0;
}

