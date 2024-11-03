void rearrange(vector<ll>::iterator begin, vector<ll>::iterator end) {
  ll n = end - begin;
  if (n == 2)
    return;
  rearrange(begin, begin + n / 2);
  rearrange(begin + n / 2, end);
  for (ll i = 0; i < n / 4; i++) {
    iter_swap(begin + n / 4 + i, begin + n / 2 + i);
  }
}

void fft(vector<ll>::iterator begin, vector<ll>::iterator end) {
  ll n = end - begin;
  auto mid = begin + n / 2;
  if (n == 1)
    return;
  rearrange(begin, end);
  fft(begin, mid);
  fft(mid, end);
  ll w = unity_root(n);
  ll W = 1;
  for (ll i = 0; i < n / 2; i++) {
    *(mid + i) = mul(*(mid + i), W);
    W = mul(W, w);
  }
  for (ll i = 0; i < n / 2; i++) {
    *(begin + i) = add(*(begin + i), *(mid + i));
    *(mid + i) = sub(*(begin + i), mul(2, *(mid + i)));
  }
}

void ifft(vector<ll>::iterator begin, vector<ll>::iterator end) {
  ll n = end - begin;
  auto mid = begin + n / 2;
  if (n == 1)
    return;
  rearrange(begin, end);
  ifft(begin, mid);
  ifft(mid, end);
  ll w = inv(unity_root(n));
  ll W = 1;
  for (ll i = 0; i < n / 2; i++) {
    *(mid + i) = mul(*(mid + i), W);
    W = mul(W, w);
  }
  for (ll i = 0; i < n / 2; i++) {
    *(begin + i) = add(*(begin + i), *(mid + i));
    *(mid + i) = sub(*(begin + i), mul(2, *(mid + i)));
  }
  for (auto it = begin; it < end; it++) {
    *it = mul(*it, inv(2));
  }
}
