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

  /*
  Constructor to take an arguement and turn it into trigrams. Returns the possible trigrams.
  */

  std::string trigramHash(std::string text);


  /*
  Counts the frequency of a the trigram in the trigrams and returns the number.
  */

  int frequency(std::string hash);

  std::vector<int> alpha = ["", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "z"]

}
