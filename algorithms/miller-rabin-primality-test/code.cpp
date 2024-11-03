bool miller_rabin(ll n, ll base) {
  ll d = n - 1, s = 0;
  while ((d & 1) == 0) {
    d >>= 1;
    s++;
  }
  ll x = fastpow(base, d, n);
  for (ll i = 0; i < s; i++) {
    ll y = x * x % n;
    if (y == 1 && x != 1 && x != n - 1)
      return false;
    x = y;
  }
  return x == 1;
}

bool is_prime(ll n) {
  if (n < 2)
    return false;
  array<ll, 12> bases = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
  if (n < 500) {
    for (ll base : bases) {
      if (n % base == 0 && n != base)
        return false;
    }
    return true;
  }
  for (ll base : bases) {
    if (!miller_rabin(n, base))
      return false;
  }
  return true;
}
