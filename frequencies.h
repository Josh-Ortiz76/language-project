#ifndef _frq_h
#define _frq_h

#include <iostream>
#include <string>
#include <vector>

/*
A class to represent DNA sequences, related to the FASTA format.
A DNA object has two member fields: a header, which is a sequence of characters beginning with the `>` character,
and a sequence, which is a sequence of characters containing only A, C, T, G, and N.
*/

class FRQ{

public:

  /*
	Default constructor
	*/

  FRQ();

  /*
  Constructor with separate arguments for header and sequence
  If `sequence` contains invalid characters, throws a std::runtime_error
  */

  FRQ(std::string header, std::string sequence);















}
