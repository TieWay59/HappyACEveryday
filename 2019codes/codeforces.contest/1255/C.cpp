#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 59;

int n;
vector<int> a[MAXN];
int cnt[MAXN];
bool vis[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1, x, y, z; i <= n - 2; i++) {
        cin >> x >> y >> z;
        a[x].emplace_back(y);
        a[x].emplace_back(z);
        a[y].emplace_back(z);
        a[y].emplace_back(x);
        a[z].emplace_back(y);
        a[z].emplace_back(x);
        cnt[x]++;
        cnt[y]++;
        cnt[z]++;
    }

    int x, y, z;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] == 1) {
            x = i;
            break;
        }
    }
    y = cnt[a[x].front()] == 2 ? a[x][0] : a[x][1];
    cout << x << " " << y;
    vis[x] = vis[y] = true;

    for (int i = 1; i <= n - 2; i++) {
        for (auto ai:a[x]) {
            if (!vis[ai]) {
                z = ai;
                break;
            }
        }
        cout << " " << z;
        vis[z] = true;
        x = y;
        y = z;
    }
    cout << '\n';
    return 0;

}
