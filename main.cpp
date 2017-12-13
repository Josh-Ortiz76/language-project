#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include "language.h"

int main(int argc, char* argv[]){
  //Creates language object for the test file language
  language lang = language(argv[argc - 1]);
  //Finds the frequencies of the trigrams of the test file language
  std::vector<int> vtest = lang.trigramHash();

  //Closest language to the test language
  std::string closest;
  //Largest cosine similarity value
  double largest = 0;

  //loops through the given training data trigram and uses the cosine similarity formula
  //to identify which language is more similar to identify the given file as.
  //The language is identified based on having the largest cosine similarity value
  for (int j = 1; j < argc - 1; j++){
    language train = language(argv[j]);
    std::vector<int> num = train.trigramHash();
    double temp = train.similarity(num, vtest);
    std::cout << temp << std::endl;
    if (temp > largest){
      largest = temp;
      closest = argv[j];
    }
  }
  std::cout << closest << std::endl;
}
