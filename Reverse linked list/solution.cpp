#include <iostream>

struct Node {
  char data;
  struct Node* next;
  Node(char data) {
    this->data = data;
    next = NULL;
  }
};
struct Lilist {
  Node* head;
  Lilist() { head = NULL; }
  void Print() {
    struct Node* puntero = head;
    while (puntero != NULL) {
      std::cout << puntero->data;
      puntero = puntero->next;
    }
  }
  void Push(char data) {
    Node* puntero = new Node(data);
    puntero->next = head;
    head = puntero;
  }
};
int main() {
  std::string s;
  while (getline(std::cin, s)) {
    Lilist lista;
    int n = s.size();
    for (int i = 0; i < n; i++) {
      lista.Push(s[i]);
    }
    lista.Print();
    std::cout << "\n";
  }
}
