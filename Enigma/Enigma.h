#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <iostream>
#include <numeric>

class Enigma
{
public:
	//Empty/Default constructor 
	Enigma();
	/// <summary>
	/// Maps characters to integer
	/// </summary>
	/// <param name="ascii_start">Start character</param>
	/// <param name="ascii_end">End character</param>
	Enigma(const char ascii_start, const char ascii_end, int random_seed = 1);
	/// <summary>
	/// Maps characters to integer
	/// </summary>
	/// <param name="ascii_start">Start value taken from ascii table.</param>
	/// <param name="ascii_end">End value taken from ascii table.</param>
	Enigma(const int ascii_start, const int ascii_end, int random_seed = 1);
	virtual ~Enigma();
private: //Variables
	std::string m_alphabet;
	std::vector<std::pair<char, int>> m_right_rotor;
	std::vector<std::pair<char, int>> m_middle_rotor;
	std::vector<std::pair<char, int>> m_left_rotor;
	int m_alphabet_size;
	int m_random_seed;

private: //Functions
	/// <summary>
	/// Will generate settings based on constructor input
	/// </summary>
	/// <param name="start">Start character</param>
	/// <param name="end">End character</param>
	void generateSettings(const char start, const char end);
	/// <summary>
	/// Will scramble a rotor second pair according to scrambler vector
	/// </summary>
	/// <param name="&rotor">Rotor containing a pair struct of char and int</param>
	/// <param name="&scrambler">Shufled vector containing numbers from 0 to rotor length - 1</param>
	void scrambleRotor(std::vector<std::pair<char, int>> &rotor, const std::vector<int> &scrambler);
	/// <summary>
	/// Will output rotor pair content in following format first[second]
	/// </summary>
	/// <param name="&rotor">Rotor containing a pair struct of char and int</param>
	/// <param name="&scrambler">Output string</param>
	void rotorToString(const std::vector<std::pair<char, int>> &rotor, std::string &out) const;

public: //Functions
	/// <summary>
	/// Return a reference to available alphabet
	/// </summary>
	/// <returns>String reference containing characters available to enigma machine</returns>
	const std::string& GetAlphabet() const
	{
		return m_alphabet;
	}
	/// <summary>
	/// Return a reference to alphabet size
	/// </summary>
	/// <returns>size_t reference to alphabet</returns>
	const size_t GetAlphabetSize() const
	{
		return m_alphabet.size();
	}
	/// <summary>
	/// Generate a string of all 3 rotors content
	/// </summary>
	/// <returns>String containing Right, Middle and Left rotor content in following format first[second]</returns>
	std::string ToStringRotor() const;
};

