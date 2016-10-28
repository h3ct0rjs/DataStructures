#ifndef __BST_HH__
#define __BST_HH__

#include <cassert>
#include <iostream>
#include <stack>
#include <utility>

template <typename T> class BST {
private:
  class Node {
  private:
    T data;
    Node *left;
    Node *right;

  public:
    Node(T elem) : data(elem), left(nullptr), right(nullptr) {}
    T &getData() { return data; }
    const T &getData() const { return data; }
    void setData(T elem) { data = elem; }
    Node *getLeft() { return left; }
    void setLeft(Node *nl) { left = nl; }
    bool hasLeft() const { return left != nullptr; }
    Node *getRight() { return right; }
    void setRight(Node *nr) { right = nr; }
    bool hasRight() const { return right != nullptr; }
  };
  // Attributes
  Node *root;
  int sz;

public:
  BST() : root(nullptr), sz(0) {}
  bool empty() const { return root == nullptr; }
  int size() const { return sz; }

  void insert(T elem) {
    if (empty()) {
      Node *n = new Node(elem);
      root = n;
      sz++;
    } else {
      insert(root, elem);
    }
  }

private:
  void insert(Node *n, T elem) {
    if (n->getData() == elem)
      return;
    if (elem < n->getData())
      if (n->hasLeft()) {
        insert(n->getLeft(), elem);
      } else {
        Node *k = new Node(elem);
        n->setLeft(k);
        sz++;
      }
    else if (n->hasRight()) {
      insert(n->getRight(), elem);
    } else {
      Node *k = new Node(elem);
      n->setRight(k);
      sz++;
    }
  }

public:
  void inorder() {
    // inorder(root);

    std::stack<Node *> s;

    Node *aux = root;

    while (!s.empty() || aux != nullptr) {
      if (!s.empty() && aux == nullptr) {

        std::cout << s.top()->getData() << std::endl;
      }
      if (aux != nullptr) {

        s.push(aux);

        aux = aux->getLeft();
      } else if (!s.empty()) {

        aux = s.top();

        s.pop();

        aux = aux->getRight();
      }
    }
  }
/*
public:
  void inorder() {
    Node *n = root;
    inorder(root);
  }

private:
  void inorder(Node *n) {
    if (n == nullptr)
      return;
    else {
      inorder(n->getLeft());
      std::cout << n->getData() << std::endl;
      inorder(n->getRight());
    }
  }
*/
public:
  int height() { return height(root); }

private:
  int height(Node *n) {
    if (n == nullptr)
      return 0;
    else if (!n->hasLeft() && !n->hasRight())
      return 1;
    else {
      int hl = height(n->getLeft());
      int hr = height(n->getRight());
      return 1 + std::max(hl, hr);
    }
  }

public:
  T min() {
    assert(!empty());
    Node *m = findMin(root);
    return m->getData();
  }

private:
  Node *findMin(Node *n) {
    assert(n != nullptr);
    if (!n->hasLeft())
      return n;
    else {
      return findMin(n->getLeft());
    }
  }

public:
  void remove(T e) { root = remove(root, e); }

private:
  Node *remove(Node *n, T e) {
    if (n == nullptr)
      return nullptr;
    else {
      if (n->getData() == e) {
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
          T t = m->getData();
          m->setData(n->getData());
          n->setData(t);
          // Remove e from the right subtree
          n->setRight(remove(n->getRight(), e));
          return n;
        }
      } else if (e < n->getData()) {
        n->setLeft(remove(n->getLeft(), e));
        return n;
      } else {
        // e > n->getData()
        n->setRight(remove(n->getRight(), e));
        return n;
      }
    }
  }

public:
  /**
   * Outputs a textual representation of the BST.
   *
   * To visualize it, visit:
   * http://www.webgraphviz.com/
   * Visit http://sandbox.kidstrythisathome.com/erdos/
   */
  void print() const {
    using std::cout;
    using std::endl;

    cout << "digraph BST {" << endl;
    if (empty())
      cout << endl;
    else if (!root->hasLeft() && !root->hasRight())
      cout << root->getData() << endl;
    else {
      size_t nullnodes = 0;
      print(root, nullnodes);
    }
    cout << "};" << endl;
  }

private:
  static std::string removeSpaces(const std::string &data) {
    std::string s;
    for (char c : data)
      if (c != ' ')
        s.push_back(c);

    return s;
  }

  void print(Node *n, size_t &nullnodes) const {
    using std::cout;
    using std::endl;

    if (n->hasLeft()) {
      cout << removeSpaces(n->getData()) << " -> "
           << removeSpaces(n->getLeft()->getData()) << ";" << endl;
      print(n->getLeft(), nullnodes);
    } else
      printNullNode(removeSpaces(n->getData()), nullnodes++);

    if (n->hasRight()) {
      cout << removeSpaces(n->getData()) << " -> "
           << removeSpaces(n->getRight()->getData()) << ";" << endl;
      print(n->getRight(), nullnodes);
    } else
      printNullNode(removeSpaces(n->getData()), nullnodes++);
  }

  void printNullNode(T data, size_t nullnodes) const {
    using std::cout;
    using std::endl;

    cout << "null" << nullnodes << " [shape=point];" << endl;
    cout << data << " -> null" << nullnodes << ";" << endl;
  }
};

#endif
