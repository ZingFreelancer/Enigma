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
	Enigma(const char ascii_start, const char ascii_end, const int random_seed = 1);
	/// <summary>
	/// Maps characters to integer
	/// </summary>
	/// <param name="ascii_start">Start value taken from ascii table.</param>
	/// <param name="ascii_end">End value taken from ascii table.</param>
	Enigma(const int ascii_start, const int ascii_end, const int random_seed = 1);
	virtual ~Enigma();
private: //Variables
	int m_random_seed;
	std::string m_alphabet;
	int m_alphabet_size;
	//rotors
	std::string m_rotor_key;
	std::vector<std::pair<char, int>> m_right_rotor;
	std::vector<std::pair<char, int>> m_middle_rotor;
	std::vector<std::pair<char, int>> m_left_rotor;

private: //Functions
	/// <summary>
	/// Will convert given letter to its index value in m_alphabet using letter - m_alphabet[0]
	/// </summary>
	/// <param name="c">Character to be indexed</param>
	/// <returns>Position of character in m_alphabet</returns>
	int char_index(char c) const;
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
	char encrypt_character(char c) const;
	int mod_to_alphabet_size(int val) const;
	void updateRotors();

public: //Functions
	long mod26(long a);
	std::string encrypt_message(std::string message);
	std::string decrypt_message(std::string message);
#pragma region Setters
	void SetRotorKey(const std::string key)
	{
		m_rotor_key = key;
	}
#pragma endregion /Setters

#pragma region Getters
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
	const size_t& GetAlphabetSize() const
	{
		return m_alphabet.size();
	}

	const std::string& GetRotorKey() const
	{
		return m_rotor_key;
	}
#pragma endregion /Getters	
	/// <summary>
	/// Generate a string of all 3 rotors content
	/// </summary>
	/// <returns>String containing Right, Middle and Left rotor content in following format first[second]</returns>
	std::string ToStringRotor() const;
};

