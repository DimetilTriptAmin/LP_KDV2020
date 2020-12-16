#pragma once
#include <fstream>
using namespace System::Runtime::InteropServices;

namespace KDVTextEdit {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Params
	/// </summary>
	public ref class Params : public System::Windows::Forms::Form
	{
	public:
		Params()
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Params()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;


	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::RichTextBox^ richTextBox2;
	private: System::Windows::Forms::RichTextBox^ richTextBox3;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox3 = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(390, 30);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(104, 20);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Выбраць файл";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Params::button1_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(3, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(47, 29);
			this->label1->TabIndex = 1;
			this->label1->Text = L"-in:";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(3, 65);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(51, 29);
			this->label2->TabIndex = 3;
			this->label2->Text = L"-out:";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(3, 104);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(51, 29);
			this->label3->TabIndex = 4;
			this->label3->Text = L"-log:";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(275, 153);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(104, 20);
			this->button2->TabIndex = 7;
			this->button2->Text = L"ОК";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Params::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(393, 153);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(104, 20);
			this->button3->TabIndex = 8;
			this->button3->Text = L"Закрыць";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Params::button3_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(56, 30);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(328, 20);
			this->richTextBox1->TabIndex = 9;
			this->richTextBox1->Text = L"";
			// 
			// richTextBox2
			// 
			this->richTextBox2->Location = System::Drawing::Point(56, 72);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(328, 20);
			this->richTextBox2->TabIndex = 10;
			this->richTextBox2->Text = L"";
			// 
			// richTextBox3
			// 
			this->richTextBox3->Location = System::Drawing::Point(56, 111);
			this->richTextBox3->Name = L"richTextBox3";
			this->richTextBox3->Size = System::Drawing::Size(328, 20);
			this->richTextBox3->TabIndex = 11;
			this->richTextBox3->Text = L"";
			// 
			// Params
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(509, 185);
			this->Controls->Add(this->richTextBox3);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Name = L"Params";
			this->Text = L"Params";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			richTextBox1->AppendText(openFileDialog1->FileName);
		}
	}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	Close();
}

private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	std::ofstream source("рэсурсы/params.txt");
	if (source.is_open()) {
		if (richTextBox1->Text->Length != 0) {
			source << "-in:" << (char*)(void*)Marshal::StringToHGlobalAnsi(richTextBox1->Text);
		}
		if (richTextBox2->Text->Length != 0) {
			source << ' ' << "-out:" << (char*)(void*)Marshal::StringToHGlobalAnsi(richTextBox2->Text);
		}
		if (richTextBox3->Text->Length != 0) {
			source << ' ' << "-log:" << (char*)(void*)Marshal::StringToHGlobalAnsi(richTextBox3->Text);
		}
		source.close();
		Close();
	}
	else MessageBox::Show("Немагчыма адкрыць файл з параметрамі", "KDVTextEdit", MessageBoxButtons::OK);
}
};
}
