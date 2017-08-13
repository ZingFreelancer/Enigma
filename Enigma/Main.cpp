#include "Enigma.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
	Enigma e('a', 'z');
	std::string s = e.ToStringAlphabet();
	cout << s << endl;
	return 0;
}