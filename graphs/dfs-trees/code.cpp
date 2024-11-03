void build_tree_on_simple_graph() {
  ll n;                          // Number of vertices
  ll m;                          // Number of edges
  vector<vector<ll>> N(n + 1);   // Neighbors
  vector<pair<ll, ll>> E(m);     // Edges
  vector<bool> V(n + 1);         // Visited
  vector<ll> T(n + 1), L(n + 1); // Time, low
  auto hang = [&](ll u, ll time, auto self) -> void {
    T[u] = time;
    V[u] = true;
    L[u] = time;
    for (ll v : N[u]) {
      if (V[v] && T[v] < time - 1) {
        // (u, v) is a backlink
        L[u] = min(L[u], T[v]);
      } else if (!V[v]) {
        // v is a child of u
        self(v, time + 1, self);
        L[u] = min(L[u], L[v]);
      } else {
        // v is either a parent of u, or a descendant of u
      }
    }
  };
  hang(1, 0, hang); // Assuming 1 is a vertice
  auto bridge = [&](ll u, ll v) {
    if (T[u] > T[v])
      swap(u, v);
    return L[v] == T[v];
  };
}
