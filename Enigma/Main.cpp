#include "Enigma.h"
#include <iostream>
using namespace std;



int main()
{
	Enigma e;
	e.SetRotorKey("ABC");
	string input = ".Encrypted";
	string out = e.encrypt_message(input);
	cout << input << " = " << out << endl;
	e.SetRotorKey("ABC");
	cout << out << " = " << e.encrypt_message(out) << endl;
	cout << endl;
	return 0;
}