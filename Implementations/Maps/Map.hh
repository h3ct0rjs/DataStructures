#include "vect.hh"
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
    K &getKey() { return key; }
    V getValue() { return value; }
    const K &getKey() const { return key; }
    Node *getLeft() { return left; }
    void setLeft(Node *nl) { left = nl; }
    bool hasLeft() const { return left != nullptr; }
    Node *getRight() { return right; }
    void setRight(Node *nr) { right = nr; }
    bool hasRight() const { return right != nullptr; }
    void setValue(V v) { value = v; }
  };

  Node *root;
  int sz;

public:
  Map() : root(nullptr), sz(0) {}

  int tam() const { return sz; }

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
  bool find(K key) { return find(root, key); }

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
      return find(n->getRight(), key);
    }
  }

public:
  void inorder(Vector<V> v) { inorder(root, v); }

private:
  void inorder(Node *n, Vector<V> v) {
    if (n == nullptr)
      return;
    else {
      inorder(n->getLeft(), v);
      v.add(v.size(), n->getValue());
      inorder(n->getRight(), v);
    }
  }

public:
  Vector<V> Tovect() {
    Vector<V> r;
    inorder(r);
    return r;
  }
};
