#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "language.h"

//Initializes the trigram variable.
language::language(){
  std::string text = "";
  std::vector<std::string> tri;
  std::vector<int> freq;
}

std::string language::trigramHash(std::string text){
  std::string trigram = "";
  int hash1 = 0;
  int hash2 = 0;
  int hash3 = 0;
  int triHash = 0;
  for (int i = 0; i < (int)text.length() - 2; i++){
    trigram = text.substr(i, 3));
    trigrams.push_back(trigram);
    hash1 = alpha.at(trigram[0]);
    hash2 = alpha.at(trigram[1]);
    hash3 = alpha.at(trigram[2]);
    triHash =  (hash1 * 27^2) + (hash2 * 27^1) + (hash3 * 27^0);
    freq.push_back(triHash);
  }
  return freq;
}

int language::frequency(text){
  int count = 0;
  for (int i = 0; i < (int)freq.size(); i++){
    
  }
}

int language::frequency(text, tri){
  int count = 0;
  for (int j = 0; (int)tri.size(); j++){
    for (int i = 0; (int)text.length(); i++){
      if (tri[j] == text.substr(i, 3)){
        count += 1;
      }
      freq.push_back(count);
      count = 0;
    }
  }
  return tri, freq;
}
