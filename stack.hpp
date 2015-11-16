#ifndef STACK_HPP
#define STACK_HPP

#include <list>

template <typename T>
class Stack {
  public:
    // the constructor initializes the list 
    // and sets the size counter to zero
    Stack() :
      list_{new std::list<T>()},
      size_{0}
    {}
    // the destructor deletes the list
    ~Stack() {
      delete list_;
    }
    // push gets an object and adds it
    // to the end of the list, the
    // size increases by one
    void push(T const& object) {
      list_->push_back(object);
      size_++;
    }
    // pop gets the last added element 
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

#endif //STACK_HPP