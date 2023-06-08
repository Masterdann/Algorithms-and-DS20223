#include <iostream>

class Node {
 public:
  int key;
  Node* left;
  Node* right;
  int height;
};

int Height(Node* node) {
  if (node == NULL) {
    return 0;
  }
  return node->height;
}

int Max(int a, int b) {
  int val;
  if (a >= b) {
    val = a;
  } else {
    val = b;
  }
  return val;
}

Node* NewNode(int key) {
  Node* node = new Node();
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return (node);
}

Node* RightRotate(Node* y) {
  Node* x = y->left;
  if (x != NULL) {
    Node* aux = x->right;
    x->right = y;
    y->left = aux;
    y->height = Max(Height(y->left), Height(y->right)) + 1;
    x->height = Max(Height(x->left), Height(x->right)) + 1;
  }
  return x;
}

Node* LeftRotate(Node* x) {
  Node* y = x->right;
  if (y != NULL) {
    Node* aux = y->left;
    y->left = x;
    x->right = aux;
    x->height = Max(Height(x->left), Height(x->right)) + 1;
    y->height = Max(Height(y->left), Height(y->right)) + 1;
  }
  return y;
}

int GetBalance(Node* node) {
  if (node == NULL) {
    return 0;
  }
  return Height(node->left) - Height(node->right);
}

Node* Insert(Node* node, int key) {
  if (node == NULL) {
    return (NewNode(key));
  }
  if (key < node->key) {
    node->left = Insert(node->left, key);
  } else if (key > node->key) {
    node->right = Insert(node->right, key);
  } else {
    return node;
  }
  node->height = 1 + Max(Height(node->left), Height(node->right));
  int balance = GetBalance(node);
  if (node->left != NULL && node->right != NULL) {
    if (balance > 1 && key < node->left->key) {
      return RightRotate(node);
    }
    if (balance < -1 && key > node->right->key) {
      return LeftRotate(node);
    }
    if (balance > 1 && key > node->left->key) {
      node->left = LeftRotate(node->left);
      return RightRotate(node);
    }
    if (balance < -1 && key < node->right->key) {
      node->right = RightRotate(node->right);
      return LeftRotate(node);
    }
  }
  return node;
}
int Search(struct Node* root, int key) {
  if (root == NULL) {
    return -1;
  }
  if (root->key == key) {
    return key;
  }
  int val = -1;
  if (root->key > key) {
    val = Search(root->left, key);
    if (val == -1) {
      return root->key;
    }
  }
  if (root->key <= key) {
    val = Search(root->right, key);
    if (val == -1) {
      return root->key;
    }
  }
  return val;
}
void DeleteTree(Node* node) {
  if (node == NULL) {
    return;
  }
  DeleteTree(node->left);
  DeleteTree(node->right);
  delete node;
}
int main() {
  int n, ans = -2;
  std::cin >> n;
  Node* root = NULL;
  std::string s;
  int last_answer = 0;
  for (int i = 0; i < n; i++) {
    char x;
    int y;
    std::cin >> x >> y;
    s += x;
    if (x == '+') {
      if (s[i - 1] == '?') {
        root = Insert(root, (last_answer + y) % 1000000000);
      }
      root = Insert(root, y);
    } else {
      ans = Search(root, y);
      if (ans < y) {
        std::cout << -1 << '\n';
      } else {
        std::cout << ans << '\n';
      }
      last_answer = ans;
    }
  }
  DeleteTree(root);
}
