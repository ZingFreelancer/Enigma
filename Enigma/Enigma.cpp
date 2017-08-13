#include "Enigma.h"
Enigma::Enigma() : Enigma('A', 'Z', 1)
{}

Enigma::Enigma(const char first, char last, int random_seed) : m_AlphabetLength{0}
{
	generateSettings(first, last);
}

Enigma::Enigma(const int ascii_start, const int ascii_end, int random_seed) : Enigma(char(ascii_start), char(ascii_end), random_seed)
{}


Enigma::~Enigma()
{}

void Enigma::generateSettings(const char start, const char end)
{
	//Reserve space in memory for rotors
	right_rotor.reserve(end-start);
	middle_rotor.reserve(end - start);
	left_rotor.reserve(end - start);
	for (char c = start; c <= end; c++)
	{
		m_Alphabet.emplace(c, m_AlphabetLength);
		right_rotor.push_back(std::make_pair(c, m_AlphabetLength));
		middle_rotor.push_back(std::make_pair(c, m_AlphabetLength));
		left_rotor.push_back(std::make_pair(c, m_AlphabetLength));
		m_AlphabetLength++;
	}

	auto rng = std::default_random_engine(m_random_seed);
	std::vector<int> randomizer(m_AlphabetLength);
	std::iota(std::begin(randomizer), std::end(randomizer), 0); // Fill with 0, 1, ..., m_AlphabetLength-1.
	std::shuffle(std::begin(randomizer), std::end(randomizer), rng);
	scrambleRotor(right_rotor, randomizer);
	std::shuffle(std::begin(randomizer), std::end(randomizer), rng);
	scrambleRotor(middle_rotor, randomizer);
	std::shuffle(std::begin(randomizer), std::end(randomizer), rng);
	scrambleRotor(left_rotor, randomizer);
}

void Enigma::scrambleRotor(std::vector<std::pair<char, int>>& rotor, const std::vector<int> &scrambler)
{
	for (size_t i = 0; i < rotor.size(); i++)
	{
		rotor[i].second = scrambler[i];
	}
}

void Enigma::rotorToString(const std::vector<std::pair<char, int>>& v, std::string &out) const
{
	for (size_t i = 0; i < v.size(); i++)
	{
		out += v[i].first;
		out += "[" + std::to_string(v[i].second) + "],";
	}
	out.pop_back();
	out += "\n";
}


std::string Enigma::ToStringAlphabet() const
{
	std::string out;
	for (auto itr = m_Alphabet.begin(); itr != m_Alphabet.end(); itr++)
	{
		out += itr->first;
		out += "[" + std::to_string(itr->second) + "],";
	}
	out.pop_back();
	return out;
}

std::string Enigma::ToStringRotor() const
{
	std::string out = "Right rotor: ";
	rotorToString(right_rotor, out);
	out += "Middle rotor: ";
	rotorToString(middle_rotor, out);
	out += "Left rotor: ";
	rotorToString(left_rotor, out);
	return out;
}
