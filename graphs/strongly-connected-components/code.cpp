void find_SCC() {
  ll n, m;
  vector<set<ll>> N(n);    // Neighbors
  vector<set<ll>> invN(n); // Neighbors in transposed graph
  vector<bool> visited(n);
  vector<ll> Tout(n);
  ll time = 0;
  auto dfs = [&](ll u, auto self) -> void {
    if (visited[u])
      return;
    visited[u] = true;
    for (ll v : N[u]) {
      if (visited[v])
        continue;
      self(v, self);
    }
    Tout[u] = ++time;
  };
  for (ll u = 0; u < n; u++) {
    dfs(u, dfs);
  }
  vector<ll> I(n);
  for (ll i = 0; i < n; i++)
    I[i] = i;
  sort(I.begin(), I.end(), [&](ll i, ll j) { return Tout[i] > Tout[j]; });
  fill(visited.begin(), visited.end(), false);
  DSU<ll> dsu;
  auto dfs2 = [&](ll u, auto self) -> void {
    if (visited[u])
      return;
    visited[u] = true;
    for (ll v : invN[u]) {
      if (visited[v])
        continue;
      dsu.merge(u, v);
      self(v, self);
    }
  };
  for (ll u : I)
    dfs2(u, dfs2);
  // dsu holds information about strongly connected components
}
