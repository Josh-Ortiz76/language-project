#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include "language.h"

int main(int argc, char* argv[]){
  language lang = language(argv[argc - 1]);
  std::vector<int> vtest = lang.trigramHash();
  //Prints out the frequencies of the trigrams

  std::string closest;
  double largest = 0;

  //language test = language(argv[argc - 1]);
  //std::vector<int> vtest = test.trigramHash();

  /*for(int z = 0; z < (int)vtest.size(); z++){
    std::cout << vtest[z] << std::endl;
  }*/

  for (int j = 1; j < argc - 1; j++){
    language train = language(argv[j]);
    std::vector<int> num = train.trigramHash();
    double temp = train.similarity(num, vtest);
    if (temp > largest){
      largest = temp;
      closest = argv[j];
    }
  }
  std::cout << closest << std::endl;
}
