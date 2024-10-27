class FT {
public:
  vector<ll> a;
  ll n;
  FT(ll n) : n(n) { a = vector<ll>(n, 0); }
  void u(ll i, ll v) {
    while (i < n) {
      a[i] += v;
      i |= i + 1;
    }
  }
  ll q(ll i) {
    ll r = 0;
    while (i >= 0) {
      r += a[i];
      i &= i + 1;
      i--;
    }
    return r;
  }
};
