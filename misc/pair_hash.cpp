struct hash_pair {
  template <class A, class B> size_t operator()(const pair<A, B> &p) const {
    auto h1 = hash<A>{}(p.first);
    auto h2 = hash<B>{}(p.second);
    return h1 * 33 + h2;
  }
}
