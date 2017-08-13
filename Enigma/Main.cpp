#include "Enigma.h"

using namespace std;

void fillOutVector(vector<char> &v)
{
	for (char c = 'a'; c <= 'z'; c++)
		v.push_back(c);
}

void printVector(vector<char> &v)
{
	for (auto itr = v.begin(); itr != v.end(); itr++)
		cout << *itr;
	cout << endl;
}

int main()
{
	Enigma e('a', 'z');
	std::string s = e.ToStringAlphabet();
	cout << "Alphabet: " << s << endl;
	s = e.ToStringRotor();
	cout << s << endl;
	return 0;
}