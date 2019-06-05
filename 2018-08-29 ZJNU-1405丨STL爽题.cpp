#include <bits/stdc++.h>

using namespace std;
const int N = 2005;

struct Patient {
    int i, w;

    bool operator<(const Patient &x) const {
        if (w != x.w)return w < x.w;
        return i > x.i;
    }
};

int main() {
    int n, a, b;
    char op[5];
    while (scanf("%d", &n) != EOF) {
        priority_queue <Patient> que[3];
        int i = 0;
        while (n--) {
            scanf("%s", op);
            if (op[0] == 'I') {
                scanf("%d%d", &a, &b);
                que[a - 1].push({++i, b});
            } else {
                scanf("%d", &a);
                if (que[a - 1].empty()) {
                    puts("EMPTY");
                } else {
                    printf("%d\n", que[a - 1].top().i);
                    que[a - 1].pop();
                }
            }
        }
    }
    return 0;
}
/*

*/

