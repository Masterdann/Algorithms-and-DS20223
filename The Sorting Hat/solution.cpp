
#include <iostream>
#include <stack>
using std::stack;
template <class T>
class MinStack {
 public:
  void Push(const T& value) {
    min_stack_.emplace(value,
                       min_stack_.empty()
                           ? value
                           : std::min(value, min_stack_.top().min_value));
  }
  T GetMin() { return min_stack_.top().min_value; }
  void Pop() { min_stack_.pop(); }
  bool Empty() { return min_stack_.empty(); }
  T Top() { return min_stack_.top().value; }
  void Clear() {
    while (!min_stack_.empty()) {
      min_stack_.pop();
    }
  }
  size_t Size() { return min_stack_.size(); }

 private:
  struct Pair {
    T value;
    T min_value;
    Pair(T value, T min_value) {
      this->value = value;
      this->min_value = min_value;
    }
  };
  stack<Pair> min_stack_;
};
template <class T>
struct Queue {
  MinStack<T> s1, s2;
  T size;
  T first;
  Queue() { size = 0; }
  void Enqueue(T data) {
    s1.Push(data);
    if (size == 0) {
      first = data;
    }

    size++;
  }
  T Dequeue() {
    if (s1.Empty() && s2.Empty()) {
      throw "error";
    }
    if (s2.Empty()) {
      while (!s1.Empty()) {
        s2.Push(s1.Top());
        s1.Pop();
      }
    }
    int x = s2.Top();
    s2.Pop();
    if (!s2.Empty()) {
      first = s2.Top();
    }
    size--;
    return x;
  }
  T Front() {
    if (s1.Empty() && s2.Empty()) {
      throw "error";
    }
    if (s2.Empty()) {
      while (!s1.Empty()) {
        s2.Push(s1.Top());
        s1.Pop();
      }
    }
    return s2.Top();
  }
  int Size() { return size; }
  void Clear() {
    if (!s1.Empty()) {
      s1.Clear();
    }
    if (!s2.Empty()) {
      s2.Clear();
    }
    size = 0;
  }
  T Min() {
    if (s1.Empty() && s2.Empty()) {
      throw "error";
    }
    if (s1.Empty()) {
      return s2.GetMin();
    }
    if (s2.Empty()) {
      return s1.GetMin();
    }
    return std::min(s1.GetMin(), s2.GetMin());
  }
  ~Queue() {}
};
int main() {
  Queue<int> q1 = Queue<int>();
  int n;
  std::cin >> n;
  std::string s;
  for (int i = 0; i < n; i++) {
    std::cin >> s;
    try {
      if (s == "enqueue") {
        int elem;
        std::cin >> elem;
        q1.Enqueue(elem);
        std::cout << "ok" << std::endl;
      } else if (s == "front") {
        std::cout << q1.Front() << std::endl;
      } else if (s == "dequeue") {
        std::cout << q1.Dequeue() << std::endl;
      } else if (s == "size") {
        std::cout << q1.Size() << std::endl;
      } else if (s == "clear") {
        q1.Clear();
        std::cout << "ok" << std::endl;
      } else if (s == "min") {
        std::cout << q1.Min() << std::endl;
      }
    } catch (...) {
      std::cout << "error" << std::endl;
    }
  }
}
