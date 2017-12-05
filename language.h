#ifndef _language_h
#define _language_h

#include <iostream>
#include <string>
#include <vector>


class language{

public:

  //Default Constructor
  language();

  //Constructor to grab the text. Does not return anything.
  language(std::string str);

  //Function that grabs the trigrams from the text and finds the hash of the trigrams to find the frequency of the hash.
  //Returns the vector of occurences
  std::vector<int> trigramHash();

private:
  //Text variable for the inputted text
  std::string text;
  //String for the alphabet including the space
  std::string alpha = " abcdefghijklmnopqrstuvwxyz";

};
#endif
