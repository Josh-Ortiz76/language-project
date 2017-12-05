#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "language.h"

//Initializes the trigram variable.
language::language(){
  std::string text = "";
}

std::string language::trigramHash(std::string text){
  std::vector<int> hash;
  std::string trigram = "";
  int hash1 = 0;
  int hash2 = 0;
  int hash3 = 0;
  int triHash = 0;
  for (z = 0; z < 3; z++){
    for (int i = z; i < (int)text.length(); i += 3){
      trigram = text.substr(i, 3));
      hash1 = alpha.at(trigram[0]);
      hash2 = alpha.at(trigram[1]);
      hash3 = alpha.at(trigram[2]);
      triHash =  (hash1 * pow(27, 2)) + (hash2 * 27) + (hash3);
      hash.push_back(triHash);
    }
    std::vector<int> freq;
    freq.resize(19683);
    int count = 0;
    for (int i = 0; i < (int)hash.size(); i++){
      for (int j = 0; j < (int)hash.size(); j++){
        if (hash[i] == hash[j]){
          count += 1;
        }
      }
      freq.at(hash[i]) = count;
      count = 0;
    }
  }
  return freq
}
