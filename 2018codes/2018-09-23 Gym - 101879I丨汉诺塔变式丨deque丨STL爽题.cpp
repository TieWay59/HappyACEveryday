#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define pf push_front

typedef pair<char, char> pcc;
deque<pcc> sol;

void hanoi(int n, char a, char b, char c) {
    if (n == 1) {
        sol.pb({a, c});
    } else {
        hanoi(n - 1, a, c, b);
        sol.pb({a, c});
        hanoi(n - 1, b, a, c);
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    if (k < (1 << n) - 1)return puts("N") * 0;
    puts("Y");
    hanoi(n, 'A', 'B', 'C');
    while (sol.size() < k) {
        pcc fs = sol.front();
        sol.pop_front();
        char a = fs.first;
        char b = fs.second;
        char c = 'A' + 'B' + 'C' - a - b;
        sol.pf({c, b});
        sol.pf({a, c});
    }
    for (pcc p:sol)
        printf("%c %c\n", p.first, p.second);
    return 0;
}
