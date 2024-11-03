typedef int ll;
using namespace std;
#include <vector>
void lca_example() {
  ll n;                    // Number of vertices in a graph
  vector<vector<ll>> C(n); // Array of children of nodes
  vector<ll> depth, vtx;
  auto dfs = [&](ll u, ll d, auto self) -> void {
    depth.push_back(d);
    vtx.push_back(u);
    for (ll v : C[u]) {
      self(v, d + 1, self);
      depth.push_back(d);
      vtx.push_back(u);
    }
  };
  dfs(0, 0, dfs);
  vector<ll> I(n);
  for (ll i = 0; i < vtx.size(); i++) {
    I[vtx[i]] = i;
  }
  MinSegmentTree tree(depth);
  auto LCA = [&](ll u, ll v) -> ll {
    ll U = I[u], V = I[v];
    if (U > V) {
      swap(U, V);
    }
    return vtx[tree.get_min_index(U, V)];
  };
}
