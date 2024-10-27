class ST {
public:
  vector<ll> a;
  ll n;
  ST(vector<ll> &A) {
    n = 1;
    while (n < A.size())
      n <<= 1;
    a = vector<ll>(2 * n, 0);
    copy(A.begin(), A.end(), a.begin() + n);
    for (ll i = n - 1; i > 0; i--) {
      a[i] = a[2 * i] + a[2 * i + 1];
    }
  }

  ll q(ll l, ll r) { //[l, r]
    l += n;
    r += n;
    ll res = 0;
    while (l < r) {
      if (l % 2 == 1) {
        res += a[l];
        l++;
      }
      if (r % 2 == 0) {
        res += a[r];
        r--;
      }
      l >>= 1;
      r >>= 1;
    }
    if (l == r) {
      res += a[l];
    }
    return res;
  }

  void set(ll i, ll v) {
    i += n;
    a[i] = v;
    while (i > 0) {
      i >>= 1;
      a[i] = a[2 * i] + a[2 * i + 1];
    }
  }
};
