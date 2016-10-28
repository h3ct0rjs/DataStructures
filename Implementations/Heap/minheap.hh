#ifndef __MIN_HEAP_HH__
#define __MIN_HEAP_HH__
/**
 * Min-heap data structure implementation.
 *
 * (From wikipedia http://en.wikipedia.org/wiki/Binary_heap)
 *
 * A binary heap is a data structure created using a binary tree that has two
 * additional properties:
 *
 * 1) Is a complete binary tree. That is, all the levels of the tree, except
 *    possibly the deepest one, are fully filled. If the last level is not
 *    complete, the nodes at that level are filled from left to right.
 *
 * 2) All the nodes are less than or equal to each of its children according to
 *    a comparison predicate.
 *
 * The second property defines a min-heap. In a max-heap this property is
 * changed to all the nodes being greater than or equal to each of its children.
 *
 * Visualization software:
 * https://www.cs.usfca.edu/~galles/visualization/Heap.html
 */

#include <cassert>
#include <vector>
#include <iostream>
using namespace std;
using std::vector;

template <typename T>
class MinHeap {
private:
  vector<T> storage_; // Internal storage for the heap's elements

public:
  /**
   * Constructor for an empty min-heap.
   *
   * Complexity: O(1)
   */
  MinHeap(void)
      : storage_() {}

  /**
   * Constructor for an empty min-heap of initial capacity @a capacity.
   *
   * Complexity: O(1)
   */
  MinHeap(size_t capacity)
      : storage_() {
    storage_.reserve(capacity);
  }

  /**
   * Returns the number of elements stored by the heap.
   *
   * Complexity: O(1)
   */
  size_t size(void) const { return storage_.size(); }

  /**
   * Tests whether the heap is empty.
   *
   * Complexity: O(1)
   */
  bool empty() const { return storage_.empty(); }

  /**
   * Inserts @a elem in the heap.
   *
   * Complexity: O(log n)
   */
  void insert(T elem) {
    storage_.push_back(elem);
    heapifyUp(storage_.size() - 1);
  }

  /**
   * Returns the minimum element.
   *
   * Complexity: O(1)
   */
  T min(void) const {
    assert(!empty());
    return storage_.front();
  }

  /**
   * Prints the heap elements.
   *
   * Complexity: O(n)
   */
  void print(void) const {
    for (const auto& i : storage_) std::cout << " " << i;
    std::cout << std::endl;
   }
/*
O(log_2 n)
*/
   void pop(){
     swap(0,storage_.size()-1);
     storage_.pop_back();
     heapifyDown(0);
  }
private:
	/* Function heapifyDown 
	Restores the heap property for every node in the path from storage_[i] down
   * to the path to leafs of the tree.
   O(log_2 n)
	*/
   void heapifyDown(size_t i) {
    if(hasLeft(i)&&hasRight(i)){
      size_t n;
      size_t nl=left(i);
      size_t nr=right(i);
      if(storage_[nl]<storage_[nr])
        n=nl;
      if(storage_[nl]>=storage_[nr])
        n=nr;
      if(storage_[i]>storage_[n]){
        swap(i,n);
        heapifyDown(n);
      }
    }
    if(hasLeft(i)&&!hasRight(i)){
      size_t l=left(i);
      if(storage_[i]>storage_[l]){
        swap(i,l);
        heapifyDown(l);
      }
    }
    if(!hasLeft(i)&&hasRight(i)){
      size_t r=right(i);
      if(storage_[i]>storage_[r]){
        swap(i,r);
        heapifyDown(r);
      }
    }
 }

  /**
   * Swaps elements storage_[i] and storage_[j]
   *
   * Complexity: O(1)

   
   */
  void swap(size_t i, size_t j) {
    T temp = storage_[i];
    storage_[i] = storage_[j];
    storage_[j] = temp;
  }

  /**
   * Tests whether element at position @a i is the root of the tree.
   *
   * Complexity: O(1)
   */
  bool isRoot(size_t i) const { return i == 0; }

  /**
   * Tests whether element at position @a i has a parent.
   *
   * Complexity: O(1)
   */
  bool hasParent(size_t i) const { return !isRoot(i); }

  /**
   * Returns the position of the parent of element at position @a i.
   *
   * Complexity: O(1)
   */
  size_t parent(size_t i) const {
    assert(hasParent(i));
    return (i - 1) / 2;
  }

  /**
   * Restores the heap property for every node in the path from storage_[i] up
   * to the root of the tree.
   *
   * Complexity: O(log_2 n)
   */
  void heapifyUp(size_t i) {
    if (isRoot(i)) return;

    size_t p = parent(i);
    if (storage_[p] > storage_[i]) {
      swap(i, p);
      heapifyUp(p);
    }
  }

  /**
   * Returns the position of the left child for node at position @a i
   *
   * Complexity: O(1)
   */
  size_t left(size_t i) const { return 2 * i + 1; }

  /**
   * Returns the position of the right child for node at position @a i
   *
   * Complexity: O(1)
   */
  size_t right(size_t i) const { return 2 * i + 2; }

  /**
   * Tests whether node at position @a i has a left child.
   *
   * Complexity: O(1)
   */
  bool hasLeft(size_t i) const { return left(i) < storage_.size(); }

  /**
   * Tests whether node at position @a i has a right child.
   *
   * Complexity: O(1)
   */
  bool hasRight(size_t i) const { return right(i) < storage_.size(); }

  /**
   * Tests whether node at position @a i is a leaf.
   *
   * Complexity: O(1)
   */
  bool isLeaf(size_t i) const { return !hasLeft(i) && !hasRight(i); }

  /**
   * Returns the position of the left child of node at position @a i.
   *
   * Complexity: O(1)
   */
  size_t getLeft(size_t i) const {
    assert(hasLeft(i));
    return left(i);
  }

  /**
   * Returns the position of the right child of node at position @a i.
   *
   * Complexity: O(1)
   */
  size_t getRight(size_t i) const {
    assert(hasRight(i));
    return right(i);
  }

};

#endif