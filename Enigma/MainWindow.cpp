#include "MainWindow.h"
#include "Utility.h"
using namespace Utility;

void Enigma::MainWindow::update_rotor_display()
{
	display_key = gcnew String(enigma->GetRotorKey().c_str());
	txt_LR_key->Text = display_key[0].ToString();
	txt_MR_key->Text = display_key[1].ToString();
	txt_RR_key->Text = display_key[2].ToString();
	can_update_key_input = true;
}
System::Void Enigma::MainWindow::on_main_window_Load(System::Object ^ sender, System::EventArgs ^ e)
{
	txt_alphabet->Text = gcnew String(enigma->GetAlphabet().c_str());
	update_rotor_display();
}

System::Void Enigma::MainWindow::btn_encrypt_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	txt_output->Text = gcnew String(enigma->encrypt_message(StringToString(txt_input->Text)).c_str());
	update_rotor_display();
}

System::Void Enigma::MainWindow::on_rotor_value_change_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	can_update_key_input = false;
	//Convert sender object to a button
	Button^ btn = safe_cast<Button^>(sender);
	std::string key = enigma->GetRotorKey();
	if (btn == btn_LR_up)
		key[0]++;
	else if (btn == btn_LR_down)
		key[0]--;
	else if (btn == btn_MR_up)
		key[1]++;
	else if (btn == btn_MR_down)
		key[1]--;
	else if (btn == btn_RR_up)
		key[2]++;
	else
		key[2]--;
	enigma->SetRotorKey(key);
	update_rotor_display();
}

System::Void Enigma::MainWindow::on_key_input(System::Object ^ sender, System::EventArgs ^ e)
{
	if (!can_update_key_input)
		return;
	can_update_key_input = false;
	TextBox^ box = safe_cast<TextBox^>(sender);
	box->Text = box->Text->ToUpper();
	update_enigma_key();
}

void Enigma::MainWindow::update_enigma_key()
{
	System::String^ s;
	s += txt_LR_key->Text;
	s += txt_MR_key->Text;
	s += txt_RR_key->Text;
	display_key = s;
	enigma->SetRotorKey(StringToString(display_key).c_str());
	update_rotor_display();
}
