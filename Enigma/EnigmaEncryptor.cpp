#include "EnigmaEncryptor.h"

EnigmaEncryptor::EnigmaEncryptor() : m_alphabet("ABCDEFGHIJKLMNOPQRSTUVWXYZ")
{
	m_rotors.push_back("EKMFLGDQVZNTOWYHXUSPAIBRCJ");
	m_rotors.push_back("AJDKSIRUXBLHWTMCQGZNPYFVOE");
	m_rotors.push_back("BDFHJLCPRTXVZNYEIWGAKMUSQO");
	m_rotors.push_back("YRUHQSLDPXNGOKMIEBFZCWVJAT");
	m_alphabet_size = m_alphabet.length();
	m_rotor_key += m_alphabet[0];
	m_rotor_key += m_alphabet[1];
	m_rotor_key += m_alphabet[2];
}

EnigmaEncryptor::~EnigmaEncryptor()
{}

/// <summary>
/// Converts an ASCII character to m_alphabet character
/// </summary>
/// <param name="val">ASCII character value</param>
/// <returns>Signet int representing c designated position in alphabet</returns>
int8_t EnigmaEncryptor::char_index(char c) const
{
	return c - m_alphabet[0];
}

/// <summary>
/// Ensures that a value stays always within alphabet length
/// </summary>
/// <param name="val">ASCII character value</param>
/// <returns>Result a new value within m_alphabet</returns>
uint8_t EnigmaEncryptor::mod_to_alphabet(int val) const
{
	return  (val + m_alphabet_size) % m_alphabet_size;
}

/// <summary>
/// Increment rotors during encryption
/// </summary>
void EnigmaEncryptor::incrementRotors()
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

/// <summary>
/// Scramble the message using enigma algoritmth
/// </summary>
/// <param name="input">Message to scramle</param>
/// <returns>Scrambled message</returns>
std::string EnigmaEncryptor::encrypt_message(std::string input)
{
	std::string output;
	uint8_t left_rotor;
	uint8_t middle_rotor;
	uint8_t right_rotor;
	//Uppercase string
	transform(input.begin(), input.end(), input.begin(), toupper);
	for (size_t i = 0; i < input.length(); i++)
	{
		//Skip all letters that are not present in alphabet
		if (input[i] < m_alphabet[0] || input[i]> m_alphabet[m_alphabet_size - 1])
			continue;
		//Convert ASCII character index to alphabet index
		uint8_t cryptChar = char_index(input[i]);
		//Increment rotors
		incrementRotors();
		//Get rotor values
		left_rotor   =	char_index(m_rotor_key[0]);
		middle_rotor =	char_index(m_rotor_key[1]);
		right_rotor	 =	char_index(m_rotor_key[2]);
		//Right rotor
		cryptChar = m_rotors[2][mod_to_alphabet(right_rotor + cryptChar)];
		//Middle rotor
		cryptChar = m_rotors[1][mod_to_alphabet(middle_rotor + char_index(cryptChar) - right_rotor)];
		//Left rotor
		cryptChar = m_rotors[0][mod_to_alphabet(left_rotor + char_index(cryptChar) - middle_rotor)];
		//Reflector
		cryptChar = m_rotors[3][mod_to_alphabet(char_index(cryptChar) - left_rotor)];
		//Left rotor
		cryptChar = mod_to_alphabet(m_rotors[0].find(m_alphabet[mod_to_alphabet(char_index(cryptChar) + left_rotor)]) - left_rotor);
		//Middle rotor
		cryptChar = mod_to_alphabet(m_rotors[1].find(m_alphabet[mod_to_alphabet(cryptChar + middle_rotor)]) - middle_rotor);
		//Right rotor
		cryptChar = mod_to_alphabet(m_rotors[2].find(m_alphabet[mod_to_alphabet(cryptChar + right_rotor)]) - right_rotor);
		//Final output
		output += m_alphabet[cryptChar];
	}
	return output;
}
