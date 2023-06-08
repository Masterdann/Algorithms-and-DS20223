#include <iostream>

template <class T>
struct Sequence {
  int n1;
  T* temp;
  T first;
  T second;
  Sequence(int n, T first, T second) {
    n1 = n;
    temp = new T[n1];
    temp[0] = first;
    temp[1] = second;
    Fill();
  }
  void Fill() {
    for (int i = 2; i < n1; i++) {
      temp[i] = (temp[i - 1] * 123 + temp[i - 2] * 45) % (10000000 + 4321);
    }
  }
  int Partition(int left, int right) {
    if (left != right)
      std::swap(temp[left + rand() % (right - left)], temp[right]);
    T x = temp[right];
    int i = left - 1;
    for (int j = left; j <= right; j++) {
      if (temp[j] <= x) std::swap(temp[++i], temp[j]);
    }
    return i;
  }
  T Find(int k) {
    int left = 0, right = n1 - 1;
    for (;;) {
      int pos = Partition(left, right);
      if (pos < k)
        left = pos + 1;
      else if (pos > k)
        right = pos - 1;
      else
        return temp[k];
    }
  }
  ~Sequence() { delete[] temp; }
};
int main() {
  int n, k, a0, a1;
  std::cin >> n >> k >> a0 >> a1;
  Sequence<long long int> s1 = Sequence<long long int>(n, a0, a1);
  std::cout << s1.Find(k - 1) << std::endl;
}
