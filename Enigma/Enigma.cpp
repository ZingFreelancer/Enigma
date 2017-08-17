#include "Enigma.h"
Enigma::Enigma()
{
	m_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	m_rotors.push_back("EKMFLGDQVZNTOWYHXUSPAIBRCJ");
	m_rotors.push_back("AJDKSIRUXBLHWTMCQGZNPYFVOE");
	m_rotors.push_back("BDFHJLCPRTXVZNYEIWGAKMUSQO");
	m_rotors.push_back("YRUHQSLDPXNGOKMIEBFZCWVJAT");
	m_alphabet_size = m_alphabet.length();
	m_rotor_key += m_alphabet[0];
	m_rotor_key += m_alphabet[0];
	m_rotor_key += m_alphabet[0];
}

Enigma::~Enigma()
{}

uint8_t Enigma::char_index(char c) const
{
	uint8_t re = c - m_alphabet[0];
	return c - m_alphabet[0];
}

uint8_t Enigma::mod_to_alphabet(int val) const
{
	return  (val + m_alphabet_size) % m_alphabet_size;
}

void Enigma::incrementRotors()
{
	for (int i = m_rotor_key.length() - 1; i > 0; i--)
	{
		m_rotor_key[i]++;
		if (m_rotor_key[i] == m_alphabet[m_alphabet_size - 1])
		{
			m_rotor_key[i] = m_alphabet[0];
		}
		else
			return;
	}
}

std::string Enigma::encrypt_message(std::string input)
{
	std::string output;
	uint8_t left_rotor;
	uint8_t middle_rotor;
	uint8_t right_rotor;

	transform(input.begin(), input.end(), input.begin(), toupper);
	for (size_t i = 0; i < input.length(); i++)
	{
		if (input[i] < m_alphabet[0] || input[i]> m_alphabet[m_alphabet_size - 1])
			continue;
		uint8_t input_char_indx = char_index(input[i]);
		incrementRotors();
		left_rotor =	char_index(m_rotor_key[0]);
		middle_rotor =	char_index(m_rotor_key[1]);
		right_rotor = mod_to_alphabet(char_index(m_rotor_key[2]));

		uint8_t r3 = m_rotors[2][mod_to_alphabet(right_rotor + input_char_indx)];
		uint8_t r2 = m_rotors[1][mod_to_alphabet(middle_rotor + char_index(r3) - right_rotor)];
		uint8_t r1 = m_rotors[0][mod_to_alphabet(left_rotor + char_index(r2) - middle_rotor)];

		uint8_t ref = m_rotors[3][mod_to_alphabet(char_index(r1) - left_rotor)];

		uint8_t rr1 = mod_to_alphabet(m_rotors[0].find(m_alphabet[mod_to_alphabet(char_index(ref) + left_rotor)]) - left_rotor);
		uint8_t rr2 = mod_to_alphabet(m_rotors[1].find(m_alphabet[mod_to_alphabet(rr1 + middle_rotor)]) - middle_rotor);
		uint8_t rr3 = mod_to_alphabet(m_rotors[2].find(m_alphabet[mod_to_alphabet(rr2 + right_rotor)]) - right_rotor);
		output += m_alphabet[rr3];
	}
	return output;
}
