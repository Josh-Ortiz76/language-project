#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>
#include "language.h"

//Initializes the text variable.
language::language(){
  std::string text = "";
}

//Initializes the text variable as the string.
language::language(std::string str){
  std::ifstream infile(str);
  if(!infile.fail()){
    std::string line;
    while(getline(infile, line)){
      text += line;
    }
    infile.close();
  }else{
    exit(EXIT_FAILURE);
}
}

//Returns the occurences of the trigrams found in the text
std::vector<int> language::trigramHash(){
  std::vector<int> hash;
  std::string trigram = "";
  std::vector<int> freq;
  freq.resize(19683);
  int hash1 = 0;
  int hash2 = 0;
  int hash3 = 0;
  int triHash = 0;
  //Uses the base 27 to find the hash number of the trigram to compare for other hashs of the same
  for (int z = 0; z < 3; z++){
    for (int i = z; i < (int)text.length(); i += 3){
      //Makes sure the trigram does not go out of range of the text
      if (i < (int)text.length() - 1 && i < (int)text.length() - 2){
        trigram = text.substr(i, 3);
        hash1 = alpha.find(trigram[0]);
        hash2 = alpha.find(trigram[1]);
        hash3 = alpha.find(trigram[2]);
        triHash =  (hash1 * pow(27, 2)) + (hash2 * 27) + (hash3);
        hash.push_back(triHash);
        freq.at(triHash) += 1;
        //std::cout << trigram << " " << freq.at(triHash) << std::endl;
      }
    }
  }
  return freq;
}

double language::similarity(std::vector<int> A, std::vector<int> B){
  unsigned long long numSum = 0;
  unsigned long long sumA = 0;
  unsigned long long sumB = 0;
  double cosSim = 0;
  for (int i = 0; i < (int)A.size() - 1 && (int)B.size() - 1; i++){
    numSum += A[i] * B[i];
  }
  for (int j = 0; j < (int)A.size() - 1; j++){
    sumA += pow(A[j], 2);
  }
  for (int k = 0; k < (int)B.size() - 1; k++){
    sumB += pow(B[k], 2);
  }
  cosSim = numSum/(sqrt(sumA) * sqrt(sumB));
  return cosSim;
}
