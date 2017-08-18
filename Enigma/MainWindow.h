#pragma once
#include "EnigmaEncryptor.h"

namespace Enigma {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainWindow
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		MainWindow(void) : enigma{new EnigmaEncryptor()}, can_update_key_input{false}
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainWindow()
		{
			if (components)
			{
				delete components;
			}
			delete enigma;
		}
	private: System::Windows::Forms::Label^  lbl_alphabet;
	private: System::Windows::Forms::TextBox^  txt_alphabet;
	private: System::Windows::Forms::TextBox^  txt_LR_key;
	private: System::Windows::Forms::Button^  btn_LR_up;
	private: System::Windows::Forms::Button^  btn_LR_down;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel4;
	private: System::Windows::Forms::Button^  btn_MR_up;
	private: System::Windows::Forms::TextBox^  txt_MR_key;
	private: System::Windows::Forms::Button^  btn_MR_down;
	private: System::Windows::Forms::Button^  btn_RR_up;
	private: System::Windows::Forms::TextBox^  txt_RR_key;
	private: System::Windows::Forms::Button^  btn_RR_down;
	private: System::Windows::Forms::Label^  lbl_rotor_key;
	private: System::Windows::Forms::TextBox^  txt_input;
	private: System::Windows::Forms::TextBox^  txt_output;
	private: System::Windows::Forms::Label^  lbl_input_text;
	private: System::Windows::Forms::Label^  lbl_output_text;
	private: System::Windows::Forms::Button^  btn_encrypt;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		EnigmaEncryptor *enigma;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->lbl_alphabet = (gcnew System::Windows::Forms::Label());
			this->txt_alphabet = (gcnew System::Windows::Forms::TextBox());
			this->txt_LR_key = (gcnew System::Windows::Forms::TextBox());
			this->btn_LR_up = (gcnew System::Windows::Forms::Button());
			this->btn_LR_down = (gcnew System::Windows::Forms::Button());
			this->flowLayoutPanel4 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->btn_MR_up = (gcnew System::Windows::Forms::Button());
			this->txt_MR_key = (gcnew System::Windows::Forms::TextBox());
			this->btn_MR_down = (gcnew System::Windows::Forms::Button());
			this->btn_RR_up = (gcnew System::Windows::Forms::Button());
			this->txt_RR_key = (gcnew System::Windows::Forms::TextBox());
			this->btn_RR_down = (gcnew System::Windows::Forms::Button());
			this->lbl_rotor_key = (gcnew System::Windows::Forms::Label());
			this->txt_input = (gcnew System::Windows::Forms::TextBox());
			this->txt_output = (gcnew System::Windows::Forms::TextBox());
			this->lbl_input_text = (gcnew System::Windows::Forms::Label());
			this->lbl_output_text = (gcnew System::Windows::Forms::Label());
			this->btn_encrypt = (gcnew System::Windows::Forms::Button());
			this->flowLayoutPanel4->SuspendLayout();
			this->SuspendLayout();
			// 
			// lbl_alphabet
			// 
			this->lbl_alphabet->AutoSize = true;
			this->lbl_alphabet->Location = System::Drawing::Point(12, 9);
			this->lbl_alphabet->Name = L"lbl_alphabet";
			this->lbl_alphabet->Size = System::Drawing::Size(125, 13);
			this->lbl_alphabet->TabIndex = 0;
			this->lbl_alphabet->Text = L"Recognizable characters";
			// 
			// txt_alphabet
			// 
			this->txt_alphabet->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_alphabet->Location = System::Drawing::Point(15, 25);
			this->txt_alphabet->Name = L"txt_alphabet";
			this->txt_alphabet->ReadOnly = true;
			this->txt_alphabet->Size = System::Drawing::Size(400, 22);
			this->txt_alphabet->TabIndex = 1;
			this->txt_alphabet->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// txt_LR_key
			// 
			this->txt_LR_key->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_LR_key->Location = System::Drawing::Point(3, 35);
			this->txt_LR_key->Name = L"txt_LR_key";
			this->txt_LR_key->Size = System::Drawing::Size(30, 26);
			this->txt_LR_key->TabIndex = 2;
			this->txt_LR_key->Text = L"A";
			this->txt_LR_key->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->txt_LR_key->TextChanged += gcnew System::EventHandler(this, &MainWindow::on_key_input);
			// 
			// btn_LR_up
			// 
			this->btn_LR_up->Font = (gcnew System::Drawing::Font(L"Wingdings", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(2)));
			this->btn_LR_up->Location = System::Drawing::Point(3, 3);
			this->btn_LR_up->Name = L"btn_LR_up";
			this->btn_LR_up->Size = System::Drawing::Size(30, 26);
			this->btn_LR_up->TabIndex = 3;
			this->btn_LR_up->Text = L"";
			this->btn_LR_up->UseVisualStyleBackColor = true;
			this->btn_LR_up->Click += gcnew System::EventHandler(this, &MainWindow::on_rotor_value_change_Click);
			// 
			// btn_LR_down
			// 
			this->btn_LR_down->Font = (gcnew System::Drawing::Font(L"Wingdings", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(2)));
			this->btn_LR_down->Location = System::Drawing::Point(3, 67);
			this->btn_LR_down->Name = L"btn_LR_down";
			this->btn_LR_down->Size = System::Drawing::Size(30, 26);
			this->btn_LR_down->TabIndex = 3;
			this->btn_LR_down->Text = L"";
			this->btn_LR_down->UseVisualStyleBackColor = true;
			this->btn_LR_down->Click += gcnew System::EventHandler(this, &MainWindow::on_rotor_value_change_Click);
			// 
			// flowLayoutPanel4
			// 
			this->flowLayoutPanel4->Controls->Add(this->btn_LR_up);
			this->flowLayoutPanel4->Controls->Add(this->txt_LR_key);
			this->flowLayoutPanel4->Controls->Add(this->btn_LR_down);
			this->flowLayoutPanel4->Controls->Add(this->btn_MR_up);
			this->flowLayoutPanel4->Controls->Add(this->txt_MR_key);
			this->flowLayoutPanel4->Controls->Add(this->btn_MR_down);
			this->flowLayoutPanel4->Controls->Add(this->btn_RR_up);
			this->flowLayoutPanel4->Controls->Add(this->txt_RR_key);
			this->flowLayoutPanel4->Controls->Add(this->btn_RR_down);
			this->flowLayoutPanel4->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->flowLayoutPanel4->Location = System::Drawing::Point(153, 53);
			this->flowLayoutPanel4->Name = L"flowLayoutPanel4";
			this->flowLayoutPanel4->Size = System::Drawing::Size(109, 97);
			this->flowLayoutPanel4->TabIndex = 5;
			// 
			// btn_MR_up
			// 
			this->btn_MR_up->Font = (gcnew System::Drawing::Font(L"Wingdings", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(2)));
			this->btn_MR_up->Location = System::Drawing::Point(39, 3);
			this->btn_MR_up->Name = L"btn_MR_up";
			this->btn_MR_up->Size = System::Drawing::Size(30, 26);
			this->btn_MR_up->TabIndex = 3;
			this->btn_MR_up->Text = L"";
			this->btn_MR_up->UseVisualStyleBackColor = true;
			this->btn_MR_up->Click += gcnew System::EventHandler(this, &MainWindow::on_rotor_value_change_Click);
			// 
			// txt_MR_key
			// 
			this->txt_MR_key->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_MR_key->Location = System::Drawing::Point(39, 35);
			this->txt_MR_key->Name = L"txt_MR_key";
			this->txt_MR_key->Size = System::Drawing::Size(30, 26);
			this->txt_MR_key->TabIndex = 2;
			this->txt_MR_key->Text = L"A";
			this->txt_MR_key->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->txt_MR_key->TextChanged += gcnew System::EventHandler(this, &MainWindow::on_key_input);
			// 
			// btn_MR_down
			// 
			this->btn_MR_down->Font = (gcnew System::Drawing::Font(L"Wingdings", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(2)));
			this->btn_MR_down->Location = System::Drawing::Point(39, 67);
			this->btn_MR_down->Name = L"btn_MR_down";
			this->btn_MR_down->Size = System::Drawing::Size(30, 26);
			this->btn_MR_down->TabIndex = 3;
			this->btn_MR_down->Text = L"";
			this->btn_MR_down->UseVisualStyleBackColor = true;
			this->btn_MR_down->Click += gcnew System::EventHandler(this, &MainWindow::on_rotor_value_change_Click);
			// 
			// btn_RR_up
			// 
			this->btn_RR_up->Font = (gcnew System::Drawing::Font(L"Wingdings", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(2)));
			this->btn_RR_up->Location = System::Drawing::Point(75, 3);
			this->btn_RR_up->Name = L"btn_RR_up";
			this->btn_RR_up->Size = System::Drawing::Size(30, 26);
			this->btn_RR_up->TabIndex = 3;
			this->btn_RR_up->Text = L"";
			this->btn_RR_up->UseVisualStyleBackColor = true;
			this->btn_RR_up->Click += gcnew System::EventHandler(this, &MainWindow::on_rotor_value_change_Click);
			// 
			// txt_RR_key
			// 
			this->txt_RR_key->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_RR_key->Location = System::Drawing::Point(75, 35);
			this->txt_RR_key->Name = L"txt_RR_key";
			this->txt_RR_key->Size = System::Drawing::Size(30, 26);
			this->txt_RR_key->TabIndex = 2;
			this->txt_RR_key->Text = L"A";
			this->txt_RR_key->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->txt_RR_key->TextChanged += gcnew System::EventHandler(this, &MainWindow::on_key_input);
			// 
			// btn_RR_down
			// 
			this->btn_RR_down->Font = (gcnew System::Drawing::Font(L"Wingdings", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(2)));
			this->btn_RR_down->Location = System::Drawing::Point(75, 67);
			this->btn_RR_down->Name = L"btn_RR_down";
			this->btn_RR_down->Size = System::Drawing::Size(30, 26);
			this->btn_RR_down->TabIndex = 3;
			this->btn_RR_down->Text = L"";
			this->btn_RR_down->UseVisualStyleBackColor = true;
			this->btn_RR_down->Click += gcnew System::EventHandler(this, &MainWindow::on_rotor_value_change_Click);
			// 
			// lbl_rotor_key
			// 
			this->lbl_rotor_key->AutoSize = true;
			this->lbl_rotor_key->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_rotor_key->Location = System::Drawing::Point(100, 90);
			this->lbl_rotor_key->Name = L"lbl_rotor_key";
			this->lbl_rotor_key->Size = System::Drawing::Size(47, 24);
			this->lbl_rotor_key->TabIndex = 6;
			this->lbl_rotor_key->Text = L"Key:";
			// 
			// txt_input
			// 
			this->txt_input->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_input->Location = System::Drawing::Point(15, 186);
			this->txt_input->Multiline = true;
			this->txt_input->Name = L"txt_input";
			this->txt_input->Size = System::Drawing::Size(400, 99);
			this->txt_input->TabIndex = 7;
			// 
			// txt_output
			// 
			this->txt_output->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_output->Location = System::Drawing::Point(15, 343);
			this->txt_output->Multiline = true;
			this->txt_output->Name = L"txt_output";
			this->txt_output->ReadOnly = true;
			this->txt_output->Size = System::Drawing::Size(400, 99);
			this->txt_output->TabIndex = 7;
			// 
			// lbl_input_text
			// 
			this->lbl_input_text->AutoSize = true;
			this->lbl_input_text->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_input_text->Location = System::Drawing::Point(12, 163);
			this->lbl_input_text->Name = L"lbl_input_text";
			this->lbl_input_text->Size = System::Drawing::Size(76, 20);
			this->lbl_input_text->TabIndex = 8;
			this->lbl_input_text->Text = L"Input text";
			// 
			// lbl_output_text
			// 
			this->lbl_output_text->AutoSize = true;
			this->lbl_output_text->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_output_text->Location = System::Drawing::Point(12, 320);
			this->lbl_output_text->Name = L"lbl_output_text";
			this->lbl_output_text->Size = System::Drawing::Size(88, 20);
			this->lbl_output_text->TabIndex = 9;
			this->lbl_output_text->Text = L"Output text";
			// 
			// btn_encrypt
			// 
			this->btn_encrypt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_encrypt->Location = System::Drawing::Point(335, 291);
			this->btn_encrypt->Name = L"btn_encrypt";
			this->btn_encrypt->Size = System::Drawing::Size(80, 30);
			this->btn_encrypt->TabIndex = 10;
			this->btn_encrypt->Text = L"Convert";
			this->btn_encrypt->UseVisualStyleBackColor = true;
			this->btn_encrypt->Click += gcnew System::EventHandler(this, &MainWindow::btn_encrypt_Click);
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(427, 454);
			this->Controls->Add(this->btn_encrypt);
			this->Controls->Add(this->lbl_output_text);
			this->Controls->Add(this->lbl_input_text);
			this->Controls->Add(this->txt_output);
			this->Controls->Add(this->txt_input);
			this->Controls->Add(this->lbl_rotor_key);
			this->Controls->Add(this->flowLayoutPanel4);
			this->Controls->Add(this->txt_alphabet);
			this->Controls->Add(this->lbl_alphabet);
			this->Name = L"MainWindow";
			this->Text = L"MainWindow";
			this->Load += gcnew System::EventHandler(this, &MainWindow::on_main_window_Load);
			this->flowLayoutPanel4->ResumeLayout(false);
			this->flowLayoutPanel4->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	//variables
	private:
		bool can_update_key_input;
		System::String^ display_key;
	private: 
		void update_rotor_display();
		System::Void on_main_window_Load(System::Object^  sender, System::EventArgs^  e);
		System::Void btn_encrypt_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void on_rotor_value_change_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void on_key_input(System::Object^  sender, System::EventArgs^  e);
		void update_enigma_key();
};
}
