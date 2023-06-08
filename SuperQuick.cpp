#include <iostream>

template <typename T>
struct IsLessOrEqual {
  bool operator()(const T& l, const T& r) const { return l <= r; }
};
template <class T, class TLessOrEqual = IsLessOrEqual<T>>
void QuickSort(T* v, T left, T right,
               const TLessOrEqual& is_less = TLessOrEqual()) {
  T x = v[(left + right) / 2], buffer;
  T begin = left, end = right;
  while (is_less(begin, end)) {
    while (v[begin] < x) {
      begin++;
    }
    while (v[end] > x) {
      end--;
    }
    if (is_less(begin, end)) {
      buffer = v[begin];
      v[begin] = v[end];
      v[end] = buffer;
      begin++;
      end--;
    }
  }
  if (left < end) {
    QuickSort(v, left, end);
  }
  if (begin < right) {
    QuickSort(v, begin, right);
  }
}
template <class T>
void InsertionSort(T* v, int n) {
  for (int i = 1; i < n; i++) {
    T key = v[i];
    int j = i - 1;
    while (j >= 0 && v[j] > key) {
      v[j + 1] = std::move(v[j]);
      --j;
    }
    v[j + 1] = std::move(key);
  }
}
int main() {
  int n;
  std::cin >> n;
  if (n >= 256) {
    int* v = new int[n];
    for (int i = 0; i < n; i++) {
      std::cin >> v[i];
    }
    QuickSort<int>(v, 0, n - 1);
    for (int i = 0; i < n; i++) {
      std::cout << v[i] << " ";
    }
    std::cout << '\n';
    delete[] v;
  } else {
    int* v = new int[n];
    for (int i = 0; i < n; i++) {
      std::cin >> v[i];
    }
    InsertionSort(v, n);
    for (int i = 0; i < n; i++) {
      std::cout << v[i] << " ";
    }
    std::cout << '\n';
    delete[] v;
  }
  return 0;
}
