// File: a3.hpp
// Florebencia
// Fils-Aime
// I AFFIRM THAT WHEN WORKING ON THIS ASSIGNMENT
// I WILL FOLLOW UB STUDENT CODE OF CONDUCT, AND
// I WILL NOT VIOLATE ACADEMIC INTEGRITY RULES

#ifndef A3_HPP
#define A3_HPP

// MAKE SURE TO UPDATE YOUR INFORMATION IN THE HEADER OF THIS FILE
// IMPLEMENT MISSING FUNCTIONALITY OF key_value_sequences IN THIS FILE
// YOU ARE NOT ALLOWED TO INCLUDE ANY OTHER HEADERS THAN
// <algorithm>, <list>, <vector>
// YOU CAN CHANGE/EDIT ANY CODE IN THIS FILE AS LONG AS SEMANTICS IS UNCHANGED
// AND MATCHES SPECIFICATION PROVIDED IN THE ASSIGNMENT TEXT

#include <algorithm>
#include <list>
#include <vector>


struct pair {
  int pkey;
  std::vector<int> values;
};

class key_value_sequences {
public:
    // YOU SHOULD USE C++ CONTAINERS TO AVOID RAW POINTERS
    // IF YOU DECIDE TO USE POINTERS, MAKE SURE THAT YOU MANAGE MEMORY PROPERLY
    // IMPLEMENT ME: SHOULD RETURN SIZE OF A SEQUENCE FOR GIVEN KEY
    // IF NO SEQUENCE EXISTS FOR A GIVEN KEY RETURN 0
    int size(int key){
      if (keys.size() == 0){
        return 0;
      }
      else {
        for(std::vector<pair>::iterator it = keys.begin(); it != keys.end(); ++it){
          if((*it).pkey == key){
            return (*it).values.size();
          }
        }
        return 0;
      }
    }

    // IMPLEMENT ME: SHOULD RETURN POINTER TO A SEQUENCE FOR GIVEN KEY
    // IF NO SEQUENCE EXISTS FOR A GIVEN KEY RETURN nullptr
    const int* data(int key){
      if(keys.size()==0){
        return nullptr;
      }
      else {
        for(std::vector<pair>::iterator it = keys.begin(); it != keys.end(); ++it){
          if((*it).pkey == key){
            return (*it).values.data();
          }
        }
      }
      return nullptr;
    }

    // IMPLEMENT ME: INSERT VALUE INTO A SEQUENCE IDENTIFIED BY GIVEN KEY
    void insert(int key, int value){
      if(keys.size()==0){
        pair newpair; // a structure with an integer and a vector
        newpair.pkey = key; // creates a new key
        newpair.values.push_back (value); //puts a value in the vector
        keys.push_back(newpair); //puts the pair into the doubly-linked list
      }
      else {
        for(std::vector<pair>::iterator it = keys.begin(); it != keys.end(); ++it){
          if((*it).pkey == key){
            (*it).values.push_back (value);
            return;
          }
        }
          pair np2; // a structure with an integer and a vector
          np2.pkey = key; // creates a new key
          np2.values.push_back (value); //puts a value in the vector
          keys.push_back(np2); //puts the pair into the doubly-linked list
      }
    }

private:
  std::vector<pair> keys;

}; // class key_value_sequences

#endif // A3_HPP
