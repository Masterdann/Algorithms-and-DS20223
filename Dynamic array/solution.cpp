#include <iostream>

int main() {
    std::string s;
    int potencias[56];
    potencias[0] = 1;
    int v[100005];
    for (int i = 0; i < 100004; i++) {
        v[i] = -1;
    }
    int flag = 0;
    int capacity = 1;
    for (int i = 1; i < 50; i++) {
        potencias[i] = potencias[i - 1] * 2;
    }
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
        if (s == "at") {
            int x;
            std::cin >> x;
            if (flag - 1 < x) {
                std::cout << "error";
            } else
                std::cout << v[x];
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
        if (s == "capacity") {
            for (int i = 0; i < 50; i++) {
                if (potencias[i] >= flag) {
                    capacity = potencias[i];
                    break;
                }
            }
            std::cout << capacity;
        }
        if (s == "size") {
            std::cout << flag;
        }
        if (s == "resize") {
            std::cout << "ok";
            int x;
            std::cin >> x;
            flag = x;
        }
        if (s == "clear") {
            std::cout << "ok";
            flag = 0;
            capacity = 1;
        }
        std::cout << "\n";
    }
}
