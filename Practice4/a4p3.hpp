#define A4P3_HPP

#include <algorithm>

template <typename T> struct snode{
  snode(const T& val, snode* ptr = nullptr) : value(val), next(ptr) {}
  T value;
  snode* next;
};// struct snode

  template <typename T>
  snode<T>* insert_after_after(snode<T>* p, const T& t){
    snode<T> addthis;
    addthis->value = t;
    if(p == nullptr){
      p = addthis;
      addthis->next = nullptr;
    }
    else{
      snode<T> nextp = p;//the actual node being inserted after
      addthis->next = nextp->next;
      nextp->next = addthis;
    }
    return addthis->next;
  };
