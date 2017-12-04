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

  std::string trigram(std::string text);

  /*
  Counts the frequency of a letter in the trigrams and returns the number.
  */

  int frequency(std::string tri, std::string letter);

  std::string text;
  std::vector<std::string> tri;
  std::vector<int> freq;

}
