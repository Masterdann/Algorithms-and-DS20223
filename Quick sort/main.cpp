#include <algorithm>
#include <iostream>
#include <vector>

int Partition(std::vector<int>& v, int low, int high) {
  int pivot = v[(low + high) / 2];
  int i = low - 1;
  int j = high + 1;
  while (true) {
    do {
      i++;
    } while (v[i] < pivot);

    do {
      j--;
    } while (v[j] > pivot);

    if (i >= j) {
      return j;
    }

    std::swap(v[i], v[j]);
  }
}
void QuickSort(std::vector<int>& v, int low, int high) {
  if (low < high) {
    int pivot_index = Partition(v, low, high);
    QuickSort(v, low, pivot_index);
    QuickSort(v, pivot_index + 1, high);
  }
}
void InsertionSort(std::vector<int>& v, int n) {
  int pivote, flag;
  for (int i = 1; i < n; i++) {
    pivote = v[i];
    flag = i - 1;
    while (flag >= 0 and v[flag] > pivote) {
      v[flag + 1] = v[flag];
      flag--;
    }
    v[flag + 1] = pivote;
  }
}
int main() {
  int n;
  std::cin >> n;
  std::vector<int> v(n);
  for (int i = 0; i < n; i++) {
    std::cin >> v[i];
  }
  if (n >= 256) {
    QuickSort(v, 0, n - 1);
  } else {
    InsertionSort(v, n);
  }
  for (int i = 0; i < n; i++) {
    std::cout << v[i] << '\n';
  }
}
