#ifndef _language_h
#define _language_h

#include <iostream>
#include <string>
#include <vector>

/*
A class to represent DNA sequences, related to the FASTA format.
A DNA object has two member fields: a header, which is a sequence of characters beginning with the `>` character,
and a sequence, which is a sequence of characters containing only A, C, T, G, and N.
*/

class language{

public:

  /*
	Default constructor
	*/

  language();

  /*
  Constructor with separate arguments for header and sequence
  If `sequence` contains invalid characters, throws a std::runtime_error
  */

  language(std::string header, std::string sequence);















}
