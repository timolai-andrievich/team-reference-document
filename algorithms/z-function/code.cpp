vector<ll> z_function(string s) {
  vector<ll> z(s.size());
  int l = 0, r = 0, n = s.size();
  z[0] = 0;
  for (int i = 1; i < n; i++) {
    if (r >= i) {
      z[i] = min((int)(z[i - l]), r - i + 1);
    }
    while (z[i] + i < n && s[z[i]] == s[z[i] + i]) {
      z[i]++;
    }
    if (i + z[i] - 1 > r) {
      l = i;
      r = i + z[i] - 1;
    }
  }
  return z;
}
