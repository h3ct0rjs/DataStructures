#ifndef __LIST_HH__
#define __LIST_HH__

#include <cassert>
#include <iostream>

template <typename T> class List {
private:
  class Node {
  private:
    T data;
    Node *next;

  public:
    Node(const T &d) : data(d), next(nullptr) {}
    Node *getNext() { return next; }
    void setNext(Node *n) { next = n; }
    T getData() { return data; }
    void setData(const T &d) { data = d; }
  };

  // Attributes
  int sz;
  Node *first;
  Node *last;

public:
  /*
   * Creates an empty list.
   * complexity: O(1)
   */
  List() : sz(0), first(nullptr), last(nullptr) {}
  /*
   * Rturns the number of elements in the list.
   * complexity: O(1)
   */
  int size() const { return sz; }
  /*
   * Returns whether the list is empty.
   * complexity: O(1)
   */
  bool empty() const { return sz == 0; }
  /*
   * Adds the element x at position i.
   * complexity: O(i)
   */
  void add(int i, const T &x) {
    assert(i >= 0 && i <= size());
    Node *n = new Node(x);
    if (i == 0) {
      // Adding at the beginning
      n->setNext(first);
      first = n;
      if (empty()) {
        last = n;
      }
    } else if (i == sz) {
      // Adding at the end
      last->setNext(n);
      last = n;
    } else {
      // Adding at _any_ position.
      Node *prev = moveOneBefore(i);
      n->setNext(prev->getNext());
      prev->setNext(n);
    }
    sz++;
  }
  /*
   * Appends x to the end of the list.
   * complexity: O(1)
   */
  void append(const T &x) { add(size(), x); }
  /*
   * Prepends x at the beginning of the list.
   * complexity: O(1)
   */
  void prepend(const T &x) { add(0, x); }
  /*
   * Returns the element at position p.
   * complexity: O(i)
   */
  T get(int i) {
    assert(i >= 0 && i < sz);
    Node *n = moveTo(i);
    return n->getData();
  }
  /*
   * Assigns position i to x.
   * complexity: O(i)
   */
  void set(int i, const T &x) {
    assert(i >= 0 && i < sz);
    Node *n = moveTo(i);
    n->setData(x);
  }
  /*
   * Prints the elements of the list.
   * complexity: O(size^2)
   */
  void print() {
    for (int i = 0; i < sz; i++) {
      std::cout << " " << get(i);
    }
    std::cout << std::endl;
  }

private:
  Node *moveTo(int p) {
    assert(p >= 0 && p < sz);
    Node *e = first;
    for (int i = 1; i <= p; i++) {
      e = e->getNext();
    }
    return e;
  }
  Node *moveOneBefore(int p) {
    assert(p > 0 && p <= sz);
    return moveTo(p - 1);
  }
};
#endif
