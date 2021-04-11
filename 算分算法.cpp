#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <cassert>


#define OPEN_DETAIL

const char DELIMITER = '\t';
const std::string INPUT_DIR = "./input-case-3.txt";
const std::string OUTPUT_DIR = "./output-case-3.txt";
const std::vector<int> WEIGHT = {5, 4, 12};

using namespace std;

namespace Model {

    /* 构建题数参考模型。
     * 返回每个题数对应的区间，最后会确保同题数的人会在一个分数段中。
     *
     * 注意，开根号是为了削弱过度的题数差距。例如，天梯赛是积分制的，如果按照是积分下来会有如下结果：
     *  [solv_model({222, 187, 74})] := {(0.996639, 1.000000), (0.870855, 0.874700), (0.000000, 0.081923)}
     *  如果不采用开根：
     *  [solv_model({222, 187, 74})] := {(0.993289, 1.000000), (0.758389, 0.765101), (0.000000, 0.006711)}
     *  最后一个人的区间会出现过低的极端值，这对我们算分没有帮助。
     *
     * */
    vector<pair<double, double>> solv_model(const vector<int> &solv) {
        double mx{double(*max_element(solv.begin(), solv.end()))};
        double mn{double(*min_element(solv.begin(), solv.end()))};

        auto f = [a = mn, b = mx](int x) -> pair<double, double> {
            double l = (x - a) / double(b - a + 1);
            double r = (x - a + 1) / double(b - a + 1);
            return {sqrt(l), sqrt(r)};
        };

        vector<pair<double, double>> res(solv.size());
        for (size_t i = 0; i < solv.size(); ++i) {
            res[i] = f(solv[i]);
        }

        return res;
    }

    /* 构建排名参考模型。
     * 相当于所有排名会倒序映射到log函数。
     * 排名越小，参考值越大，但是不是线性增长的。
     * 同题数的人才会主要由排名拉开差距。
     **/
    vector<double> rank_model(const vector<int> &rank) {
        double mx{double(*max_element(rank.begin(), rank.end()))};

        auto f = [b = mx](int x) -> double {
            return log(1 + (exp(1) - 1) * (b - x + 1.0) / (b + 1));
        };

        vector<double> res(rank.size());
        for (size_t i = 0; i < rank.size(); ++i) res[i] = f(rank[i]);

        return res;
    }

    /* 联合两个模型，由题数决定所在分数段，由排名决定所在段内的具体值。
     * 优点：在过题数比较连续，题数不多的时候，会划分的比较理想。
     * 缺点(?)：在积分制比赛中（比如pta），由于我们认定分数就是题数，大多数人会因为分数差距而拉开更大的差距。
     * （但这或许又不是一个缺点，因为分数差距大，也约等于题数差距很大的区别。）
     **/
    vector<double> join_model(const vector<pair<double, double>> &solv_m,
                              const vector<double> &rank_m) {
        assert(solv_m.size() == rank_m.size());
        vector<double> res(solv_m.size());
        for (size_t i = 0; i < solv_m.size(); ++i) {
            res[i] = (solv_m[i].second - solv_m[i].first) * rank_m[i] + solv_m[i].first;
        }
        return res;
    }

    /* 简化中间步骤的模型函数接口。
     **/
    vector<double> model(const vector<int> &v_solv, const vector<int> &v_rank) {
        return join_model(solv_model(v_solv), rank_model(v_rank));
    }

}

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

/* 加载数据
 * 注意保证数据的分隔符（DELIMITER），如果是从excel中贴入记事本的数据，一般是'\t'分隔的，如果不对的话可以尝试用空格。
 * */
void load(vector<Team> &teams) {
    string line;
    ifstream fin(INPUT_DIR);
    while (getline(fin, line, '\n')) {
        auto s = split(line, DELIMITER);

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

void dump(vector<Team> &teams) {
    ofstream fout(OUTPUT_DIR);

    for (const auto &t : teams) {
        fout << setw(2)
             << setfill(' ')
             << 1 + int(&t - &teams.front())
             << " "
             << setw(8)
             << setfill(' ')
             << t.name
             << " "
             << setw(10)
             << setfill(' ')
             << fixed
             << setprecision(5)
             << t.sum;

        // 可以全局#define一个这个宏来输出更具体的数据。
#ifdef OPEN_DETAIL
        fout << " :";
        for (const auto &c : t.contests) {
            fout << " "
                 << setw(6)
                 << setfill(' ')
                 << setprecision(3)
                 << c.score;
        }
#endif

        fout << endl;
    }

    fout.close();
}

void solve(int kaseId = -1) {
    vector<Team> teams;
    load(teams);

    const int contest_count = teams.front().contests.size();

    for (int i = 0; i < contest_count; ++i) {
        vector<int> solv;
        vector<int> rank;
        for (const auto &t : teams) {
            solv.emplace_back(t.contests[i].solv);
            rank.emplace_back(t.contests[i].rank);
        }
        auto score = Model::model(solv, rank);
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

    dump(teams);
}

int main() {
    solve();

//    debug(Model::solv_model({222, 187, 74}));

    return 0;
}
/*

 */