#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

//
ll exGCD(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll gcd = exGCD(b, a % b, x, y);
    ll old_x = x;
    x = y;
    y = old_x - (a / b) * x;
    return gcd;
}

int main() {
    //do this
    ll a, b, x, y, gcd;
    while (cin >> a >> b) {
        gcd = exGCD(a, b, x, y);
        if (gcd != 1) {
            cout << "sorry\n";
        } else {
            if (x < 0) {
                ll num = (abs(x) - 1) / (b / gcd) + 1;
                x += num * (b / gcd);
                y -= num * (a / gcd);
            }
            cout << x << ' ' << y << '\n';
        }
    }
}