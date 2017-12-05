#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "language.h"

int main(int argc, char *argv[]){
  if (argc != 2){
    exit(EXIT_FAILURE);
  }
  std::vector num = language::trigramHash(argv[1]);
  std::vector freq = language::frequency(num);

  for (i = 0; i < (int)num.size(); i++){
    std::cout << num[i] << freq[i];
  }
}
