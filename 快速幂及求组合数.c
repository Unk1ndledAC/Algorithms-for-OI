#define ll long long
ll mod = 1e9 + 7;
ll qpow(ll x, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) {
            res = (res * x) % mod;
        }
        x = (x * x) % mod;
        n >>= 1;
    }
    return res;
}

ll qmod(ll n) {
    return qpow(n, mod - 2);
}

ll C(ll n, ll k) {
    if (k > n - k) {
        k = n - k;
    }
    ll res = 1;
    for (ll i = 0; i < k; ++i) {
        res = (res * (n - i)) % mod;
        res = (res * qmod(i + 1)) % mod;
    }
    return res;
}