#include <iostream>
template <class T>
struct DynamicArray {
  int capacity_v;
  int size_v;
  T* v;

  DynamicArray() {
    capacity_v = 1;
    size_v = 0;
    v = new T[capacity_v];
  }

  void Resize(int new_cap) {
    capacity_v = new_cap;
    T* temp = new T[capacity_v];

    size_v = std::min(

        size_v, capacity_v);
    for (int i = 0; i < size_v; ++i) {
      temp[i] = v[i];
    }
    delete[] v;

    v = temp;
  }

  void Push(T value) {
    if (size_v == capacity_v) {
      Resize(capacity_v * 2);
    }
    size_v++;
    v[size_v - 1] = value;
  }

  T Pop() {
    if (size_v > 0) {
      size_v--;
      T temp = v[size_v];
      if (size_v <= capacity_v / 2) {
        Resize(capacity_v / 2);
      }
      if (size_v == 0) {
        Clear();
      }
      return temp;
    }
    throw "error";
  }

  T At(int i) {
    if (i >= 0 and i < size_v) {
      return v[i];
    }
    throw "error";
  }

  int Size() { return size_v; }

  int Capacity() { return capacity_v; }

  void Clear() {
    size_v = 0;
    delete[] v;
    v = new T[capacity_v];
    capacity_v = 1;
  }
  ~DynamicArray() { delete[] v; }
};
void PushElement(DynamicArray<int>& vect, int& x) {
  std::cin >> x;
  vect.Push(x);
  std::cout << "ok" << '\n';
}
void ResizeVect(DynamicArray<int>& vect, int& x) {
  std::cin >> x;
  vect.Resize(x);
  std::cout << "ok" << '\n';
}
void AtVect(DynamicArray<int>& vect, int& x) {
  std::cin >> x;
  std::cout << vect.At(x) << '\n';
}
int main() {
  DynamicArray<int> vect = DynamicArray<int>();
  std::string s;
  int x = 0;
  while (s != "exit") {
    try {
      std::cin >> s;
      if (s == "push") {
        PushElement(vect, x);
      } else if (s == "at") {
        AtVect(vect, x);
      } else if (s == "pop") {
        std::cout << vect.Pop() << '\n';
      } else if (s == "resize") {
        ResizeVect(vect, x);
      } else if (s == "capacity") {
        std::cout << vect.Capacity() << '\n';
      } else if (s == "size") {
        std::cout << vect.Size() << '\n';
      } else if (s == "clear") {
        vect.Clear();
        std::cout << "ok" << '\n';
      } else if (s == "exit") {
        std::cout << "bye" << '\n';
        break;
      }
    } catch (...) {
      std::cout << "error" << '\n';
    }
  }
}
