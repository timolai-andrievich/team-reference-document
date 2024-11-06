vector<int> g[maxn];
int s[maxn], p[maxn], tin[maxn], tout[maxn];
int head[maxn];
int t = 0;

void sizes(int v = 0) {
  s[v] = 1;
  for (int &u : g[v]) {
    sizes(u);
    s[v] += s[u];
    if (s[u] > s[g[v][0]])
      // &u is a reference, so it can be used as an argument to swap
      swap(u, g[v][0]);
  }
}

void hld(int v = 0) {
  tin[v] = t++;
  for (int u : g[v]) {
    // if the child is heavy -- its next needs to be propagated
    // otherwise it's a head of a new heavy path
    head[u] = (u == g[v][0] ? head[v] : u);
    hld(u);
  }
  tout[v] = t;
}

int val[maxn];
segtree st(0, n);

void upd(int v, int x) { st.upd(tin[v], x); }

int ancestor(int a, int b) { return tin[a] <= tin[b] && tin[b] < tout[a]; }

void up(int &a, int &b, int &ans) {
  while (!ancestor(head[a], b)) {
    ans = min(ans, st.get_min(tin[head[a]], tin[a]));
    a = p[head[a]];
  }
}

int get_min(int a, int b) {
  int ans = inf;
  up(a, b, ans);
  up(b, a, ans);
  if (!ancestor(a, b))
    swap(a, b);
  ans = min(ans, st.get_min(tin[a], tin[b]));
  return ans;
}
