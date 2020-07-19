/**
  *    █████╗  ██████╗       ██████╗ ██╗     ███████╗
  *   ██╔══██╗██╔════╝       ██╔══██╗██║     ╚══███╔╝
  *   ███████║██║            ██████╔╝██║       ███╔╝
  *   ██╔══██║██║            ██╔═══╝ ██║      ███╔╝
  *   ██║  ██║╚██████╗▄█╗    ██║     ███████╗███████╗
  *   ╚═╝  ╚═╝ ╚═════╝╚═╝    ╚═╝     ╚══════╝╚══════╝
  *
  *  @Author: TieWay59
  *  @Created: 2020/3/23 7:47
  *  @Link: https://vjudge.net/contest/363902#problem/H
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

/**
 *  @Source: https://zh.cppreference.com/w/cpp/language/parameter_pack
 *  @Complexity:
 *  @Description: 用cout模仿格式化输出
 *  @Example: see below
 *  @Verification: TODO
 */
void coutf(const char *format) {
    std::cout << format;
}

template<typename T, typename... Targs>
//void coutf(const char *format, T value, Targs... Fargs) // 递归变参函数
void coutf(const char *format, const T &value, const Targs &... Fargs) {
    for (; *format != '\0'; format++) {
        if (*format == '%') {
            std::cout << value;
            coutf(format + 1, Fargs...); // 递归调用
            return;
        }
        std::cout << *format;
    }
}


const vector<pii> deltas = {
        {1,  2},
        {1,  -2},
        {-1, 2},
        {-1, -2},
        {2,  1},
        {2,  -1},
        {-2, 1},
        {-2, -1}
};

void solve(int kaseId = -1) {
    auto BFS = [](queue<pii> &q$, vector<vint> &dis_this, vector<vint> &dis_that) -> int {
        int r, c;
        queue<pii> q;
        q.swap(q$);

        while (!q.empty()) {
            tie(r, c) = q.front(), q.pop();
            if (dis_that[r][c] != INF)
                return dis_this[r][c] +
                       dis_that[r][c];

            for (auto d:deltas) {
                int dr = r + d.first;
                int dc = c + d.second;
                if (dr < 0 || dr >= 8 || dc < 0 || dc >= 8)continue;
                if (dis_this[dr][dc] != INF)continue;
                q$.emplace(dr, dc);
                dis_this[dr][dc] = dis_this[r][c] + 1;
            }
        }
        return -1;
    };


    int r1, c1;
    int r2, c2;

    auto BiBFS = [&]() -> int {
        vector<vint> dis_s(8, vint(8, INF));
        vector<vint> dis_t(8, vint(8, INF));
        queue<pii> qs, qt;
        qs.emplace(r1, c1);
        qt.emplace(r2, c2);
        dis_s[r1][c1] = 0;
        dis_t[r2][c2] = 0;
        int res = -1;
        while (!qs.empty() || !qt.empty()) {
            if (qs.size() > qt.size() && !qt.empty()) {
                res = BFS(qt, dis_t, dis_s);
            } else {
                res = BFS(qs, dis_s, dis_t);
            }
            if (res != -1)return res;
        }
        return -1;
    };

    string input;
    while (getline(cin, input)) {
        r1 = input[0] - 'a';
        c1 = input[1] - '1';
        r2 = input[3] - 'a';
        c2 = input[4] - '1';
        debug(r1, c1, r2, c2);
        int ans = BiBFS();
        assert(ans >= 0);
        coutf("To get from % to % takes % knight moves.\n",
              input.substr(0, 2), input.substr(3, 2), ans);
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
e2 e4
a1 b2
b2 c3
a1 h8
a1 h7
h8 a1
b1 c3
f6 f6

 */