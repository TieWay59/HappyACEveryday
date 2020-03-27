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


/*inline void display(int x) {
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
}*/


void solve(int kaseId = -1) {

    const auto parseInput = [](const string &input, int &pos, int &state) {
        int i = 0;
        for (auto in:input) {
            if (in == 'x') {
                pos = 8 - i;
                state = state * 10;
            } else if (isdigit(in)) {
                state = state * 10 + int(in - '0');
                i++;
            }
        }
    };

    const auto checkInvalid = [](const int &state) {
        int cntInvs = 0;
        for (int i = 8; i >= 0; --i) {
            int di = (state / digitMask[i]) % 10;
            if (di == 0)continue;
            for (int j = 8; j > i; --j) {
                int dj = (state / digitMask[j]) % 10;
                if (dj == 0)continue;
                if (dj > di)cntInvs++;
            }
        }
        return cntInvs % 2 == 1;
    };

    const auto digitSwap = [](int x, int a, int b) {
        int da = (x / digitMask[a]) % 10;
        int db = (x / digitMask[b]) % 10;
        return x - da * digitMask[a] - db * digitMask[b]
               + db * digitMask[a] + da * digitMask[b];
    };

    const auto mht_dis = [](int xa, int ya, int xb, int yb) {
        return abs(xa - xb) + abs(ya - yb);
    };

    const auto h = [&](int state) {
        int sum = 0;
        int pos = 8;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j, --pos) {
                int v = (state / digitMask[pos]) % 10 - 1;
                if (v >= 0) sum += mht_dis(i, j, v / 3, v % 3);
            }
        }
        return sum;
    };

    const auto DFS = [&](auto dfs, int u, int f, int pos, int steps,
                         const int &depth, vector<char> &trace) -> bool {
        if (u == 123456780) return true;

        // Actually, this code runs faster without A* sort.
        vector<tuple<int, int, int, char>> Astar;

        for (const auto &d:dir) {
            int nxt = pos + d.first;
            if (nxt < 0 || nxt >= 9 || invalid.count({pos, nxt}))continue;
            int v = digitSwap(u, pos, nxt);
            assert(v > 0);
            if (v == f)continue;
            if (steps + 1 + h(v) > depth)continue;
            Astar.emplace_back(steps + 1 + h(v), v, nxt, d.second);
            /*
            trace.emplace_back(d.second);
            if (dfs(dfs, v, u, nxt, steps + 1, depth, trace))return true;
            else trace.pop_back();
             */
        }

        sort(Astar.begin(), Astar.end());
        for (auto ast:Astar) {
            int fx, v, nxt, dch;
            tie(fx, v, nxt, dch) = ast;
            trace.emplace_back(dch);
            if (dfs(dfs, v, u, nxt, steps + 1, depth, trace))return true;
            else trace.pop_back();
        }

        return false;
    };

    const auto IDAstar = [&](int u, int pos, vector<char> &trace) {
        trace.clear();
        trace.reserve(200);

        for (int depth = h(u); depth <= 999;) {
            if (DFS(DFS, u, -1, pos, 0, depth, trace)) {
                return true;
            }
            // try your own enum method to speed-up.
            // this depth returns not shortest answer,
            // but faster to access one possible answer.
            if (depth < 256)depth += (depth) & (-depth);
            else depth += 2;
        }
        return false;
    };

    string input;
    while (getline(cin, input)) {
        int pos = -1;
        int state = 0;

        parseInput(input, pos, state);

        debug(state);

        if (checkInvalid(state)) {
            cout << "unsolvable" << endl;
            continue;
        }

        vector<char> trace;
        bool found = IDAstar(state, pos, trace);
        if (found) {
            for (auto ai:trace)cout.put(ai);
            cout << endl;
        } else {
            cout << "unsolvable" << endl;
        }
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