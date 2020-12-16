#pragma once
#include <stdlib.h>
#include <string>
#include <fstream>
#include "Params.h"

namespace KDVTextEdit {

#define defaultFileName "in.txt"

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ ôàéëToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ çàõàâàöüToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ àäêğûöüToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ñêàìï³ë³ğàâàöüToolStripMenuItem;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::ToolStripMenuItem^ çàäàöüÏàğàìåòğûToolStripMenuItem;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::ToolStripMenuItem^ çàäàöüToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ àäêğûöüToolStripMenuItem1;


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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->ôàéëToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->çàõàâàöüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->àäêğûöüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ñêàìï³ë³ğàâàöüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->çàäàöüÏàğàìåòğûToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->çàäàöüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->àäêğûöüToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->ôàéëToolStripMenuItem,
					this->ñêàìï³ë³ğàâàöüToolStripMenuItem, this->çàäàöüÏàğàìåòğûToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(583, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ôàéëToolStripMenuItem
			// 
			this->ôàéëToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->çàõàâàöüToolStripMenuItem,
					this->àäêğûöüToolStripMenuItem
			});
			this->ôàéëToolStripMenuItem->Name = L"ôàéëToolStripMenuItem";
			this->ôàéëToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->ôàéëToolStripMenuItem->Text = L"Ôàéë";
			// 
			// çàõàâàöüToolStripMenuItem
			// 
			this->çàõàâàöüToolStripMenuItem->Name = L"çàõàâàöüToolStripMenuItem";
			this->çàõàâàöüToolStripMenuItem->Size = System::Drawing::Size(124, 22);
			this->çàõàâàöüToolStripMenuItem->Text = L"Çàõàâàöü";
			this->çàõàâàöüToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::çàõàâàöüToolStripMenuItem_Click);
			// 
			// àäêğûöüToolStripMenuItem
			// 
			this->àäêğûöüToolStripMenuItem->Name = L"àäêğûöüToolStripMenuItem";
			this->àäêğûöüToolStripMenuItem->Size = System::Drawing::Size(124, 22);
			this->àäêğûöüToolStripMenuItem->Text = L"Àäêğûöü";
			this->àäêğûöüToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::àäêğûöüToolStripMenuItem_Click);
			// 
			// ñêàìï³ë³ğàâàöüToolStripMenuItem
			// 
			this->ñêàìï³ë³ğàâàöüToolStripMenuItem->Name = L"ñêàìï³ë³ğàâàöüToolStripMenuItem";
			this->ñêàìï³ë³ğàâàöüToolStripMenuItem->Size = System::Drawing::Size(96, 20);
			this->ñêàìï³ë³ğàâàöüToolStripMenuItem->Text = L"Ñêàìï³ëÿâàöü";
			this->ñêàìï³ë³ğàâàöüToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ñêàìï³ë³ğàâàöüToolStripMenuItem_Click);
			// 
			// çàäàöüÏàğàìåòğûToolStripMenuItem
			// 
			this->çàäàöüÏàğàìåòğûToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->çàäàöüToolStripMenuItem,
					this->àäêğûöüToolStripMenuItem1
			});
			this->çàäàöüÏàğàìåòğûToolStripMenuItem->Name = L"çàäàöüÏàğàìåòğûToolStripMenuItem";
			this->çàäàöüÏàğàìåòğûToolStripMenuItem->Size = System::Drawing::Size(83, 20);
			this->çàäàöüÏàğàìåòğûToolStripMenuItem->Text = L"Óëàñö³âàñö³";
			this->çàäàöüÏàğàìåòğûToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::çàäàöüÏàğàìåòğûToolStripMenuItem_Click);
			// 
			// çàäàöüToolStripMenuItem
			// 
			this->çàäàöüToolStripMenuItem->Name = L"çàäàöüToolStripMenuItem";
			this->çàäàöüToolStripMenuItem->Size = System::Drawing::Size(123, 22);
			this->çàäàöüToolStripMenuItem->Text = L"Çàäàöü";
			this->çàäàöüToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::çàäàöüToolStripMenuItem_Click);
			// 
			// àäêğûöüToolStripMenuItem1
			// 
			this->àäêğûöüToolStripMenuItem1->Name = L"àäêğûöüToolStripMenuItem1";
			this->àäêğûöüToolStripMenuItem1->Size = System::Drawing::Size(123, 22);
			this->àäêğûöüToolStripMenuItem1->Text = L"Àäêğûöü";
			this->àäêğûöüToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::àäêğûöüToolStripMenuItem1_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->richTextBox1->Location = System::Drawing::Point(0, 24);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(583, 470);
			this->richTextBox1->TabIndex = 1;
			this->richTextBox1->Text = L"";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::richTextBox1_TextChanged);
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->Filter = L"Òıêñòàâûÿ ôàéëû|.txt";
			this->saveFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::saveFileDialog1_FileOk);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->Filter = L"Òıêñòàâûÿ ôàéëû|*.txt";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::WindowFrame;
			this->ClientSize = System::Drawing::Size(583, 494);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"KDVTextEdit";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
