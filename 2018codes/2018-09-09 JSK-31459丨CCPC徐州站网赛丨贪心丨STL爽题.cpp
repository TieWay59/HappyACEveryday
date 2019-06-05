#include<set>
#include<stdio.h>

using namespace std;
typedef long long ll;
struct node {
    int x, y;
} a[100005];

struct xcmp {//��setд�����ıȽϺ���
    bool operator()(const node &a, const node &b) { return a.x > b.x; }
};

struct ycmp {
    bool operator()(const node &a, const node &b) { return a.y > b.y; }
};

set<node, xcmp> xset;
set<node, ycmp> yset;
typedef set<node>::iterator sit;//����������ֱ����<node>����

int main() {
    int n;
    scanf("%d", &n);
    for (int x, y, i = 1; i <= n; i++) {
        scanf("%d%d", &x, &y);
        a[i] = {x, y};
    }
    xset.insert({0, 0});
    yset.insert({0, 0});

    ll ans = 0;
    sit it;
    for (int i = n; i > 0; i--) {
        xset.insert(a[i]);
        it = xset.find(a[i]);
        it++;
        ans += a[i].x - it->x;

        yset.insert(a[i]);
        it = yset.find(a[i]);
        it++;
        ans += a[i].y - it->y;
    }
    printf("%lld\n", ans);
    return 0;
}
