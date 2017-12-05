#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "language.h"

//Initializes the trigram variable.
language::language(){
  std::vector<std::string> tri;
}

std::string language::trigramHash(std::string text){
  std::vector<int> hash;
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
    hash.push_back(triHash);
  }
  return hash;
}

int language::frequency(text){
  std::vector<int> freq;
  int count = 0;
  for (int i = 0; i < (int)hash.size(); i++){
    for (int j = 0; j < (int)hash.size(); j++){
      if (hash[i] == hash[j]){
        count += 1;
      }
    }
    freq.push_back(count);
    count = 0;
  }
  return freq
}
