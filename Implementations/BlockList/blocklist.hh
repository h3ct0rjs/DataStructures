#include <cassert>
#include <iostream>
using namespace std;

template <typename T> class Blocklist {
private:
  int sz;
  Node *first;
  Node *last;

  class Node {
  private:
    T *storage;
    int sz;
    int capacity;
    Node *next;

  public:
    Node() : sz(0), capacity(6), next(nullptr) { storage = new T[capacity]; }
    Node(const T &x) : sz(1), next(nullptr), capacity(6) { storage[0] = x; }
    Node *getNext() { return next; }

    void setNext(Node &m) { next = m; }

    T getData(int i) { return storage[i]; }

    void setData(int i, const T &x) { storage[i] = x; }
    void add(int i, const T &x) {
      assert(i >= 0 && i < sz);
      storage[i] = x;
      sz++;
    }

    void moveOneRight(int i) {
      assert(i >= 0 && i < sz);
      for (int j = sz; j > i; j--)
        if (j == capacity && next != nullptr) {
          next->moveOneRight(0);
          next->add(0, storage[j]);
        }
      if (j == capacity && next == nullptr) {
        Node() n;
        next = n;
        next->add(0, storage[j]);
      }

      storage[j] = storage[j - 1];
    }
  };

public:
  Blocklist() : sz(0), first(nullptr), last(nullptr) {}

  void add(int i, const T &x) {
    assert(i >= 0 && i <= sz);
    Node *n = new Node(x);
    Node *m = new Node();
    m->setNext(last);
    if (i < 6) {
      n->setNext(first);
      n->moveOneRight(i);
      n->add(i, x);
      if (sz < 6) {
        last = n;
        first = n;
      } else {
        last = getNext(last);
      }
    }
  }
};
