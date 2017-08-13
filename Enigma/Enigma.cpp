#include "Enigma.h"
Enigma::Enigma() : m_AlphabetLength{ 0 }
{
	generateAlphabetMap('A', 'Z');
}

Enigma::Enigma(const char first, char last) : m_AlphabetLength{0}
{
	generateAlphabetMap(first, last);
}


Enigma::~Enigma()
{}

void Enigma::generateAlphabetMap(const char start, const char end)
{
	for (char c = start; c <= end; c++)
	{
		m_Alphabet.emplace(c, m_AlphabetLength);
		m_AlphabetLength++;
	}
}

std::string Enigma::ToStringAlphabet() const
{
	std::string out;
	for (auto itr = m_Alphabet.begin(); itr != m_Alphabet.end(); itr++)
		out += itr->first;
	return out;
}
