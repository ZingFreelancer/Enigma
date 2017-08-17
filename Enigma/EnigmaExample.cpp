#include <iostream>
#include <cstring>
#include <string>
using namespace std;

char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char rotors[3][27] =
{
	"EKMFLGDQVZNTOWYHXUSPAIBRCJ",
	"AJDKSIRUXBLHWTMCQGZNPYFVOE",
	"BDFHJLCPRTXVZNYEIWGAKMUSQO"
};
char reflector[] = "YRUHQSLDPXNGOKMIEBFZCWVJAT";
//Rotor settings
char key[] = "ABC";

//Make sure that our current index is within range of 26
long mod26(long a)
{
	int re = (a + 26) % 26;
	//cout << "Mod26 of ("<< a <<"): " << re << endl;
	return re;
}

//Map letter ascii value to 26 letters alphabet, A(65) becomes 0 and B(66) becomes 1 etc
int letter_index(char l)
{
	int re = l - 'A';
	//cout << "Li of (" << l << "): " << re << endl;
	return re;
}

int indexof(char* arr, int find)
{
	int re = strchr(arr, find) - arr;
	//cout << "Find (" << find << ") in " << *arr << " = " << re << endl;
	return re;
}

string crypt(const char *input)
{
	//Get rotor settings from key
	int L = letter_index(key[0]);
	int M = letter_index(key[1]);
	int R = letter_index(key[2]);

	string output;

	for (unsigned int x = 0; x < strlen(input); x++) 
	{
		//Map current letter to ascii index
		int input_char = letter_index(input[x]);

		//increment right rotor once
		R = mod26(R + 1);

		//First encryption using right rotor ascii index + 1 and current letter ascii index
		char a = rotors[2][mod26(R + input_char)];
		//Second encryption using middle rotor + ascii index of a encryption - the position of right rotor
		char b = rotors[1][mod26(M + letter_index(a) - R)];
		//Third encryption using left rotor + ascii index of b encryption - the position of middle rotor
		char c = rotors[0][mod26(L + letter_index(b) - M)];

		char ref = reflector[mod26(letter_index(c) - L)];

		int d = mod26(indexof(rotors[0], alpha[mod26(letter_index(ref) + L)]) - L);
		int e = mod26(indexof(rotors[1], alpha[mod26(d + M)]) - M);
		char f = alpha[mod26(indexof(rotors[2], alpha[mod26(e + R)]) - R)];

		output += f;
	}

	return output;
}

//int main()
//{
//	string s = "HELLO";
//	string out;
//	out = crypt(s.c_str());
//	cout << s << " becomes " << out << endl;
//	s = crypt(out.c_str());
//	cout << out << " becomes " << s << endl;
//	return 0;
//}