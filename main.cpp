#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include "language.h"

int main(int argc, char *argv[]){
  if (argc < 2){
    exit(EXIT_FAILURE);
  }
  //language lang = language(argv[1]);
  //std::vector<int> num = lang.trigramHash();
  std::vector<double> num;
  std::vector<double> vtest;
  //Prints out the frequencies of the trigrams
  for (int i = 0; i < (int)num.size(); i++){
    std::cout << num[i];
    std::cout << " ";
  }
  std::cout << std::endl;

  std::string closest = "";
  double largest = 0;
  language test = language(argv[argc - 1]);
  vtest = test.trigramHash();
  double temp = 0;

  for (int j = 1; j < argc - 1; j++){
    language train = language(argv[j]);
    num = train.trigramHash();
    temp = train.similarity(num, vtest);
    if (temp > largest){
      largest = temp;
      closest = argv[j];
    }
  }
  std::cout << closest;
}
