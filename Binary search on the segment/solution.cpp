#include <iostream>

template <class T>
bool BinarySearch(T* l, T* r, T val) {
  r = r - 1;
  while (l < r) {
    T* mid = l + ((r - l) / 2);
    if (*(mid) == val) {
      return true;
    }
    if (*(mid) < val) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  return false;
}
int main() {
  int n;
  std::cin >> n;
  int* arr = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
  int q;
  std::cin >> q;
  int l;
  int r;
  while (q > 0) {
    int val;
    std::cin >> l >> r >> val;
    int* start = &arr[l];
    int* end = &(arr[r]);
    end += 1;
    bool ans = BinarySearch<int>(start, end, val);
    if (ans) {
      std::cout << "YES"<<'\n';
    } else {
      std::cout << "NO"<<'\n';
    }
    q--;
  }
  delete[] arr;
  return 0;
}
