//File: a1.cpp
//Florebencia
//Fils-Aime
//I AFFIRM THAT WHEN WORKING ON THIS ASSIGNMENT
//I WILL FOLLOW UB STUDENT CODE OF CONDUCT, AND
//I WILL NOT VIOLATE ACADEMIC INTEGRITY RULES

#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>
#include<vector>

/*
This counts the amount of each letter and puts it into an array
*/
void counting(int *count, int l, std::string word){
  for(int i = 0; i< l; i++){
    count[i] = 0; // zero-ing out the contents in count to ensure no nulls
  }
  //counting the amount of As in the string
  // size_t asize = std::count(word.begin(), word.end(), 'A');
  // count[0]= asize;
  // //counting the amount of Cs in the string
  // size_t csize = std::count(word.begin(), word.end(), 'C');
  // count[1]= csize;
  // //counting the amount of Gs in the string
  // size_t gsize = std::count(word.begin(), word.end(), 'G');
  // count[2]= gsize;
  // size_t tsize = std::count(word.begin(), word.end(), 'T');
  // count[3]= tsize;
  // size_t nsize = std::count(word.begin(), word.end(), 'N');
  // count[4]= nsize;
  while()
  for (int j = 0; j < l; j++){
    std::cout << count[j] << " ";
  }
  std::cout << "" << std::endl;
}

/*This counts the amount of substrings in a given string
*/
int countstring(std::string word, std::string substring, size_t k){
  int count = 0;
  size_t nPos = word.find(substring, 0);
  while(nPos != std::string::npos){
    count += 1;
    nPos = word.find(substring, nPos+k);
  }
  return count;
}

void kmercount(std::string word, size_t k, std::string *kmer, int *amount){
  for(size_t a = 0; a < word.length()-k+1; a++){
    kmer[a]= "F";
    amount[a]=0;
  }
  for(size_t i=0; i< (word.length()-k+1); i++){
      kmer[i] = word.substr(i,k);
      amount[i] = countstring(word, kmer[i], k);
  }

  if(kmer[0].find('N') == std::string::npos){
    std::cout << kmer[0] << " " << amount[0] << std::endl;
  }

  for(size_t j = 0; j < (word.length()-k+1); j++){
    bool dulpicate = false;
    for(size_t x = 1; (x>j&&x<word.length()-k+1) && (dulpicate==false); x++){
      if(kmer[j]==kmer[x]){
        dulpicate = true;
      }
      if(!dulpicate){
        if(kmer[x].find('N') == std::string::npos){
        std::cout << kmer[x] << " " << amount[x] << std::endl;
      }
    }
  }
}
}

/*
This takes the file mentioned, reads its lines and turns them into a string called
dna. It prints out the k value and the size of the string.
*/
int main(int argc, char** argv){
  // size_t k = *argv[2]; // Lines 83- 84 this is converting a char into an int
  // k -= 48;
  std::string dna;
  std::ifstream thefile (argv[1]);
  size_t k = std::atoi(dna);
  if (thefile.is_open()) {
    std::getline(thefile,dna);
    std::string x;
    while (std::getline(thefile, x)){
      dna.append(x);
    }
  }
  else {
    std::cout << "Unable to open file";
  }
  int *counter = new int[5];
  std::string *kmerstring = new std::string[dna.length()-k+1];
  int *kmeramount = new int[dna.length()-k+1];

  std::cout << 0 << " " << argv[2] << " " << dna.length() << std::endl;
  std::cout << 1 << " ";
  counting(counter, 5, dna);
  delete[] counter;

  if(k>dna.length()){
    std::cout << "error" << std::endl;
  }
   else {
    kmercount(dna, k, kmerstring, kmeramount);
    delete[] kmerstring;
    delete[] kmeramount;
  }

  return 0;
}
