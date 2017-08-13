#pragma once
#include <algorithm>
#include <random>
#include <map>
#include <vector>
#include <iostream>
#include <string>
#include <numeric>

class Enigma
{
public:
	//Empty/Default constructor 
	Enigma();
	/// <summary>
	/// Maps characters to integer
	/// </summary>
	/// <param name="start">Start character</param>
	/// <param name="end">End character</param>
	Enigma(const char start, const char end, int random_seed = 1);
	/// <summary>
	/// Maps characters to integer
	/// </summary>
	/// <param name="ascii_start">Start value taken from ascii table.</param>
	/// <param name="ascii_end">End value taken from ascii table.</param>
	Enigma(const int ascii_start, const int ascii_end, int random_seed = 1);
	virtual ~Enigma();
private: //Variables
	std::map<char, int> m_Alphabet;
	std::vector<std::pair<char, int>> right_rotor;
	std::vector<std::pair<char, int>> middle_rotor;
	std::vector<std::pair<char, int>> left_rotor;
	int m_AlphabetLength;
	int m_random_seed;

private: //Functions
	Enigma();
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
	/// Generate a string of alphabet map content
	/// </summary>
	/// <returns>Result a string of alphabet content in following format first[second]</returns>
	std::string ToStringAlphabet() const;
	/// <summary>
	/// Generate a string of all 3 rotors content
	/// </summary>
	/// <returns>String containing Right, Middle and Left rotor content in following format first[second]</returns>
	std::string ToStringRotor() const;
};

