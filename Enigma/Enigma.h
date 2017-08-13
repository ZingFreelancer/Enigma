#pragma once
#include <map>
#include <iostream>
#include <string>

class Enigma
{
public:
	//Empty/Default constructor 
	Enigma();
	Enigma(const char first, const char last);
	virtual ~Enigma();
private: //Variables
	std::map<char, int> m_Alphabet;
	int m_AlphabetLength;

private: //Functions
	void generateAlphabetMap(const char start, const char end);

public: //Functions
	std::string ToStringAlphabet() const;
};

