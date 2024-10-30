constexpr inline ll fastpow(ll x, ll p) {
  ll res = 1;
  while (p) {
    if (p & 1) {
      res *= x;
      res %= mod;
    }
    x *= x;
    x %= mod;
    p >>= 1;
  }
  return res;
}
