// File: a2.hpp
// Florebencia
// Fils-Aime
// I AFFIRM THAT WHEN WORKING ON THIS ASSIGNMENT
// I WILL FOLLOW UB STUDENT CODE OF CONDUCT, AND
// I WILL NOT VIOLATE ACADEMIC INTEGRITY RULES

#ifndef A2_HPP
#define A2_HPP

// IMPLEMENT MISSING FUNCTIONALITY OF sorted_sc_array IN THIS FILE
// YOU ARE NOT ALLOWED TO INCLUDE ANY OTHER HEADERS EXCEPT OF <algorithm>
// YOU CAN CHANGE/EDIT ANY CODE IN THIS FILE AS LONG AS SEMANTICS IS UNCHANGED
// AND MATCHES SPECIFICATION AS PROVIDED IN THE ASSIGNMENT TEXT

#include <algorithm>


class sorted_sc_array {
public:
    sorted_sc_array() : size_(0), ptr_(nullptr) { }

    ~sorted_sc_array() { delete[] ptr_; }

    // IMPLEMENT ME
    sorted_sc_array(const sorted_sc_array& A){
      size_= A.size_;
      if(size_==0){
        ptr_ = nullptr;
        length = 0;
      } else {
        ptr_ = new signed char[size_];
        std::copy(A.ptr_, A.ptr_ + size_, ptr_);
        length = size_;
      }
    }

    // IMPLEMENT ME
    sorted_sc_array& operator=(const sorted_sc_array& A){
      if(this == &A){
        return *this;
      }
      delete[] ptr_;
      size_= A.size_;
      if(size_==0){
        ptr_ = nullptr;
        length = 0;
      } else {
        ptr_ = new signed char[size_];
        std::copy(A.ptr_, A.ptr_ + size_, ptr_);
        length = size_;
        }
      return *this;
    }

    // RETURNS SIZE OF THE ARRAY (i.e. HOW MANY ELEMENTS IT STORES)
    int size() const { return size_; }

    // RETURNS RAW POINTER TO THE ACTUAL DATA, CAN BE INVOKED AT ANY TIME
    const signed char* data() const {
      std::sort(ptr_, ptr_+size_);
      return ptr_;
    }


    // IMPLEMENT ME: AFTER INSERT COMPLETES THE ARRAY MUST BE IN ASCENDING ORDER
    void insert(signed char c){
        if(size_==0){
          ptr_ = new signed char[2];
          ptr_[0] = c;
          size_ += 1;
          length = 2;
        } else  if (size_ < length){
        ptr_[size_] = c;
        size_ += 1;

      }
      else {
        signed char * temp = new signed char[2*size_];
        std::copy(ptr_, ptr_ + size_, temp);
        delete[] ptr_;
        ptr_ = temp;
        ptr_[size_] = c;
        length = size_ * 2;
        size_ += 1;
      }
    }


private:
    int size_;         // size of the array
    int length;
    signed char* ptr_; // pointer to the array

}; // class sorted_sc_array

#endif // A2_HPP
