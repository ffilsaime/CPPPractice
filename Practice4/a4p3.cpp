#include <iostream>
#include "a4p3.hpp"

template <typename T> struct snode{
  snode(const T& val, snode* ptr = nullptr) : value(val), next(ptr) {}
  T value;
  snode* next;
};

int main(int argc, char* argv[]){
  snode<std::string> first;
  first->value = "ab";
  insert_after_after(first->next, "b");

  std::cout << "Test 1" << std::endl;
  std::string littleb = "bc";
  std::string& refb = &littleb;
  snode<std::string> second = first->next;
  if(second->value != refb){
    std::cout << "failed to see if the second node was added" << std::endl;
    return 0;
  }

  insert_after_after(first->next, "c");
  std::cout << "Test 2" << std::endl;
  std::string littlec = "cd";
  std::string& refc = &littlec;
  snode<std::string> third = second->next;
  if(third->value != refc){
    std::cout << "failed to see if the third node was added" << std::endl;
    return 0;
  }

  std::cout << "pass" << std::endl;
  return 0;
}
