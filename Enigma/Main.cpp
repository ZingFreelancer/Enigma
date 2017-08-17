#include "MainWindow.h"
#include <iostream>
using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Enigma::MainWindow window;
	Application::Run(%window);
}

//int main()
//{
//	Enigma e;
//	e.SetRotorKey("ABC");
//	string input = ".Encrypted";
//	string out = e.encrypt_message(input);
//	cout << input << " = " << out << endl;
//	e.SetRotorKey("ABC");
//	cout << out << " = " << e.encrypt_message(out) << endl;
//	cout << endl;
//	return 0;
//}