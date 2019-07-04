/*
 * http://acm.zjnu.edu.cn/CLanguage/showproblem?problem_id=1217
 * 最长上升子序列长度的简便写法
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, Kase;
    cin >> Kase;
    while (Kase--) {
        cin >> n;
        vector<pair<int, int> > a(n);
        vector<int> dp;
        for (auto &ai:a)
            cin >> ai.first >> ai.second;
        sort(a.begin(), a.end());
        for (auto ai:a) {
            if (dp.empty() || ai.second >= *dp.rbegin())
                dp.push_back(ai.second);
            else
                *upper_bound(dp.begin(), dp.end(), ai.second) = ai.second;
        }
        cout << dp.size() << "\n";
    }
    return 0;
}