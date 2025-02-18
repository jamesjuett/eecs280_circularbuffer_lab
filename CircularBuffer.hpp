#ifndef CIRCULARBUFFER_HPP
#define CIRCULARBUFFER_HPP

#include <iostream>
#include <cassert>

template <typename T>
class CircularBuffer {

public:

  // EFFECTS: Constructs an empty CircularBuffer.
  CircularBuffer()
    : head(0), tail(0), num_elts(0), capacity(CAPACITY) {

  }

  // REQUIRES: size < capacity
  // MODIFIES: *this
  // EFFECTS:  Adds a new value to the back of the buffer
  //           moves tail to the new position
  void push_back(const T &value) {
    assert(false); // TODO: Replace with your implementation
  }

  // REQUIRES: buffer is not empty
  // MODIFIES: *this
  // EFFECTS:  Removes the element at the front of the buffer
  //           moves head to the new position
  void pop_front() {
    assert(false); // TODO: Replace with your implementation
  }

  // REQUIRES: buffer is not empty
  // EFFECTS:  Returns the value at the front of the buffer
  T &front() {
    assert(false); // TODO: Replace with your implementation
  }

  // EFFECTS:  Returns the current size of the buffer
  int size() const {
    return num_elts;
  }

  // EFFECTS:  Returns true if this CircularBuffer is empty, false otherwise.
  bool empty() const {
    return num_elts == 0;
  }

  // REQUIRES: 0 <= index and index < number of elements in this CircularBuffer.
  // EFFECTS:  Returns (by reference) the element that is index positions from head.
  T & at(int index) {
    return data[(head + index) % capacity];
  }

  // REQUIRES: 0 <= index and index < number of elements in this CircularBuffer.
  // EFFECTS:  Returns (by const reference) the element that is index positions from head.
  const T & at(int index) const {
    return data[(head + index) % capacity];
  }

  // EFFECTS:  Prints the buffer to os.
  void print(std::ostream &os) const{
    os << "[ ";
    for (int i = 0; i < num_elts; ++i) {
        os << at(i);
        if (i < num_elts - 1) {
            os << ", ";
        }
    }
    os << " ]";
  }

private:

  // The maximum capacity of a CircularBuffer
  static const int CAPACITY = 1000;

  // The array to hold the N elements stored in this circular buffer in positions determined
  // by head and tail
  T data[CAPACITY];

  // head is the index marking the beginning of the data in the buffer
  // tail is the index where a new element would be added in the buffer
  // num_elts is the number of elements currently in the buffer
  int head;      // INVARIANT: 0 <= head < capacity
  int tail;      // INVARIANT: 0 <= tail < capacity
  int num_elts;  // INVARIANT: 0 <= num_elts <= capacity
  int capacity;

};

// EFFECTS:  overloaded operator that prints the buffer to os
template <typename T>
std::ostream& operator<<(std::ostream &os, const CircularBuffer<T> &rb) {
  rb.print(os);
  return os;
}

#endif // Do not remove this. Write all your code above this line.
