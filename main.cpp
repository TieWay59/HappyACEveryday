#include <bits/stdc++.h>
#include <tuple>

const int MAXN = 555;
using namespace std;
int n, kase;
string str;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> kase;
    while (kase--) {
        cin >> str;
        queue<char> odd, eve;
        for (auto si:str) {
            if ((si - '0') & 1) {
                odd.emplace(si);
            } else {
                eve.emplace(si);
            }
        }
        while (!(odd.empty() || eve.empty())) {
            if (odd.front() < eve.front()) {
                cout << odd.front();
                odd.pop();
            } else {
                cout << eve.front();
                eve.pop();
            }
        }
        while (!odd.empty()) {
            cout << odd.front();
            odd.pop();
        }
        while (!eve.empty()) {
            cout << eve.front();
            eve.pop();
        }
        cout << endl;
    }
    return 0;
}