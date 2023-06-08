
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
struct Stack {
  vector<T> v;
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
      cerr << "error" << endl;
      return T();
    }
    T x = v[top];
    top--;
    return x;
  }

  T Top() {
    if (top == -1) {
      cerr << "error" << endl;
      return T();
    }
    return v[top];
  }

  bool Empty() { return (top == -1); }
  int Size() { return top + 1; }
  void Clear() { top = -1; }
};

int main() {
  Stack<int> s;
  string str;

  while (cin >> str) {
    if (str == "exit") {
      cout << "bye" << endl;
      break;
    }
    if (str == "push") {
      int x;
      cin >> x;
      s.Push(x);
      cout << "ok" << endl;
    }
    if (str == "pop") {
      cout << s.Pop() << endl;
    }
    if (str == "size") {
      cout << s.Size() << endl;
    }
    if (str == "back") {
      cout << s.Top() << endl;
    }
    if (str == "clear") {
      s.Clear();
      cout << "ok" << endl;
    }
  }
}
