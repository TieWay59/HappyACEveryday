/**
  *    █████╗  ██████╗       ██████╗ ██╗     ███████╗
  *   ██╔══██╗██╔════╝       ██╔══██╗██║     ╚══███╔╝
  *   ███████║██║            ██████╔╝██║       ███╔╝
  *   ██╔══██║██║            ██╔═══╝ ██║      ███╔╝
  *   ██║  ██║╚██████╗▄█╗    ██║     ███████╗███████╗
  *   ╚═╝  ╚═╝ ╚═════╝╚═╝    ╚═╝     ╚══════╝╚══════╝
  *
  *  @Author: TieWay59
  *  @Created: 2020/2/8 13:22
  *  @Link: https://vjudge.net/contest/355794?tdsourcetag=s_pctim_aiomsg#problem/J
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

ll fpow(ll a, ll b, ll mod = MOD) {
    ll ret = 1;
    while (b) {
        if (b & 1)ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}

ll n;
set<ll> p;

bool isPrime(ll t) {
    if (t == 1)return false;
    for (ll i = 2; i * i <= t; ++i) {
        if (t % i == 0) {
            return false;
        }
    }
    return true;
}

void addPrime(ll t) {
    debug(t);
    for (ll i = t; i <= t + 255; ++i) {
        if (isPrime(i)) {
            p.emplace(i);
            if (i != t)break;
        }
    }

    for (ll i = t; i > 1; --i) {
        if (isPrime(i)) {
            p.emplace(i);
            if (i != t)break;
        }
    }
}

ll x = 0;

void solve(int kaseId = -1) {
    cin >> n;
    vector<ll> a(n);

    for (auto &ai:a) {
        cin >> ai;
    }

    sort(a.begin(), a.end());

    if (n % 2) {
        addPrime(a[n / 2]);
    } else {
        addPrime(a[n / 2]);
        addPrime(a[n / 2 - 1]);
    }

    ll ans = llINF, sum;
    debug(p);
    for (const auto &pi:p) {
        sum = 0;
        for (const auto &ai:a) {
            sum += abs(ai - pi);
            if (sum > ans)break;
        }
        ans = min(ans, sum);
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
    solve();
    return 0;
}
/*

 */