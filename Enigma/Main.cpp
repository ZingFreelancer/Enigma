#include "Enigma.h"
using namespace std;

int main()
{
	Enigma e('a', 'z');
	cout << "Alphabet: " << e.GetAlphabet() << endl;
	cout << "Key: " << e.GetRotorKey() << endl;
	cout << e.ToStringRotor() << endl;

	string message = "hello";
	cout << "--- Encrypt: " << message << " ---" << endl;
	string result = e.encrypt_message(message);
	cout << message << " becomes: " << result << endl;
	
	e.SetRotorKey("aaa");
	cout << "Alphabet: " << e.GetAlphabet() << endl;
	cout << "Key: " << e.GetRotorKey() << endl;
	cout << e.ToStringRotor() << endl;

	cout << "--- Decrypt: " << result << " ---" << endl;
	string decrypt = e.encrypt_message(result);
	cout << result << " becomes: " << decrypt << endl;

	return 0;
}