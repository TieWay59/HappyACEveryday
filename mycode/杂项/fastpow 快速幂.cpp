ll fpow(ll a, ll b, ll mod = 1000000007) {
    ll ret = 1;
    while (b) {
        if (b & 1)ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}
