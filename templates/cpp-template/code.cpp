#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
template <class T> istream &operator>>(istream &is, vector<T> &v);
template <class T> ostream &operator<<(ostream &os, vector<T> &v);

void solve() {
  // Code goes here
}

int main() {
  cout.tie(NULL);
  cin.tie(NULL);
  cout << fixed << setprecision(9);
  ll t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
}

template <class T> istream &operator>>(istream &is, vector<T> &v) {
  for (size_t i = 0; i < v.size(); i++) {
    is >> v[i];
  }
  return is;
}

template <class T> ostream &operator<<(ostream &os, vector<T> &v) {
  for (size_t i = 0; i < v.size(); i++) {
    os << v[i] << (i == v.size() - 1 ? "" : " ");
  }
  return os;
}
