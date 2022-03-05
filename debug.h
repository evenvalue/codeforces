#ifndef CODEFORCES_DEBUG_H
#define CODEFORCES_DEBUG_H

#include <bits/stdc++.h>
using namespace std;

struct Foo {
  static string to_string(const int x) {
    return std::to_string(x);
  }

  static string to_string(const long long &x) {
    return std::to_string(x);
  }

  static string to_string(const double &d) {
    return std::to_string(d);
  }

  static string to_string(const long double &ld) {
    return std::to_string(ld);
  }

  static string to_string(const string &s) {
    return s;
  }

  static string to_string(const bool &b) {
    return (b ? "true" : "false");
  }

  template<typename T1, typename T2>
  static string to_string(const pair<T1, T2> &p) {
    return "[ " + to_string(p.first) + ", " + to_string(p.second) + " ]";
  }

  template<typename T>
  static string to_string(const vector<T> &v) {
    string s = "[ ";
    for (const T &x : v) {
      s += to_string(x) + ", ";
    }
    if (s.size() > 2) {
      s.pop_back(), s.pop_back();
    }
    s += " ]";
    return s;
  }

  template<typename T, typename Cmp>
  static string to_string(priority_queue<T, vector<T>, Cmp> pq) {
    vector<T> v;
    while (not pq.empty()) {
      v.push_back(pq.top());
      pq.pop();
    }
    return to_string(v);
  }

  template<typename T>
  static string to_string(const set<T> &s) {
    vector<T> v;
    for (const T &x : s) {
      v.push_back(x);
    }
    return to_string(v);
  }

  template<typename T>
  static string to_string(const multiset<T> &s) {
    vector<T> v;
    for (const T &x : s) {
      v.push_back(x);
    }
    return to_string(v);
  }

  template<typename T1, typename T2>
  static string to_string(const map<T1, T2> &m) {
    vector<pair<T1, T2>> v;
    for (const auto &[x, y] : m) {
      v.emplace_back(x, y);
    }
    return to_string(v);
  }
};

vector<string> sep(const string &arguments) {
  vector<string> v(1);
  int open = 0;
  for (const char c : arguments) {
    if (c == ',' and open == 0) v.emplace_back();
    if ((c == ' ' or c == ',') and open == 0) continue;
    if (c == '(') open++;
    if (c == ')') open--;
    v.back() += c;
  }
  return v;
}

template<typename... Args>
void print(const string &arguments, Args &&...values) {
  const auto v = sep(arguments);
  int i = 0;
  (..., (cerr << v[i++] << " = " << Foo::to_string(values) << '\n'));
}

#endif//CODEFORCES_DEBUG_H
