#ifndef __BST_HH__
#define __BST_HH__

#include <iostream>

template <typename T>
class BST {
private:
  class Node {
  private:
    T data;
    Node* left;
    Node* right;

  public:
    Node(T elem)
        : data(elem)
        , left(nullptr)
        , right(nullptr) {}
    T& getData() { return data; }
    const T& getData() const { return data; }
    Node* getLeft() { return left; }
    void setLeft(Node* nl) { left = nl; }
    bool hasLeft() const { return left != nullptr; }
    Node* getRight() { return right; }
    void setRight(Node* nr) { right = nr; }
    bool hasRight() const { return right != nullptr; }
  };
  // Attributes
  Node* root;
  size_t size;

public:
  BST()
      : root(nullptr)
      , size(0) {}
  bool empty() const { return root == nullptr; }
  void insert(T elem) {
    if (empty()) {
      Node* n = new Node(elem);
      root = n;
      size++;
    } else {
      insert(root, elem);
    }
  }

private:
  void insert(Node* n, T elem) {
    if (n->getData() == elem) return;
    if (elem < n->getData())
      if (n->hasLeft()) {
        insert(n->getLeft(), elem);
      } else {
        Node* k = new Node(elem);
        n->setLeft(k);
        size++;
      }
    else if (n->hasRight()) {
      insert(n->getRight(), elem);
    } else {
      Node* k = new Node(elem);
      n->setRight(k);
      size++;
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
  static std::string removeSpaces(const std::string& data) {
    std::string s;
    for (char c : data)
      if (c != ' ') s.push_back(c);

    return s;
  }

  void print(Node* n, size_t& nullnodes) const {
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
