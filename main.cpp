#include "stack.hpp"  // including selfwritten stack
#include "queue.hpp"  // including selfwritten queue
#include <iostream>   // library for in- and outputs
#include <cstring>    // library including strlen()
 
int main(int argc, char** argv) {

  // if there is no or more than one input an usage message
  // is shown and the program terminates
  if(argc!=2) {
    std::cout << "  Usage: " << argv[0] 
      << " \"chars to check if palindrome\"" << std::endl;
    return 0;
  }

  // initializing the queue and stack
  Queue<char> firstPart;
  Stack<char> secondPart;

  // length is the character count of the input
  // and limit is the half (rounded off) of the length
  int length = std::strlen(argv[1]);
  int limit = length / 2;

  // the first half of characters is stored in the queue
  // and the second half is stored in the stack;
  // if the input is odd the character in the middle
  // goes unnoticed
  for(int i=0; i<limit; i++) {
    firstPart.push(argv[1][i]);
    secondPart.push(argv[1][i+limit+length%2]);
  }

  // each element of both the stack and the queue get
  // compared in the order their pop-methods send them
  // so that the last character will be compared to the 
  // first one and so on;
  // if a pair of characters is unequal, the program returns
  // a text saying that the input is not a palindrome and
  // terminates itself
  while(firstPart.size()>0) {
    if(firstPart.pop() != secondPart.pop()) {
      std::cout << "input is not a palindrome" << std::endl;
      return 0;
    }
  }

  // if every pair of characters was equal, the program
  // returns that the input is a palindrome
  std::cout << "input is a palindrome" << std::endl;
  return 0;
}
