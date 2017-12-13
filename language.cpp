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
//reads through each line of the text file and exits if given an invalid file name
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

//Returns the occurences of the trigrams found in the text. Looks at and compares
//the hash values within the vectors to determine frequency count of the trigrams in the text.
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
      //Makes sure the trigram does not go out of range of the text, so it does not grab invalids trigrams
      if (i < (int)text.length() - 1 && i < (int)text.length() - 2){
        trigram = text.substr(i, 3);
        hash1 = alpha.find(trigram[0]);
        hash2 = alpha.find(trigram[1]);
        hash3 = alpha.find(trigram[2]);
        triHash =  (hash1 * pow(27, 2)) + (hash2 * 27) + (hash3);
        hash.push_back(triHash);
        freq.at(triHash) += 1;
      }
    }
  }
  return freq;
}

//function that implements cosine similarity in order for us to check how related
//the trigram occurences are to a given language. We used the "unsigned long long" declaration to
//deal with very large values that would normally take very long with other declarations such as
//"int". The formula is split into 3 for loops for clarity
double language::similarity(std::vector<int> A, std::vector<int> B){
  unsigned long long numSum = 0;
  unsigned long long sumA = 0;
  unsigned long long sumB = 0;
  double cosSim = 0;
  //Calculates the summation of the product of two vectors
  for (int i = 0; i < (int)A.size() - 1 && (int)B.size() - 1; i++){
    numSum += A[i] * B[i];
  }
  //Calculates the square root of the summation of the first vector squared
  for (int j = 0; j < (int)A.size() - 1; j++){
    sumA += pow(A[j], 2);
  }
  //Calculates the square root of the summation of the second vector squared
  for (int k = 0; k < (int)B.size() - 1; k++){
    sumB += pow(B[k], 2);
  }
  //Final calculation of the summations to find the cosine similarity value
  cosSim = numSum/(sqrt(sumA) * sqrt(sumB));
  return cosSim;
}
