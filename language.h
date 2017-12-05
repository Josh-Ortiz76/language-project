#ifndef _language_h
#define _language_h

#include <iostream>
#include <string>
#include <vector>


class language{

public:

  /*
	Default constructor
	*/

  language();

  language(std::string str);

  std::vector<int> trigramHash();

  /*
  Counts the frequency of a the trigram in the trigrams and returns the number.
  */


private:

  std::string text;
  std::string alpha = " abcdefghijklmnopqrstuvwxyz";

};
#endif
