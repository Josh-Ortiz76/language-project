#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "language.h"

//Initializes the trigram variable.
language::language(){
  std::string text = "";
  std::vector<std::string> tri;
  std::vector<int> freq;
}

std::string language::trigram(std::string text){
  for (int i = 0; i < (int)text.length(); i++){
    tri += text.substr(i, 3);
  }
  return tri;
}

int language::frequency(text, tri){
  int count = 0;
  for (int j = 0; (int)tri.length(); j++){
    for (int i = 0; (int)text.length(); i++){
      if (tri[j] == text.substr(i, 3)){
        count += 1;
      }
      freq += count;
      count = 0;
    }
  }
  return tri, freq;
}
