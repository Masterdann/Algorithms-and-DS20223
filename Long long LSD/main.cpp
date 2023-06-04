#include <iostream>
#include <vector>

std::vector<long long> RadixSort(std::vector<long long>& v, long long maxi) {
  long long max_bytes = sizeof(maxi);
  int n = v.size();
  for (int i = 0; i < max_bytes; i++) {
    std::vector<std::vector<long long> > buckets(256);
    for (int j = 0; j < n; j++) {
      long long byte = (v[j] >> (8 * i)) & 0xFF;
      buckets[byte].push_back(v[j]);
    }
    int k = 0;
    for (int l = 0; l < 256; l++) {
      int lol = buckets[l].size();
      for (int j = 0; j < lol; j++) {
        v[k++] = buckets[l][j];
      }
    }
  }
  return v;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<long long> v(n);
  long long maxi = -1;
  for (int i = 0; i < n; i++) {
    std::cin >> v[i];
    if (maxi < v[i]) {
      maxi = v[i];
    }
  }
  std::vector<long long> ans = RadixSort(v, maxi);
  for (int i = 0; i < n; i++) {
    std::cout << ans[i] << '\n';
  }
}
