#include <iostream>
#include <vector>

template <typename K, typename V>
class HashMap {
 private:
  struct Node {
    K key;
    V value;
    Node* next;
    Node(K k, V v) : key(k), value(v), next(nullptr) {}
  };

  std::vector<Node*> table_;
  int capacity_;
  int size_;

  int Hash(K key) const { return std::hash<K>()(key) % capacity_; }

 public:
  HashMap(int capacity) : capacity_(capacity), size_(0) {
    table_.resize(capacity_, nullptr);
  }

  ~HashMap() {
    for (int i = 0; i < capacity_; i++) {
      Node* curr = table_[i];
      while (curr != nullptr) {
        Node* next = curr->next;
        delete curr;
        curr = next;
      }
    }
  }

  void Insert(K key, V value) {
    int index = Hash(key);
    Node* curr = table_[index];
    while (curr != nullptr) {
      if (curr->key == key) {
        curr->value = value;
        return;
      }
      curr = curr->next;
    }
    Node* new_node = new Node(key, value);
    new_node->next = table_[index];
    table_[index] = new_node;
    size_++;
  }

  bool Get(K key) const {
    int index = Hash(key);
    Node* curr = table_[index];
    while (curr != nullptr) {
      if (curr->key == key) {
        return true;
      }
      curr = curr->next;
    }
    return false;
  }

  void Remove(K key) {
    int index = Hash(key);
    Node* curr = table_[index];
    Node* prev = nullptr;
    while (curr != nullptr) {
      if (curr->key == key) {
        if (prev == nullptr) {
          table_[index] = curr->next;
        } else {
          prev->next = curr->next;
        }
        delete curr;
        size_--;
        return;
      }
      prev = curr;
      curr = curr->next;
    }
  }
};

int main() {
  int n;
  std::cin >> n;
  HashMap<int, int> mp(n);
  for (int i = 0; i < n; i++) {
    char x;
    int y;
    std::cin >> x >> y;
    if (x == '+') {
      mp.Insert(y, 1);
    }
    if (x == '-') {
      mp.Remove(y);
    }
    if (x == '?') {
      if (mp.Get(y)) {
        std::cout << "YES" << '\n';
      } else {
        std::cout << "NO" << '\n';
      }
    }
  }
}
