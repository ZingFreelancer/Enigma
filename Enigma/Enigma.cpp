#include "Enigma.h"
Enigma::Enigma() : Enigma('A', 'Z', 1)
{}

Enigma::Enigma(const char ascii_start, char ascii_end, int random_seed) : m_alphabet_size{0}
{
	generateSettings(ascii_start, ascii_end);
}

Enigma::Enigma(const int ascii_start, const int ascii_end, int random_seed) : Enigma(char(ascii_start), char(ascii_end), random_seed)
{}


Enigma::~Enigma()
{}

void Enigma::generateSettings(const char start, const char end)
{
	//Reserve space in memory for rotors
	int8_t length = end - start;
	m_alphabet.reserve(length);
	m_right_rotor.reserve(length);
	m_middle_rotor.reserve(length);
	m_left_rotor.reserve(length);
	for (char c = start; c <= end; c++)
	{
		m_alphabet += c;
		m_right_rotor.push_back(std::make_pair(c, m_alphabet_size));
		m_middle_rotor.push_back(std::make_pair(c, m_alphabet_size));
		m_left_rotor.push_back(std::make_pair(c, m_alphabet_size));
		m_alphabet_size++;
	}

	auto rng = std::default_random_engine(m_random_seed);
	std::vector<int> randomizer(m_alphabet_size);
	std::iota(std::begin(randomizer), std::end(randomizer), 0); // Fill with 0, 1, ..., m_AlphabetLength-1.
	std::shuffle(std::begin(randomizer), std::end(randomizer), rng);
	scrambleRotor(m_right_rotor, randomizer);
	std::shuffle(std::begin(randomizer), std::end(randomizer), rng);
	scrambleRotor(m_middle_rotor, randomizer);
	std::shuffle(std::begin(randomizer), std::end(randomizer), rng);
	scrambleRotor(m_left_rotor, randomizer);
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

std::string Enigma::ToStringRotor() const
{
	std::string out = "Right rotor: ";
	rotorToString(m_right_rotor, out);
	out += "Middle rotor: ";
	rotorToString(m_middle_rotor, out);
	out += "Left rotor: ";
	rotorToString(m_left_rotor, out);
	return out;
}
