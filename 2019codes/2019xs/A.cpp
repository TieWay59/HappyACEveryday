/**
  *    █████╗  ██████╗       ██████╗ ██╗     ███████╗
  *   ██╔══██╗██╔════╝       ██╔══██╗██║     ╚══███╔╝
  *   ███████║██║            ██████╔╝██║       ███╔╝
  *   ██╔══██║██║            ██╔═══╝ ██║      ███╔╝
  *   ██║  ██║╚██████╗▄█╗    ██║     ███████╗███████╗
  *   ╚═╝  ╚═╝ ╚═════╝╚═╝    ╚═╝     ╚══════╝╚══════╝
  *
  *  @Author: TieWay59
  *  @Created: 2019/12/14 19:39
  *  @Link: http://101.132.131.241:81/contest/1/problem/A
  *  @Tags:
  *
  *******************************************************/


#include <bits/stdc++.h>

#ifdef DEBUG
//#define debug(x)  cerr <<#x << " = "<<x<<endl;
#   include "libs59/debugers.h"

#else
#   define endl '\n'
#   define debug(...)  59
#endif

#define STOPSYNC ios::sync_with_stdio(false);cin.tie(nullptr)
#define MULTIKASE int Kase=0;cin>>Kase;for(int kase=1;kase<=Kase;kase++)
typedef long long ll;
typedef unsigned long long ull;
const int MAXN = 1u << 21u;
const int MOD = 1e9 + 7;
const int INF = 0x3F3F3F3F;
const ll llINF = 0x3F3F3F3F3F3F3F3F;
using namespace std;
const ull sh1 = 19491001ull;
const ull sh2 = 19260817ull;


struct node {
    ull val[5];

    ull getHush(const ull &m) {
        ull v1 = 0;
        ull v2 = 0;
        ull shsh1 = sh1;
        ull shsh2 = sh2;
        for (int i = 0; i < m; i++) {
            v1 += val[i] * shsh1;
            v2 += val[i] * shsh2;
            shsh1 *= sh1;
            shsh2 *= sh2;
        }
        return v1;
    }

    void init(const ull &mul, const node &rht, const ull &m) {
        for (int i = 0; i < m; i++) {
            val[i] = rht.val[i] * mul;
        }
    }

    node operator+(const node &rht) const {
        node ret;
        for (int i = 0; i < 5; i++) {
            ret.val[i] = val[i] + rht.val[i];
        }
        return ret;
    }

    node operator-(const node &rht) const {
        node ret;
        for (int i = 0; i < 5; i++) {
            ret.val[i] = val[i] - rht.val[i];
        }
        return ret;
    }

    bool operator<(const node &rht) const {
        for (int i = 0; i < 5; ++i) {
            if (val[i] < rht.val[i])return true;
            else if (val[i] > rht.val[i])return false;
        }
        return false;
    }
} a[55], aim;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(pair<ull, ull> x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x.first + FIXED_RANDOM + x.second);
    }
};

ull maxBit[MAXN];
ull lenBit[MAXN];
ull cntBit[MAXN];
node sub[MAXN];

void solve(int kaseId = -1) {
    ull n, m, k, leftpart, rightpart;
    cin >> n >> m >> k;
    leftpart = n - n / 2;
    rightpart = n / 2;

    //init??
    unordered_map<ull, ull> check_val;
    memset(aim.val, 0, sizeof aim.val);
    memset(a, 0, sizeof a);
    memset(sub, 0, sizeof sub);


    for (int i = 0; i < m; ++i) {
        cin >> aim.val[i];
    }

    for (ull i = 1; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i].val[j];
        }
    }

    ull subset = 1ull << leftpart;
//    debug(subset);

    ull t;
    for (ull i = 0; i < subset; i++) {
        sub[i] = sub[i - maxBit[i]] + a[lenBit[i]];
        t = sub[i].getHush(m);
        check_val[t] = max(check_val[t], cntBit[i]);
    }

    subset = 1ull << rightpart;
    for (ull i = leftpart + 1, j = 1; i <= n; ++i, ++j) {
        a[j] = a[i];
        debug(a[j].val[0]);
    }

    memset(sub, 0, sizeof sub);
    node tmp;
    bool ans = false;
    for (ull i = 0; i < subset && !ans; i++) {
        sub[i] = sub[i - maxBit[i]] + a[lenBit[i]];

        for (ull j = max(k, cntBit[i]); j <= cntBit[i] + leftpart; ++j) {
            // j := the number of need.
            tmp.init(j, aim, m);

            if (tmp < sub[i])continue;


            tmp = tmp - sub[i];
            t = tmp.getHush(m);

            if (check_val.find(t) != check_val.end()
                && j == check_val[t] + cntBit[i]) {

                ans = true;
                break;
            }
        }
    }

//    for (auto cv:check_val) {
//        debug(cv);
//    }

    if (ans) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

void solves() {
    MULTIKASE {
        solve(kase);
    }
}

int main() {

    maxBit[1] = 1;
    lenBit[1] = 1;
    cntBit[1] = 1;

    for (ull i = 2; i <= 1048576ull; i++) {
        maxBit[i] = maxBit[i >> 1u] << 1u;
        lenBit[i] = lenBit[i >> 1u] + 1u;
        cntBit[i] = cntBit[i >> 1u] + (i & 1u);
    }
    //freopen("E:\\qq\\2728735169\\FileRecv\\颜色配制\\3.in", "r", stdin);
    STOPSYNC;
    solves();
    return 0;
}
/*

 */