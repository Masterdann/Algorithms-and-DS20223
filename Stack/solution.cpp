#include <iostream>
#include <vector>
int main() {
  std::string s;
  std::vector<int> v(100005);
  for (int i = 0; i < 100004; i++) v[i] = -1;
  int flag = 0;
  while (std::cin >> s) {
    if (s == "exit") {
      std::cout << "bye";
      break;
    }
    if (s == "push") {
      int x;
      std::cin >> x;
      v[flag] = x;
      flag++;
      std::cout << "ok";
    }
    if (s == "pop") {
      if (flag == 0) {
        std::cout << "error";
      } else {
        std::cout << v[flag - 1];
        v[flag - 1] = -1;
        flag--;
      }
    }
    if (s == "size") {
      std::cout << flag;
    }
    if (s == "back") {
      if (flag == 0)
        std::cout << "error";
      else
        std::cout << v[flag - 1];
    }
    if (s == "clear") {
      std::cout << "ok";
      flag = 0;
    }
    std::cout << "\n";
  }
}
