
#include <bits/stdc++.h>

using namespace std;

int main() {

    clock_t begin = clock();
    int x = 0;
    for (int i = 1; i <= 800000000; ++i) {
        x++;
    }
    printf("%.3f ms\n", (double) (clock() - begin));
    return 0;
}

int _main() {
#ifdef DEBUG
    freopen("input.txt", "r+", stdin);
    clock_t begin_t = clock();
#endif
    STOPSYNC;
    solve();

#ifdef DEBUG
    cerr << fixed << setprecision(3)
         << (double) (clock() - begin_t) << " ms" << endl;
#endif
    return 0;
}