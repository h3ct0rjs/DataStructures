#include <iostream>
#include <random>

using namespace std;

template <typename T> class Treap {
private:
  class Node {
    T key;
    double priority;
    Node *left;
    Node *right;

  public:
    Node(T elem) : key(elem), left(nullptr), right(nullptr) {
      priority = numero_random();
    }
    T getKey() { return key; }
    T getProb() { return priority; }
    Node *getLeft() { return left; }
    Node *getRight() { return right; }
    bool hasLeft() const { return left != nullptr; }
    bool hasRight() const { return right != nullptr; }
    void setLeft(Node *nl) { left = nl; }
    void setRight(Node *nr) { right = nr; }
    void setKey(T elem) { key = elem; }
    void setProb(double p) { priority = p; }
    // número random
    double numero_random() {
      random_device rd;
      mt19937 gen(rd());
      uniform_int_distribution<> dis(0.00, 100.00);
      double result = dis(gen);
      return result;
    }
  };

  Node *root;
  int sz;

public:
  Treap() : root(nullptr), sz(0) {}
  bool empty() const { return root == nullptr; }
  int size() const { return sz; }

  // busqueda de un elemento en un Treap
private:
  Node *search(Node *root, T key) {

    if (root == nullptr)
      return nullptr;
    if (key < root->getkey())
      return search(root->getLeft(), key);
    if (key > root->getkey())
      return search(root->getRight(), key);
    return root;
  }

private:
  Node *rotateRight(Node *x, Node *y) {
    Node *B = x->getRight();
    x->setRight(y);
    y->setLeft(B);
    return x;
  }

  Node *rotateLeft(Node *x, Node *y) {
    Node *B = y->getLeft();
    x->setRight(B);
    y->setLeft(x);
    return y;
  }

public:
  void insert(T elem) { root = insert(root, elem); }

private:
  Node *insert(Node *n, T elem) {
    if (n == nullptr) {
      Node *e = new Node(elem);
      sz++;
      return e;
    }
    if (n->getKey() == elem)
      return n;
    if (elem < n->getKey()) {
      n->setLeft(insert(n->getLeft(), elem));
      if (n->getLeft()->getProb() < n->getProb()) {
        return rotateRight(n->getLeft(), n);
      } else {
        return n;
      }
    } else {
      n->setRight(insert(n->getRight(), elem));
      if (n->getRight()->getProb() < n->getProb()) {
        return rotateLeft(n, n->getRight());
      } else {
        return n;
      }
    }
  }

  Node *findMin(Node *n) {
    while (n->getLeft() != nullptr) {
      n = n->getLeft();
    }
    return n;
  }

  Node *aux(Node *n) {
    if (n->hasRight() && n->hasLeft()) {
      if (n->getProb() > n->getLeft()->getProb() ||
          n->getProb() > n->getRight()->getProb()) {
        Node *t;
        if (n->getLeft()->getProb() < n->getRight()->getProb()) {
          t = rotateRight(n->getLeft(), n);
          t->setRight(aux(n));
          return t;
        } else {
          t = rotateLeft(n, n->getRight());
          t->setLeft(aux(n));
          return t;
        }
      } else {
        return n;
      }
    }
    if (n->hasRight()) {
    }
    if (n->hasLeft()) {
    }
    return n;
  }

public:
  void preOrder() { preOrder(root); }

private:
  void preOrder(Node *n) {
    if (n == nullptr) {
      return;
    } else {
      cout << n->getKey() << "," << n->getProb() << endl;
      preOrder(n->getLeft());

      preOrder(n->getRight());
    }
  }

public:
  void remove(T e) { root = remove(root, e); }

private:
  Node *remove(Node *n, T e) {
    if (n == nullptr)
      return nullptr;
    else {
      if (n->getKey() == e) {
        if (!n->hasLeft() && !n->hasRight()) {
          // n is a leaf.
          delete n;
          sz--;
          return nullptr;
        } else if (!n->hasRight()) {
          // n has only left child
          Node *p = n->getLeft();
          delete n;
          sz--;
          return p;
        } else if (!n->hasLeft()) {
          // n has only right child
          Node *p = n->getRight();
          delete n;
          sz--;
          return p;
        } else {
          // n has both children
          Node *m = findMin(n->getRight());
          // Swap m->getData() with n->getData()
          T t = m->getKey();
          double p = m->getProb();
          m->setKey(n->getKey());
          n->setKey(t);
          n->setProb(p);
          // Remove e from the right subtree
          n->setRight(remove(n->getRight(), e));
          return aux(n);
        }
      } else if (e < n->getKey()) {
        n->setLeft(remove(n->getLeft(), e));
        return n;
      } else {
        // e > n->getData()
        n->setRight(remove(n->getRight(), e));
        return n;
      }
    }
  }
};
