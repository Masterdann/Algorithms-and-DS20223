#include <iostream>

struct Node {
  char data;
  struct Node* next;
  Node(char data) {
    this->data = data;
    next = NULL;
  }
};
struct List {
  Node* head;
  List() { head = NULL; }
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
  ~List(){}
};
int main() {
  std::string s;
  while (getline(std::cin, s)) {
    List lista;
    int n = s.size();
    for (int i = 0; i < n; i++) {
      lista.Push(s[i]);
    }
    lista.Print();
    std::cout << "\n";
  }
}
