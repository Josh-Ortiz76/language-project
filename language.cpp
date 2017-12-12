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
      trigram = text.substr(i, 3);
      //Makes sure the trigram does not go out of range of the text
      if (i < (int)text.length() - 1 && i < (int)text.length() - 2){
        hash1 = alpha.find(trigram[0]);
        hash2 = alpha.find(trigram[1]);
        hash3 = alpha.find(trigram[2]);
        triHash =  (hash1 * pow(27, 2)) + (hash2 * 27) + (hash3);
        hash.push_back(triHash);
      }
    }
  }
  int count = 0;
  //Replaces the position of the trigram with the frequency number
  for (int i = 0; i < (int)hash.size(); i++){
    for (int j = 0; j < (int)hash.size(); j++){
      if (hash[i] == hash[j]){
        count += 1;
      }
    }
    freq[hash[i]] = count;
    count = 0;
  }
  return freq;
}

//
double language::similarity(std::vector<int> A, std::vector<int> B){
  double numSum = 0;
  double sumA = 0;
  double sumB = 0;
  for (int i = 0; i < (int)A.size() - 1; i++){
    numSum += A[i] * B[i];
    sumA += pow(A[i], 2);
    sumB += pow(B[i], 2);
    std::cout << i << std::endl;
  }
  return(numSum/(sqrt(sumA) * sqrt(sumB)));
}
