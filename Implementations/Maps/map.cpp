#include <iostream>
using namespace std;
template <typename K, typename V> class Map {
private:
  class Node {
  private:
    K key;
    V value;
    Node *left;
    Node *right;

  public:
    Node(K k, V v) : key(k), value(v), left(nullptr), right(nullptr) {}
    T &getKey() { return key; }
    get(K key) { return value; }
    const T &getKey() const { return key; }
    Node *getLeft() { return left; }
    void setLeft(Node *nl) { left = nl; }
    bool hasLeft() const { return left != nullptr; }
    Node *getRight() { return right; }
    void setRight(Node *nr) { right = nr; }
    bool hasRight() const { return right != nullptr; }
  };
  Node *root;
  int sz;

public:
  Map() : root(nullptr), sz(0) {}
  void insert(K key, V value) { root = insert(root, key, value); }

private:
  Node *insert(Node *n, K key, V value) {
    if (n == nullptr) {
      Node *e = new Node(key, value);
      sz++;
      return e;
    }
    if (n->getKey() == key)
      return n;
    if (key < n->getKey()) {
      n->setLeft(insert(n->getLeft(), key, value));
      return n;
    }
    n->setRight(insert(n->getRight(), key, value));
    return n;
  }

public:
  bool find(K key) { return find(root, key) }
private:
  bool find(Node *n, K key) {
    if (n == nullptr)
      return false;
    else if (key == n->getKey())
      return true;
    else {
      if (key < n->getKey()) {
        return find(n->getLeft(), key);
      }
      retun find(n->getRight(), key);
    }
  }
};
