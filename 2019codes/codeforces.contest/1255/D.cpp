#include<bits/stdc++.h>

using namespace std;
#define multicase int Kase;cin>>Kase;for(int kase=1;kase<=Kase;kase ++)
const int MAXN = 1e5 + 59;

int n, m, k;
int cntR;
const string str = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
int has[159];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    multicase {
        cntR = 0;
        cin >> n >> m >> k;
        vector<string> g(n);
        for (auto &gi:g) {
            cin >> gi;
            for (auto gij:gi) {
                if (gij == 'R') {
                    cntR++;
                }
            }
        }
        for (int i = 0; i < k; i++) {
            has[i] = cntR / k;
            if (i < cntR % k)
                has[i]++;
        }

        for (int i = 0, st, ed, delta, id = 0; i < n; i++) {
            if (i & 1) {
                st = m - 1;
                ed = -1;
                delta = -1;
            } else {
                st = 0;
                ed = m;
                delta = 1;
            }

            for (int j = st; j != ed; j += delta) {
                if (g[i][j] == 'R')
                    has[id]--;
                g[i][j] = str[id];
                if (has[id] == 0 && id < k - 1)
                    id++;
            }

        }

        for (int i = 0; i < n; i++) {
            cout << g[i] << '\n';
        }
    }

    return 0;

}
