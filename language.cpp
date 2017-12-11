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
  text = str;
}

//Returns the occurences of the trigrams found in the text
std::vector<long long> language::trigramHash(){
  std::vector<long long> hash;
  std::string trigram = "";
  std::vector<long long> freq;
  freq.resize(19683);
  long long hash1 = 0;
  long long hash2 = 0;
  long long hash3 = 0;
  long long triHash = 0;
  //Uses the base 27 to find the hash number of the trigram to compare for other hashs of the same
  for (long long z = 0; z < 3; z++){
    for (long long i = z; i < (long long)text.length(); i += 3){
      trigram = text.substr(i, 3);
      //Makes sure the trigram does not go out of range of the text
      if (i < (long long)text.length() - 1 && i < (long long)text.length() - 2){
        hash1 = alpha.find(trigram[0]);
        hash2 = alpha.find(trigram[1]);
        hash3 = alpha.find(trigram[2]);
        triHash =  (hash1 * pow(27, 2)) + (hash2 * 27) + (hash3);
        hash.push_back(triHash);
      }
    }
  }
  long long count = 0;
  //Replaces the position of the trigram with the frequency number
  for (long long i = 0; i < (long long)hash.size(); i++){
    for (long long j = 0; j < (long long)hash.size(); j++){
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
double language::similarity(std::vector<double> A, std::vector<double> B){
  double numSum = 0;
  double sumA = 0;
  double sumB = 0;
  for (size_t i = 0; i < (double)A.size(); i++){
    numSum += A[i] * B[i];
    sumA += pow(A[i], 2);
  }
  for (size_t i = 0; i < (double)B.size(); i++){
    sumB += pow(B[i], 2);
  }
  double cosSim = numSum/(sqrt(sumA) * sqrt(sumB));
  return cosSim;
}
