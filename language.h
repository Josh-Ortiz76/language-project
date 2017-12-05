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


private:

  std::string text;
  std::string alpha = " abcdefghijklmnopqrstuvwxyz";

};
#endif