private: System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}

	   bool exists(char* name) {
		   std::ifstream f(name);
		   return f.good();
	   }

private: System::Void ñêàìï³ë³ğàâàöüToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	char params[255]="";
	char* pch;
	char in[255];
	char buff[255];
	char cl[] = "ğıñóğñû\\LP_CourseProject.exe ";
	std::ifstream source("ğıñóğñû/params.txt");
	if (source.is_open()) {
		source.getline(buff, 254);
		strcpy_s(in,buff);
		pch = strtok(in, " ");
		if (exists(&pch[4])) {
			strcpy_s(params, 254, buff);
			system(strcat(cl, params));
			source.close();
		}
		else MessageBox::Show("Íåìàã÷ûìà àäêğûöü ôàéë ç çûõîäíûì êîäàì", "KDVTextEdit", MessageBoxButtons::OK);
	}
	else MessageBox::Show("Íåìàã÷ûìà àäêğûöü ôàéë ç ïàğàìåòğàì³", "KDVTextEdit", MessageBoxButtons::OK);
}
private: System::Void çàõàâàöüToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	System::Windows::Forms::DialogResult res;
	res = MessageBox::Show("Çàõàâàöü çìåíû ¢ ôàéëå?", "KDVTextEdit", MessageBoxButtons::YesNoCancel);
	switch (res)
	{
	case System::Windows::Forms::DialogResult::None:
		break;
	case System::Windows::Forms::DialogResult::Cancel:
		break;
	case System::Windows::Forms::DialogResult::Ignore:
		break;
	case System::Windows::Forms::DialogResult::Yes:
		if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				richTextBox1->SaveFile(saveFileDialog1->FileName, RichTextBoxStreamType::PlainText);
		}
		break;
	case System::Windows::Forms::DialogResult::No:
		richTextBox1->Clear();
		break;
	default:
		break;
	}
}
private: System::Void saveFileDialog1_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
}

public: System::Void read(System::String^ str) {
		   richTextBox1->LoadFile(str, RichTextBoxStreamType::PlainText);
}

private: System::Void àäêğûöüToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		richTextBox1->LoadFile(openFileDialog1->FileName, RichTextBoxStreamType::PlainText);
	}
}
private: System::Void çàäàöüÏàğàìåòğûToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void çàäàöüToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	KDVTextEdit::Params parms;
	parms.ShowDialog();
}
private: System::Void àäêğûöüToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
	std::ifstream source("ğıñóğñû\\params.txt");
	if (source.is_open()) {
		system("ğıñóğñû\\params.txt");
		source.close();
	}
	else MessageBox::Show("Íåìàã÷ûìà àäêğûöü ôàéë ç ïàğàìåòğàì³", "KDVTextEdit", MessageBoxButtons::OK);
}
};
}
