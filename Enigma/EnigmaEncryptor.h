#pragma once
#include <vector>
#include <string>
#include <algorithm>

class EnigmaEncryptor
{
public:
	//Empty/Default constructor 
	EnigmaEncryptor();
	virtual ~EnigmaEncryptor();
private: 
	//Variables
	int m_random_seed;
	std::string m_alphabet;
	int m_alphabet_size;
	//rotors
	std::string m_rotor_key;
	std::vector<std::string> m_rotors;

private: //Functions
	int8_t char_index(char c) const;
	uint8_t mod_to_alphabet(int val) const;
	void incrementRotors();

public: //Functions
	std::string encrypt_message(std::string message);

#pragma region Setters and Getters
	void SetRotorKey(const std::string key)
	{
		m_rotor_key = key;
		for (size_t i = 0; i < key.length(); i++)
			m_rotor_key[i] = m_alphabet[mod_to_alphabet(char_index(key[i]))];

	}

	const std::string& GetAlphabet() const
	{
		return m_alphabet;
	}
	const size_t& GetAlphabetSize() const
	{
		return m_alphabet.size();
	}

	const std::string GetRotorKey() const
	{
		return m_rotor_key;
	}
#pragma endregion /setters and getters	
};

