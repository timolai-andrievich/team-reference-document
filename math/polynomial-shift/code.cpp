vector<ll> shift(vector<ll> P, ll a) {
  ll n = 1;
  auto p = [&](ll i) { return i < P.size() ? P[i] : 0; };
  while (n < P.size())
    n <<= 1;
  vector<ll> V(n * 2), U(n * 2), G(n * 2);
  for (ll i = 0; i < n; i++) {
    U[i] = mul(F[n - i - 1], p(n - i - 1));
    V[i] = div(fastpow(a, i), F[i]);
  }
  // Convolve U and V using FFT
  fft(U);
  fft(V);
  for (ll i = 0; i < n * 2; i++) {
    G[i] = mul(U[i], V[i]);
  }
  ifft(G);
  vector<ll> Q(P.size());
  for (ll i = 0; i < P.size(); i++) {
    Q[i] = div(G[n - i - 1], F[i]);
  }
  return Q;
}
