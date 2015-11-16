#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <list>

template <typename T>
class Queue {
  public:
    // the constructor initializes the list 
    // and sets the size counter to zero
    Queue() :
      list_{new std::list<T>()},
      size_{0}
    {}
    // the destructor deletes the list
    ~Queue() {
      delete list_;
    }
    // push gets an object and adds it
    // to the beginning of the list, the
    // size increases by one
    void push(T const& object) {
      list_->push_front(object);
      size_++;
    }
    // pop gets the first added element 
    // from the list. If the size is bigger
    // than zero, the object is deleted
    // from the list and size decreases
    T& pop() {
      T& object = list_->back();
      if(size_>0) {
        list_->pop_back();
        size_--;
      }
      return object;
    }
    // size returns the number of
    // currently stored objects
    int size() const {
      return size_;
    }
  private:
    std::list<T>* list_;
    int size_;
};

#endif //QUEUE_HPP