#include "Enigma.h"
Enigma::Enigma() : Enigma('A', 'Z', 1)
{}

Enigma::Enigma(const char ascii_start, char ascii_end, const int random_seed) : m_alphabet_size{ 0 }
{
	generateSettings(ascii_start, ascii_end);
	m_rotor_key = "aaa";
}

Enigma::Enigma(const int ascii_start, const int ascii_end, const int random_seed) : Enigma(char(ascii_start), char(ascii_end), random_seed)
{}

Enigma::~Enigma()
{}

int Enigma::char_index(char c) const
{
	return (c - m_alphabet[0]);
}

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

char Enigma::encrypt_character(char c) const
{
	int left_rtr_pos = char_index(m_rotor_key[0]);
	int middle_rtr_pos = char_index(m_rotor_key[1]);
	int right_rtr_pos = char_index(m_rotor_key[2]);
	int c_indx = char_index(c);

	//Pass through right rotor
	c_indx = mod_to_alphabet_size(m_right_rotor[right_rtr_pos].second + c_indx);
	//Pass throught middle rotor
	c_indx = mod_to_alphabet_size(m_middle_rotor[middle_rtr_pos].second + c_indx);
	//Pass through left rotor
	c_indx = mod_to_alphabet_size(m_left_rotor[left_rtr_pos].second + c_indx);
	return c_indx;
}

int Enigma::mod_to_alphabet_size(int val) const
{
	return val % m_alphabet_size;
}

void Enigma::updateRotors()
{
	//Increment right rotor
	int rightRotorPos = char_index(m_rotor_key[0]);
	rightRotorPos++;
	if (rightRotorPos >= m_alphabet_size)
	{
		m_rotor_key[0] = m_alphabet[rightRotorPos];
		return;
	}
	else //Increment middle rotor
	{
		m_rotor_key[0] = m_alphabet[mod_to_alphabet_size(rightRotorPos)];
		int middleRotorPos = char_index(m_rotor_key[1]);
		middleRotorPos++;
		if (middleRotorPos >= m_alphabet_size)
		{
			m_rotor_key[1] = m_alphabet[middleRotorPos];
			return;
		}
		else //Increment left rotor
		{
			m_rotor_key[1] = m_alphabet[mod_to_alphabet_size(middleRotorPos)];
			int leftRotorPos = char_index(m_rotor_key[2]);
			leftRotorPos++;

			if (leftRotorPos >= m_alphabet_size)
				m_rotor_key[2] = m_alphabet[leftRotorPos];
			else
				m_rotor_key[2] = m_alphabet[mod_to_alphabet_size(leftRotorPos)];
		}
	}
}

std::string Enigma::encrypt_message(std::string input)
{
	//Get rotor settings from key
	int L = char_index(m_rotor_key[0]);
	int M = char_index(m_rotor_key[1]);
	int R = char_index(m_rotor_key[2]);

	std::string output;

	for (size_t x = 0; x < input.size(); x++)
	{
		//Map current letter to ascii index
		int input_char = char_index(input[x]);

		//increment right rotor once
		R = mod_to_alphabet_size(R + 1);

		int nextIndx = m_right_rotor[input_char].second + R;
		int result = mod_to_alphabet_size(nextIndx);
		char a = m_alphabet[result];

		//First encryption using right rotor ascii index + 1 and current letter ascii index
		//char a = m_right_rotor[mod26(R + input_char)].first;
		////Second encryption using middle rotor + ascii index of a encryption - the position of right rotor
		//char b = m_middle_rotor[mod26(M + char_index(a) - R)].first;
		////Third encryption using left rotor + ascii index of b encryption - the position of middle rotor
		//char c = m_left_rotor[mod26(L + char_index(b) - M)].first;
		output += a;
	}

	//int rIndx = char_index(m_rotor_key[0]);
	//for (size_t i = 0; i < message.size(); i++)
	//{
	//	rIndx++;
	//	if (rIndx >= m_alphabet_size)
	//		rIndx = 0;
	//	int charIndx = char_index(message[i]);
	//	std::cout << "message [" << message[i] << "] has index: "<< charIndx << std::endl;
	//	std::pair<char, int> p = m_right_rotor[charIndx];
	//	std::cout << "pair [" << p.first<<", "<<p.second << "]" << std::endl;
	//	int rightRIndx = p.second + rIndx;
	//	std::cout << "pair index + second = "<< rightRIndx << std::endl;
	//	rightRIndx = modToAlphabetSize(rightRIndx);
	//	std::cout << "modToAlphabetSize pair index + second = " << rightRIndx << std::endl;
	//	char c = m_alphabet[rightRIndx];
	//	std::cout << "encrypted (" << message[i] << ") to " << c << std::endl;
	//	out += c;
	//}
	//for (auto itr = message.begin(); itr != message.end(); itr++)
	//{
	//	out += m_alphabet[encrypt_character(*itr)];
	//	updateRotors();
	//}
	return output;
}

long Enigma::mod26(long a)
{
	int re = (a + m_alphabet_size) % m_alphabet_size;
	//cout << "Mod26 of ("<< a <<"): " << re << endl;
	return re;
}

	std::string Enigma::decrypt_message(std::string message)
{
	return std::string();
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
