
#include <iostream>
#include <vector>

template <typename T>
struct Stack {
  std::vector<T> v;
  int top;

  Stack() {
    top = -1;
    v.resize(100005);
  }

  void Push(T x) {
    top++;
    v[top] = x;
  }

  T Pop() {
    if (top == -1) {
      std::cout << "error" << '\n';
      return T();
    }
    T x = v[top];
    top--;
    return x;
  }

  T Top() {
    if (top == -1) {
      std::cout << "error" << '\n';
      return T();
    }
    return v[top];
  }

  bool Empty() { return (top == -1); }
  int Size() { return top + 1; }
  void Clear() { top = -1; }
  ~Stack(){};
};

int main() {
  Stack<int> s;
  std::string str;

  while (std::cin >> str) {
    if (str == "exit") {
      std::cout << "bye" << '\n';
      break;
    }
    if (str == "push") {
      int x;
      std::cin >> x;
      s.Push(x);
      std::cout << "ok" << '\n';
    }
    if (str == "pop") {
      std::cout << s.Pop() << '\n';
    }
    if (str == "size") {
      std::cout << s.Size() << '\n';
    }
    if (str == "back") {
      std::cout << s.Top() << '\n';
    }
    if (str == "clear") {
      s.Clear();
      std::cout << "ok" << '\n';
    }
  }
}
