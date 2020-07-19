/**
  *    █████╗  ██████╗       ██████╗ ██╗     ███████╗
  *   ██╔══██╗██╔════╝       ██╔══██╗██║     ╚══███╔╝
  *   ███████║██║            ██████╔╝██║       ███╔╝
  *   ██╔══██║██║            ██╔═══╝ ██║      ███╔╝
  *   ██║  ██║╚██████╗▄█╗    ██║     ███████╗███████╗
  *   ╚═╝  ╚═╝ ╚═════╝╚═╝    ╚═╝     ╚══════╝╚══════╝
  *
  *  @Author: TieWay59
  *  @Created: 2020/3/23 9:07
  *  @Link: http://acm.hdu.edu.cn/showproblem.php?pid=1043
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
#   define max(x,y) ((x)>(y)?(x):(y))
#   define min(x,y) ((x)>(y)?(y):(x))
#endif

#define STOPSYNC ios::sync_with_stdio(false);cin.tie(nullptr)
#define MULTIKASE int Kase=0;cin>>Kase;for(int kase=1;kase<=Kase;kase++)
typedef long long ll;
const int MAXN = 2e5 + 59;
const int MOD = 1e9 + 7;
const int INF = 0x3F3F3F3F;
const ll llINF = 0x3F3F3F3F3F3F3F3F;
using namespace std;
using pii = pair<int, int>;
using vint = vector<int>;

const vector<pair<int, char>> dir = {
        {1,  'l'},
        {-1, 'r'},
        {3,  'u'},
        {-3, 'd'}
};
const set<pii> invalid = {
        {2, 3},
        {3, 2},
        {5, 6},
        {6, 5}
};
const vector<int> digitMask = {
        1,
        10,
        100,
        1000,
        10000,
        100000,
        1000000,
        10000000,
        100000000,
        1000000000
};
unordered_map<int, pair<int, char>> pre;

inline int dis(int xa, int ya, int xb, int yb) {
    return abs(xa - xb) + abs(ya - yb);
}

inline int h(int state) {
    int sum = 0;
    int pos = 8;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j, --pos) {
            int v = (state / digitMask[pos]) % 10 - 1;
            if (v < 0);//sum += dis(i, j, 2, 2);
            else sum += dis(i, j, v / 3, v % 3);
//            debug(sum, i, j, v / 3, v % 3);
        }
    }
    return sum;
}

inline int digitSwap(int x, int a, int b) {
    int da = (x / digitMask[a]) % 10;
    int db = (x / digitMask[b]) % 10;
    return x - da * digitMask[a] - db * digitMask[b]
           + db * digitMask[a] + da * digitMask[b];
}

void display(int x) {
    vector<int> xs;
    while (x) {
        xs.emplace_back(x % 1000);
        x /= 1000;
    }
    while (!xs.empty()) {
        cerr << setw(3) << setfill('0') << xs.back() << endl;
        xs.pop_back();
    }
    cerr << string(13, '*') << endl;
}

bool DFS(int u, int pos, const int &depth, int steps) {
    if (u == 123456780) return true;
    if (steps + h(u) > depth)return false;

    for (const auto &d:dir) {
        int nxt = pos + d.first;
        if (nxt < 0 || nxt >= 9 || invalid.count({pos, nxt}))continue;
        int v = digitSwap(u, pos, nxt);
        assert(v > 0);
        if (pre.count(v))continue;
        pre.emplace(v, make_pair(u, d.second));
        if (DFS(v, nxt, depth, steps + 1))return true;
    }
//    debug(steps, u);
//    display(u);
    return false;
};

bool IDDFS(int u, int pos) {
    for (int depth = h(u);; ++depth) {
        pre.clear();
        pre[u] = make_pair(-1, 0);
        if (DFS(u, pos, depth, 0))
            return true;
    }
    return false;
}

bool checkValid(int x) {
    int cntInvs = 0;
    for (int i = 0; i < 9; ++i) {
        for (int j = i + 1; j < 9; ++j) {
            int di = (x / digitMask[i]) % 10;
            int dj = (x / digitMask[j]) % 10;
            if (di > dj)cntInvs++;
        }
    }
    return cntInvs % 2 == 0;
}


void solve(int kaseId = -1) {
//    cout << h(123456708) << endl;
    string input;
    int pos = -1;
    int state = 0;

    for (int i = 0; i < 9; ++i) {
        cin >> input;
        if (input[0] == 'x') {
            pos = 8 - i;
            state = state * 10;
        } else {
            state = state * 10 + int(input[0] - '0');
        }
    }
    if (!checkValid(state)) {
        cout << "unsolvable" << endl;
        return;
    }
    bool found = IDDFS(state, pos);
    if (found) {
        vector<char> ans;
        state = 123456780;
        display(state);
        while (pre[state].first != -1) {
            ans.emplace_back(pre[state].second);
            cerr << string(1, pre[state].second) << endl;
            display(pre[state].first);
            state = pre[state].first;
//            debug(pre[state].first, string(1, pre[state].second));
        }
        reverse(ans.begin(), ans.end());
        for (auto ai:ans)cout.put(ai);
        cout << endl;
    } else {
        cout << "unsolvable" << endl;
    }
}

void solves() {
    MULTIKASE {
        solve(kase);
    }
}

int main() {
#ifdef DEBUG
    freopen("input.txt", "r+", stdin);
#endif
    STOPSYNC;
    solve();
    return 0;
}
/*

 2  3  4  1  5  x  7  6  8


 */