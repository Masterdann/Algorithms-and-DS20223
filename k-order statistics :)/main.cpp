#include <iostream>
#define MOD 1e7 + 4321;
int n, k, a0, a1, an1, an2, mod;
int a[10000010];
void Init() {
  for (int i = 0; i <= n; i++) {
    a[i] = 0;
  }
  a[0] = a0;
  a[1] = a1;
  an1 = a1;
  an2 = a0;
}
void Generate() {
  for (int i = 2; i < n; i++) {
    a[i] = an1 * 123 + an2 * 45;
    an2 = an1 % mod;
    an1 = a[i] % mod;
    a[i] = a[i] % mod;
  }
}
int Solve() {
  using std::swap;
  for (int l = 0, r = n - 1;;) {
    if (r <= l + 1) {
      if (r == l + 1 and a[r] < a[l]) {
        swap(a[l], a[r]);
      }
      return a[k];
    }
    int mid = (l + r) >> 1;
    swap(a[mid], a[l + 1]);
    if (a[l] > a[r]) {
      swap(a[l], a[r]);
    }
    if (a[l + 1] > a[r]) {
      swap(a[l + 1], a[r]);
    }
    if (a[l] > a[l + 1]) {
      swap(a[l], a[l + 1]);
    }
    int i = l + 1, j = r;
    int aux = a[l + 1];
    while (1) {
      while (a[++i] < aux) {
      };
      while (a[--j] > aux) {
      };
      if (i > j) {
        break;
      }
      swap(a[i], a[j]);
    }
    a[l + 1] = a[j];
    a[j] = aux;
    if (j >= k) {
      r = j - 1;
    }
    if (j <= k) {
      l = i;
    }
  }
}
int main() {
  std::cin >> n >> k >> a0 >> a1;
  mod = MOD;
  Init();
  Generate();
  k--;
  std::cout << Solve() << '\n';
}
