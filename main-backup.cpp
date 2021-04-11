/**
  *    █████╗  ██████╗       ██████╗ ██╗     ███████╗
  *   ██╔══██╗██╔════╝       ██╔══██╗██║     ╚══███╔╝
  *   ███████║██║            ██████╔╝██║       ███╔╝
  *   ██╔══██║██║            ██╔═══╝ ██║      ███╔╝
  *   ██║  ██║╚██████╗▄█╗    ██║     ███████╗███████╗
  *   ╚═╝  ╚═╝ ╚═════╝╚═╝    ╚═╝     ╚══════╝╚══════╝
  *
  *  @Author: TieWay59
  *  @Created: 2021/3/28 20:20
  *  @Link: https://www.desmos.com/calculator?lang=zh-CN
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

//const unsigned int COUNT_CONTEST = 3;
const std::string DIR = "./input-case-2.txt";
const std::vector<int> WEIGHT = {3, 5, 8};
const double C_RANK = 0.85;


ll fpow(ll a, ll b, ll mod = MOD) {
    if (a % mod == 0) return 0;
    ll ret = 1;
    a %= mod;
    while (b) {
        if (b & 1)ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}

vector<double> solv_model(const vector<int> &solved) {
    double mx{1.0 + *max_element(solved.begin(), solved.end())};
    double mn{1.0 + *min_element(solved.begin(), solved.end())};
    auto f = [a = mn, b = mx](int x) -> double { return x * 1.0 / (a + x) * b; };
    vector<double> res(solved.size());
    for (size_t i = 0; i < solved.size(); ++i) res[i] = f(solved[i]);
    mx = *max_element(res.begin(), res.end());
    mn = *min_element(res.begin(), res.end());
    for (size_t i = 0; i < solved.size(); ++i) res[i] = (res[i] - mn + 1) / (mx - mn + 1);
    return res;
}

vector<double> rank_model(const vector<int> &rank) {
    double mx{double(*max_element(rank.begin(), rank.end()))};
    auto f = [b = mx](int x) -> double { return (b - x + 1.0) / b; };
    vector<double> res(rank.size());
    for (size_t i = 0; i < rank.size(); ++i) res[i] = f(rank[i]);
    return res;
}

vector<double> join_model(const vector<double> &_solv_model,
                          const vector<double> &_rank_model) {
    assert(_solv_model.size() == _rank_model.size());
    vector<double> res(_solv_model.size());
    for (size_t i = 0; i < _solv_model.size(); ++i) {
        res[i] = _solv_model[i] * (1 - C_RANK) + _rank_model[i] * C_RANK;
    }
    return res;
}

vector<double> model(const vector<int> &b_solv, const vector<int> &b_rank) {
    return join_model(solv_model(b_solv), rank_model(b_rank));
}

class Team {
public:
    string name;
    struct Contest {
        int solv;
        int rank;
        double score;
    };
    vector<Contest> contests;
    double sum;
};

string strip(const string &s) {
    string res;
    stringstream ss(s);
    ss >> res;
    return res;
}

vector<string> split(const string &raw, const char &del) {
    vector<string> vec;
    stringstream ss(raw);
    static string si;
    while (getline(ss, si, del)) {
        si = strip(si);
        if (si.empty())continue;
        vec.emplace_back(si);
    }
    return vec;
}

void load(vector<Team> &teams) {
    string line;
    ifstream fin(DIR);
    while (getline(fin, line, '\n')) {
        auto s = split(line, '\t');

        assert(s.size() % 2 == 1);

        Team t{s.front(), {}, 0.0};
        for (int i = 1; i + 1 < s.size(); i += 2) {
            int rank = stoi(s[i]);
            int solv = stoi(s[i + 1]);
            t.contests.push_back({solv, rank, 0.0});
        }
        teams.push_back(t);
    }
    fin.close();
}

void test_teams(const vector<Team> &teams) {
    for (const auto &team : teams) {
        debug(team.name, team.sum);
        for (const auto &con : team.contests) {
            debug(con.solv, con.rank, con.score);
        }
    }
}

void dump(vector<Team> &teams) {
    ofstream fout("./output.txt");

    for (const auto &t : teams) {
        fout << setw(2) << setfill(' ')
             << 1 + int(&t - &teams.front())
             << " "
             << setw(8) << setfill(' ')
             << t.name
             << " "
             << setw(10) << setfill(' ') << fixed << setprecision(5)
             << t.sum
             << " : ";

        for (const auto &c : t.contests) {
            fout << setw(10) << setfill(' ') << setprecision(5)
                 << c.score
                 << " \n"[&c == &t.contests.back()];
        }
    }

    fout.close();
}

void solve(int kaseId = -1) {
    vector<Team> teams;
    load(teams);
//    test_teams(teams);

    const int contest_count = teams.front().contests.size();

    for (int i = 0; i < contest_count; ++i) {
        vector<int> solv;
        vector<int> rank;
        for (auto t : teams) {
            solv.emplace_back(t.contests[i].solv);
            rank.emplace_back(t.contests[i].rank);
        }
        auto score = model(solv, rank);
        for (int j = 0; j < teams.size(); ++j) {
            teams[j].contests[i].score = score[j];
        }
    }

    for (auto &t: teams) {
        for (const auto &c: t.contests) {
            t.sum += c.score * WEIGHT[&c - &t.contests.front()];
        }
    }

    sort(teams.begin(), teams.end(), [](const auto l, const auto &r) {
        return l.sum > r.sum;
    });

//    test_teams(teams);
    dump(teams);
}

void solves() {
    MULTIKASE {
        solve(kase);
    }
}

int main() {
#ifdef DEBUG
//    freopen("input.txt", "r+", stdin);
#endif
    STOPSYNC;
    solve();
    return 0;
}
/*

 */